# Simple NestJS Exercise - Profiles Management API

## Overview
This exercise demonstrates intermediate NestJS concepts including **custom guards**, **exception filters**, **UUID validation**, and **CRUD operations** with in-memory storage.

---

## Project Structure
```
simple-nest-exercice/
├── src/
│   ├── profiles/
│   │   ├── profiles.module.ts
│   │   ├── profiles.controller.ts
│   │   ├── profiles.service.ts
│   │   ├── profiles.guard.ts
│   │   └── dto/
│   │       └── create-profile.dto.ts
│   ├── app.module.ts
│   ├── app.controller.ts
│   ├── app.service.ts
│   └── main.ts
```

---

## Core Concepts

### 1. Module Architecture

```
┌─────────────────────────────────────────┐
│           AppModule                     │
│  ┌─────────────────────────────────┐    │
│  │         ProfilesModule          │    │
│  │  ┌───────────┐  ┌─────────────┐ │    │
│  │  │ Controller│  │   Service   │ │    │
│  │  │           │  │   + Guard   │ │    │
│  │  └───────────┘  └─────────────┘ │    │
│  └─────────────────────────────────┘    │
└─────────────────────────────────────────┘
```

---

## Profiles Module

### DTO (`create-profile.dto.ts`)

```typescript
export class CreateProfileDto {
  name: string;
  description: string;
}
```

Simple DTO without validation decorators (validation done manually in service).

---

### Service (`profiles.service.ts`)

```typescript
@Injectable()
export class ProfilesService {
  // In-memory storage
  private profiles = [
    { id: randomUUID(), name: 'John Doe', description: 'A software developer' },
    { id: randomUUID(), name: 'Jane Smith', description: 'A graphic designer' },
    { id: randomUUID(), name: 'Bob Johnson', description: 'A web developer' },
  ];

  findAll() {
    if (this.profiles.length === 0) {
      throw new NotFoundException('No profiles found');
    }
    return this.profiles;
  }

  findOne(id: string) {
    const matchingProfile = this.profiles.find(profile => profile.id === id);
    if (!matchingProfile) {
      throw new NotFoundException('Profile not found');
    }
    return matchingProfile;
  }

  create(createProfileDto: CreateProfileDto) {
    const newProfile = {
      id: randomUUID(),
      name: createProfileDto.name,
      description: createProfileDto.description,
    };
    this.profiles.push(newProfile);
    return newProfile;
  }

  update(id: string, updateProfileDto: CreateProfileDto) {
    const matchingProfile = this.profiles.find(profile => profile.id === id);
    if (matchingProfile) {
      matchingProfile.name = updateProfileDto.name;
      matchingProfile.description = updateProfileDto.description;
      return matchingProfile;
    }
    throw new BadRequestException('Profile not created');
  }

  delete(id: string) {
    const index = this.profiles.findIndex(profile => profile.id === id);
    if (index !== -1) {
      this.profiles.splice(index, 1);
      return true;
    }
    return false;
  }
}
```

### Key Points

| Feature | Implementation |
|---------|----------------|
| Storage | In-memory array |
| ID Generation | `randomUUID()` from `crypto` |
| Exception Handling | `NotFoundException`, `BadRequestException` |
| Search | `find()`, `findIndex()` |

---

### Controller (`profiles.controller.ts`)

```typescript
@Controller('profiles')
export class ProfilesController {
  constructor(private readonly profilesService: ProfilesService) {}

  @Get()
  findAll() {
    return this.profilesService.findAll();
  }

  @Get(':id')
  findOne(@Param('id', ParseUUIDPipe) id: UUID) {
    return this.profilesService.findOne(id);
  }

  @Post()
  create(@Body() createProfileDto: CreateProfileDto) {
    return `Created Profile: ${JSON.stringify(this.profilesService.create(createProfileDto))}`;
  }

  @Put('update')
  update(@Query('id', ParseUUIDPipe) id: UUID, @Body() updateProfileDto: CreateProfileDto) {
    return `Updated Profile: ${id} with data: ${JSON.stringify(this.profilesService.update(id, updateProfileDto))}`;
  }

  @Delete('delete')
  @UseGuards(ProfilesGuard)
  @HttpCode(HttpStatus.NO_CONTENT)
  delete(@Query('id', ParseUUIDPipe) id: UUID) {
    return this.profilesService.delete(id);
  }
}
```

---

## Special Features

### 1. UUID Validation with `ParseUUIDPipe`

```typescript
@Get(':id')
findOne(@Param('id', ParseUUIDPipe) id: UUID) {
  return this.profilesService.findOne(id);
}
```

**What it does:**
- Validates that the `:id` parameter is a valid UUID format
- Returns 400 error if invalid UUID
- Auto-transforms string to UUID type

**Example:**
```bash
# Valid UUID - works
curl http://localhost:3000/profiles/550e8400-e29b-41d4-a716-446655440000

# Invalid UUID - returns 400
curl http://localhost:3000/profiles/invalid-id
```

---

### 2. Custom Guard (`profiles.guard.ts`)

```typescript
@Injectable()
export class ProfilesGuard implements CanActivate {
  canActivate(
    context: ExecutionContext,
  ): boolean | Promise<boolean> | Observable<boolean> {
    const request = context.switchToHttp().getRequest();
    const id = request.query.id;
    
    // Custom logic: Check if ID exists
    // For demo, always returns true
    return true;
  }
}
```

**Usage:**
```typescript
@Delete('delete')
@UseGuards(ProfilesGuard)  // ← Guard applied here
delete(@Query('id', ParseUUIDPipe) id: UUID) {
  return this.profilesService.delete(id);
}
```

**What Guards Do:**
- Run **before** the route handler
- Can allow or deny request execution
- Common use: Authentication, authorization, logging

**Guard Execution Flow:**
```
Request → Guard (canActivate) → Handler (if true) → Response
                ↓
            Return false → 403 Forbidden
```

---

### 3. HTTP Status Code Customization

```typescript
@Delete('delete')
@UseGuards(ProfilesGuard)
@HttpCode(HttpStatus.NO_CONTENT)  // ← Returns 204 instead of 200
delete(@Query('id', ParseUUIDPipe) id: UUID) {
  return this.profilesService.delete(id);
}
```

**Common Status Codes:**

| Code | Constant | Use Case |
|------|----------|----------|
| 200 | `HttpStatus.OK` | Default success |
| 201 | `HttpStatus.CREATED` | Resource created |
| 204 | `HttpStatus.NO_CONTENT` | Success, no content to return |
| 400 | `HttpStatus.BAD_REQUEST` | Invalid input |
| 403 | `HttpStatus.FORBIDDEN` | Guard rejected |
| 404 | `HttpStatus.NOT_FOUND` | Resource not found |

---

### 4. Query Parameters vs Path Parameters

```typescript
// Path Parameter - part of URL
@Get(':id')
findOne(@Param('id') id: string) { }

// Query Parameter - after ? in URL
@Put('update')
update(@Query('id') id: string, @Body() data: CreateProfileDto) { }
```

**Request Examples:**
```bash
# Path parameter
GET /profiles/550e8400-e29b-41d4-a716-446655440000

# Query parameter
PUT /profiles/update?id=550e8400-e29b-41d4-a716-446655440000
```

---

## Routes Summary

| Method | Route | Description | Special Features |
|--------|-------|-------------|------------------|
| `GET` | `/profiles` | Get all profiles | Returns array |
| `GET` | `/profiles/:id` | Get profile by ID | `ParseUUIDPipe` |
| `POST` | `/profiles` | Create profile | Body DTO |
| `PUT` | `/profiles/update?id=:id` | Update profile | Query param + Body |
| `DELETE` | `/profiles/delete?id=:id` | Delete profile | Guard + 204 status |

---

## Testing the API

### Get All Profiles
```bash
curl http://localhost:3000/api/profiles
```

**Response:**
```json
[
  {
    "id": "550e8400-e29b-41d4-a716-446655440000",
    "name": "John Doe",
    "description": "A software developer"
  },
  ...
]
```

### Get Profile by ID
```bash
# Valid UUID
curl http://localhost:3000/api/profiles/550e8400-e29b-41d4-a716-446655440000

# Invalid UUID - returns 400
curl http://localhost:3000/api/profiles/invalid-id
```

### Create Profile
```bash
curl -X POST http://localhost:3000/api/profiles \
  -H "Content-Type: application/json" \
  -d '{"name":"Alice","description":"A data scientist"}'
```

### Update Profile
```bash
curl -X PUT "http://localhost:3000/api/profiles/update?id=550e8400-e29b-41d4-a716-446655440000" \
  -H "Content-Type: application/json" \
  -d '{"name":"Alice Updated","description":"Senior data scientist"}'
```

### Delete Profile
```bash
curl -X DELETE "http://localhost:3000/api/profiles/delete?id=550e8400-e29b-41d4-a716-446655440000" \
  -v  # Shows 204 No Content response
```

---

## Exception Handling

### Built-in Exceptions Used

```typescript
import { BadRequestException, NotFoundException } from '@nestjs/common';

// Not found
throw new NotFoundException('Profile not found');

// Bad request
throw new BadRequestException('Profile not created');
```

**Default Exception Response:**
```json
{
  "statusCode": 404,
  "message": "Profile not found",
  "error": "Not Found"
}
```

---

## Global Configuration (`main.ts`)

```typescript
async function bootstrap() {
  const app = await NestFactory.create(AppModule);
  
  app.useGlobalPipes(new ValidationPipe({
    whitelist: true,
    forbidNonWhitelisted: true,
    transform: true,
  }));
  
  app.setGlobalPrefix('api');  // All routes under /api
  await app.listen(process.env.PORT ?? 3000);
}
```

---

## Key Takeaways

### 1. UUID Handling
- Use `ParseUUIDPipe` for validation
- Type: `UUID` from `crypto` module
- Generates unique identifiers with `randomUUID()`

### 2. Guards
- Implement `CanActivate` interface
- Use `@UseGuards()` decorator
- Run before route handlers
- Return `true` to proceed, `false` to deny

### 3. HTTP Status Codes
- Use `@HttpCode()` to customize response
- `204 No Content` for successful deletes
- Default is `200 OK`

### 4. Parameters
- `@Param()` - Path parameters (`/profiles/:id`)
- `@Query()` - Query parameters (`/update?id=...`)
- `@Body()` - Request body

### 5. In-Memory Storage
- Simple array for demo purposes
- In production: Use database (TypeORM, Prisma, Mongoose)

---

## Comparison with Other Labs

| Feature | Lab 1 | Lab 2 | Lab 3 | This Exercise |
|---------|-------|-------|-------|---------------|
| Basic CRUD | ✅ | ✅ | ✅ | ✅ |
| DTOs | ❌ | ✅ | ❌ | ✅ |
| Validation | ❌ | ✅ | ❌ | ⚠️ Manual |
| File Upload | ❌ | ✅ | ❌ | ❌ |
| DI Patterns | ❌ | ❌ | ✅ | ❌ |
| Guards | ❌ | ❌ | ❌ | ✅ |
| UUID | ❌ | ❌ | ❌ | ✅ |
| Custom Status | ❌ | ❌ | ❌ | ✅ |

---

## When to Use Guards

| Scenario | Use Guard |
|----------|-----------|
| Check authentication token | ✅ |
| Verify user role/permission | ✅ |
| Rate limiting | ✅ |
| Request logging | ✅ |
| Input validation | ❌ (Use Pipes) |
| Business logic | ❌ (Use Service) |

---

## Best Practices Demonstrated

1. **Separation of Concerns** - Controller → Service → Data
2. **Dependency Injection** - Services injected via constructor
3. **Exception Handling** - Throw appropriate HTTP exceptions
4. **Type Safety** - Use TypeScript types (UUID, DTOs)
5. **Guard Usage** - Protect sensitive operations (DELETE)
6. **Status Codes** - Use appropriate HTTP status codes
