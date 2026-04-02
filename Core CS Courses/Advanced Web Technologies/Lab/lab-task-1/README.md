# Lab Task 1 - Course Management API (Basic REST)

## Overview
This lab introduces the fundamentals of building a REST API with NestJS. You'll learn the basic Module → Controller → Service architecture and HTTP method mapping.

---

## Project Structure
```
course-management-api/
├── src/
│   ├── course/
│   │   ├── course.module.ts
│   │   ├── course.controller.ts
│   │   └── course.service.ts
│   ├── app.module.ts
│   └── main.ts
```

---

## Core Concepts

### 1. NestJS Architecture Pattern

```
┌─────────────────┐
│   Controller    │  ← Handles HTTP requests/responses
│   (course.controller.ts) │
└────────┬────────┘
         │ uses
         ▼
┌─────────────────┐
│    Service      │  ← Contains business logic
│   (course.service.ts)  │
└─────────────────┘
```

### 2. Module System (`course.module.ts`)

```typescript
@Module({
  controllers: [CourseController],  // Registers controllers
  providers: [CourseService]        // Registers services (DI container)
})
```

**Why?**
- Modules organize related code
- `providers[]` tells NestJS to manage the service instance
- Controllers are auto-wired when listed

---

## HTTP Routes Implemented

| HTTP Method | Route | Description | Handler |
|-------------|-------|-------------|---------|
| `GET` | `/course` | Get all courses | `getAllCourses()` |
| `GET` | `/course/:id` | Get course by ID | `getCourseById(id)` |
| `POST` | `/course` | Create new course | `createCourse(name)` |
| `PUT` | `/course/:id` | Full update | `updateCourse(id, data)` |
| `PATCH` | `/course/:id` | Partial update | `patchCourse(id, data)` |
| `DELETE` | `/course/:id` | Delete course | `deleteCourse(id)` |

---

## Controller Breakdown (`course.controller.ts`)

### Decorators Explained

```typescript
@Controller('course')  // Base route prefix
export class CourseController {
  
  constructor(private readonly courseService: CourseService) {}
  // ↑ Dependency Injection - NestJS provides the service instance

  @Get()  // Maps to GET /course
  getAllCourses(): string {
    return this.courseService.getAllCourses();
  }

  @Get(':id')  // Maps to GET /course/:id
  getCourseById(@Param('id') id: string): string {
    // @Param extracts route parameter
    return this.courseService.getCourseById(id);
  }

  @Post()  // Maps to POST /course
  createCourse(@Body('name') name: string) {
    // @Body extracts data from request body
    return this.courseService.createCourse(name);
  }

  @Put(':id')  // Maps to PUT /course/:id
  updateCourse(@Param('id') id: string, @Body() updateData: any) {
    // @Body() without property extracts entire body
    return this.courseService.updateCourse(id, updateData);
  }

  @Patch(':id')  // Maps to PATCH /course/:id
  patchCourse(@Param('id') id: string, @Body() patchData: any) {
    return this.courseService.patchCourse(id, patchData);
  }

  @Delete(':id')  // Maps to DELETE /course/:id
  deleteCourse(@Param('id') id: string) {
    return this.courseService.deleteCourse(id);
  }
}
```

### Key Decorators

| Decorator | Purpose |
|-----------|---------|
| `@Controller('prefix')` | Sets base route for all endpoints |
| `@Get()`, `@Post()`, `@Put()`, `@Patch()`, `@Delete()` | Maps HTTP methods |
| `@Param('name')` | Extracts URL parameter |
| `@Body()` | Extracts request body |
| `@Body('property')` | Extracts specific property from body |

---

## Service Breakdown (`course.service.ts`)

```typescript
@Injectable()  // Marks class as injectable provider
export class CourseService {
  
  getAllCourses(): string {
    return 'All courses';
  }

  getCourseById(id: string): string {
    return `Course with ID ${id}`;
  }

  createCourse(name: string): string {
    return `Course ${name} created`;
  }

  updateCourse(id: string, updateData: any): string {
    return `Course ${id} fully updated`;
  }

  patchCourse(id: string, patchData: any): string {
    return `Course ${id} partially updated`;
  }

  deleteCourse(id: string): string {
    return `Course ${id} deleted`;
  }
}
```

**Why `@Injectable()`?**
- Registers the class with NestJS DI container
- Allows injection into controllers via constructor
- Required for any class that should be managed by NestJS

---

## Application Bootstrap (`main.ts`)

```typescript
async function bootstrap() {
  const app = await NestFactory.create(AppModule);  // Creates app instance
  await app.listen(process.env.PORT ?? 3000);       // Starts server on port 3000
}
bootstrap();
```

---

## Testing the API

### Using cURL

```bash
# Get all courses
curl http://localhost:3000/course

# Get course by ID
curl http://localhost:3000/course/1

# Create course
curl -X POST http://localhost:3000/course -H "Content-Type: application/json" -d '{"name":"NestJS"}'

# Update course (full)
curl -X PUT http://localhost:3000/course/1 -H "Content-Type: application/json" -d '{"name":"Updated"}'

# Update course (partial)
curl -X PATCH http://localhost:3000/course/1 -H "Content-Type: application/json" -d '{"name":"Patched"}'

# Delete course
curl -X DELETE http://localhost:3000/course/1
```

### Using Postman

| Method | URL | Body |
|--------|-----|------|
| GET | `http://localhost:3000/course` | None |
| GET | `http://localhost:3000/course/1` | None |
| POST | `http://localhost:3000/course` | `{"name": "Course Name"}` |
| PUT | `http://localhost:3000/course/1` | `{"name": "New Name"}` |
| PATCH | `http://localhost:3000/course/1` | `{"name": "Updated"}` |
| DELETE | `http://localhost:3000/course/1` | None |

---

## Key Takeaways

1. **Module-Controller-Service Pattern**
   - Module organizes code
   - Controller handles HTTP
   - Service contains business logic

2. **Dependency Injection**
   - Services are injected into controllers
   - No manual instantiation with `new`

3. **HTTP Method Mapping**
   - Each decorator maps to an HTTP verb
   - Route parameters extracted with `@Param`
   - Body data extracted with `@Body`

4. **Separation of Concerns**
   - Controllers: Request/Response handling
   - Services: Business logic
   - Never put business logic in controllers

---

## What's Missing (Coming in Lab 2)

- ❌ DTOs (Data Transfer Objects) for validation
- ❌ Global ValidationPipe
- ❌ Structured JSON responses
- ❌ File upload handling
- ❌ `class-validator` decorators
