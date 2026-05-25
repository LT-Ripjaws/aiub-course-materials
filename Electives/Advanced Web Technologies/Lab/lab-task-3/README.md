# Lab Task 3 - University System API (Dependency Injection Patterns)

## Overview
This lab demonstrates **three types of Dependency Injection** in NestJS:
1. **Intra-Module DI** - Within the same module
2. **Inter-Module DI** - Across different modules
3. **Circular DI** - Two services depending on each other (using `forwardRef()`)

---

## Project Structure
```
UniversitySystemAPI/
├── src/
│   ├── course/           # Part A: Intra-Module DI
│   │   ├── course.module.ts
│   │   ├── course.controller.ts
│   │   └── course.service.ts
│   ├── enrollment/       # Part B + C: Inter-Module + Circular
│   │   ├── enrollment.module.ts
│   │   ├── enrollment.controller.ts
│   │   └── enrollment.service.ts
│   ├── notification/     # Part C: Circular DI
│   │   ├── notification.module.ts
│   │   ├── notification.controller.ts
│   │   └── notification.service.ts
│   ├── app.module.ts     # Root module
│   └── main.ts
```

---

## Part A: Intra-Module Dependency Injection

### What is it?
A controller or service depends on another service **inside the same module**.

### Module: `CourseModule`

```
┌─────────────────────────────────────┐
│         CourseModule                │
│  ┌─────────────┐    ┌─────────────┐ │
│  │  Controller │ →  │   Service   │ │
│  │             │    │             │ │
│  └─────────────┘    └─────────────┘ │
└─────────────────────────────────────┘
```

### Implementation

**course.service.ts**
```typescript
@Injectable()
export class CourseService {
  getAllCourses() {
    return { message: 'All courses fetched', data: [] };
  }

  getCourseById(id: string) {
    return { message: 'Course fetched', id };
  }

  createCourse(name: string, code: string) {
    return { message: 'Course created', data: { name, code } };
  }
}
```

**course.controller.ts**
```typescript
@Controller('course')
export class CourseController {
  constructor(private readonly courseService: CourseService) {}
  // ↑ NestJS automatically injects CourseService

  @Get()
  getAll() {
    return this.courseService.getAllCourses();
  }

  @Get(':id')
  getById(@Param('id') id: string) {
    return this.courseService.getCourseById(id);
  }

  @Post()
  create(@Body() body: { name: string; code: string }) {
    return this.courseService.createCourse(body.name, body.code);
  }
}
```

**course.module.ts**
```typescript
@Module({
  controllers: [CourseController],
  providers: [CourseService],  // Registered here
  // No exports needed - service stays private
})
export class CourseModule {}
```

### How It Works

1. `@Injectable()` marks `CourseService` as a provider
2. Listed in `providers[]` — NestJS creates and manages the instance
3. Controller declares it in constructor — NestJS automatically injects it
4. No `exports[]` needed — service is private to this module

### Routes

| Method | Route | Response |
|--------|-------|----------|
| `GET` | `/course` | `{ message: 'All courses fetched', data: [] }` |
| `GET` | `/course/:id` | `{ message: 'Course fetched', id: '101' }` |
| `POST` | `/course` | `{ message: 'Course created', data: {...} }` |

---

## Part B: Inter-Module Dependency Injection

### What is it?
A service in one module depends on a service from a **different module**.

### Architecture

```
┌──────────────────────┐         ┌──────────────────────┐
│   EnrollmentModule   │         │     CourseModule     │
│  ┌─────────────────┐ │         │  ┌─────────────────┐ │
│  │ EnrollmentSvc   │ ────────→ │ │   CourseSvc     │ │
│  │                 │ │ imports │ │                 │ │
│  └─────────────────┘ │         │ └─────────────────┘ │
│                      │         │      exports: []    │
└──────────────────────┘         └──────────────────────┘
```

### Implementation

**course.module.ts** (Updated to export)
```typescript
@Module({
  providers: [CourseService],
  exports: [CourseService],  // ← Makes it public for other modules
})
export class CourseModule {}
```

**enrollment.service.ts**
```typescript
@Injectable()
export class EnrollmentService {
  constructor(private readonly courseService: CourseService) {}
  // ↑ Injected from CourseModule

  getEnrollments() {
    return { message: 'All enrollments fetched', data: [] };
  }

  enrollStudent(studentName: string, courseId: string) {
    const course = this.courseService.getCourseById(courseId);  // Uses external service
    return {
      message: 'Student enrolled successfully',
      student: studentName,
      course,  // Includes data from CourseService
    };
  }
}
```

**enrollment.module.ts**
```typescript
@Module({
  imports: [CourseModule],  // ← Import the MODULE (not the service)
  controllers: [EnrollmentController],
  providers: [EnrollmentService],
  exports: [EnrollmentService],
})
export class EnrollmentModule {}
```

### How It Works

1. `CourseModule` **exports** `CourseService` — makes it public
2. `EnrollmentModule` **imports** `CourseModule` — gains access to exported providers
3. NestJS resolves the dependency across module boundaries
4. `EnrollmentService` can now use `CourseService` methods

### Key Rule
> **Import the module, not the service directly.** This maintains modularity.

### Routes

| Method | Route | Response |
|--------|-------|----------|
| `GET` | `/enrollment` | `{ message: 'All enrollments fetched', data: [] }` |
| `POST` | `/enrollment` | `{ message: 'Student enrolled', student: 'John', course: {...} }` |

---

## Part C: Circular Dependency Injection

### What is it?
Two services depend on **each other** — creating a circular reference.

```
┌──────────────────────┐         ┌──────────────────────┐
│   EnrollmentModule   │         │   NotificationModule │
│  ┌─────────────────┐ │         │  ┌─────────────────┐ │
│  │ EnrollmentSvc   │ ←───────→ │ │ NotificationSvc │ │
│  │                 │ │         │ │                 │ │
│  └─────────────────┘ │         │ └─────────────────┘ │
└──────────────────────┘         └──────────────────────┘
```

### The Problem

Without `forwardRef()`, NestJS throws:
```
Error: Circular dependency detected
```

Because:
- `EnrollmentService` waits for `NotificationService` to be created
- `NotificationService` waits for `EnrollmentService` to be created
- **Deadlock!** Neither can be created first.

### The Solution: `forwardRef()`

`forwardRef()` wraps the dependency in a function, telling NestJS to resolve it **lazily** (after both classes are defined).

### Implementation

**enrollment.service.ts**
```typescript
@Injectable()
export class EnrollmentService {
  constructor(
    private readonly courseService: CourseService,
    @Inject(forwardRef(() => NotificationService))  // ← Lazy resolution
    private readonly notificationService: NotificationService,
  ) {}

  enrollStudent(studentName: string, courseId: string) {
    const course = this.courseService.getCourseById(courseId);
    // Notify after enrollment
    this.notificationService.sendNotification(studentName, 'Enrollment successful');
    return {
      message: 'Student enrolled successfully',
      student: studentName,
      course,
      notification: 'Confirmation sent',
    };
  }
}
```

**notification.service.ts**
```typescript
@Injectable()
export class NotificationService {
  constructor(
    @Inject(forwardRef(() => EnrollmentService))  // ← Lazy resolution
    private readonly enrollmentService: EnrollmentService,
  ) {}

  sendNotification(studentName: string, message: string) {
    return {
      message: 'Notification sent successfully',
      student: studentName,
      notification: message,
    };
  }

  checkEnrollmentAndNotify(studentName: string, courseId: string) {
    const enrollments = this.enrollmentService.getEnrollments();
    return {
      message: 'Enrollment checked and notification sent',
      student: studentName,
      enrollments,
    };
  }
}
```

**enrollment.module.ts**
```typescript
@Module({
  imports: [
    CourseModule,
    forwardRef(() => NotificationModule),  // ← Also in module imports
  ],
  controllers: [EnrollmentController],
  providers: [EnrollmentService],
  exports: [EnrollmentService],
})
export class EnrollmentModule {}
```

**notification.module.ts**
```typescript
@Module({
  imports: [
    forwardRef(() => EnrollmentModule),  // ← Also in module imports
  ],
  controllers: [NotificationController],
  providers: [NotificationService],
  exports: [NotificationService],
})
export class NotificationModule {}
```

### Why `forwardRef()` on Both Sides?

| Location | Why |
|----------|-----|
| **Constructor** | Service needs lazy injection |
| **Module imports** | Module needs lazy import resolution |

**Both sides need BOTH** — otherwise NestJS still can't resolve the circular reference.

### Routes

| Method | Route | Response |
|--------|-------|----------|
| `POST` | `/notification/send` | `{ message: 'Notification sent', student, notification }` |
| `POST` | `/notification/check` | `{ message: 'Enrollment checked', student, enrollments }` |

---

## Root AppModule

```typescript
@Module({
  imports: [
    CourseModule,
    EnrollmentModule,
    NotificationModule,  // All modules registered here
  ],
})
export class AppModule {}
```

---

## Summary Table

| Part | DI Type | Dependency | Key Mechanism |
|------|---------|------------|---------------|
| **A** | Intra-Module | `CourseController` → `CourseService` | `providers[]` |
| **B** | Inter-Module | `EnrollmentService` → `CourseService` | `exports[]` + `imports[]` |
| **C** | Circular | `EnrollmentService` ↔ `NotificationService` | `forwardRef()` on both sides |

---

## Architecture Rules

1. **`@Injectable()`** — Every service must have this decorator
2. **Constructor injection** — Never use `new Service()` manually
3. **`providers[]`** — Service must be registered to be injectable
4. **`exports[]`** — Service must be exported to be used by other modules
5. **`imports[]`** — Consuming module must import the providing module
6. **`forwardRef()`** — Required on **BOTH** sides of circular dependency:
   - Both constructors (`@Inject(forwardRef(...))`)
   - Both module imports

---

## Testing All Parts

### Part A — Intra-Module

```bash
# Get all courses
curl http://localhost:3000/course

# Get course by ID
curl http://localhost:3000/course/101

# Create course
curl -X POST http://localhost:3000/course \
  -H "Content-Type: application/json" \
  -d '{"name":"NestJS","code":"CS301"}'
```

### Part B — Inter-Module

```bash
# Get enrollments
curl http://localhost:3000/enrollment

# Enroll student (proves inter-module DI works)
curl -X POST http://localhost:3000/enrollment \
  -H "Content-Type: application/json" \
  -d '{"studentName":"John Doe","courseId":"101"}'

# Response includes data from CourseService:
# { "course": { "message": "Course fetched", "id": "101" } }
```

### Part C — Circular Dependency

```bash
# Send notification
curl -X POST http://localhost:3000/notification/send \
  -H "Content-Type: application/json" \
  -d '{"studentName":"John Doe","message":"Welcome!"}'

# Check enrollment and notify
curl -X POST http://localhost:3000/notification/check \
  -H "Content-Type: application/json" \
  -d '{"studentName":"John Doe","courseId":"101"}'

# Enroll (now includes notification confirmation)
curl -X POST http://localhost:3000/enrollment \
  -H "Content-Type: application/json" \
  -d '{"studentName":"Jane Doe","courseId":"101"}'
```

---

## Key Takeaways

### 1. Intra-Module DI
- Most basic form
- Service private to module
- No exports needed

### 2. Inter-Module DI
- Module exports its service
- Other modules import the providing module
- Maintains modularity

### 3. Circular DI
- Use `forwardRef()` to break deadlock
- Required on both sides (constructors + modules)
- Resolves lazily after both classes defined

### 4. NestJS DI Container
- Automatically manages service instances
- Singletons by default (one instance per service)
- Resolves dependencies recursively

---

## What You Learned

✅ Module → Controller → Service architecture
✅ Intra-module dependency injection
✅ Inter-module dependency injection with exports/imports
✅ Circular dependency resolution with `forwardRef()`
✅ Constructor injection pattern
✅ Root module registration
