# Lab Task 2 - Course Management API (Validation + File Upload)

## Overview
This lab extends Lab Task 1 by adding **input validation** using DTOs with `class-validator`, **global pipes**, and **file upload** functionality using Multer.

---

## Project Structure
```
course-management-api/
├── src/
│   ├── course/
│   │   ├── course.module.ts
│   │   ├── course.controller.ts
│   │   ├── course.service.ts
│   │   └── dto/
│   │       ├── create-course.dto.ts
│   │       └── update-course.dto.ts
│   ├── app.module.ts
│   └── main.ts
└── uploads/              # Uploaded files storage
```

---

## Core Concepts

### 1. DTOs (Data Transfer Objects)

DTOs define the shape of data and enforce validation rules.

```typescript
// create-course.dto.ts
export class CreateCourseDto {
  @IsString()
  @IsNotEmpty()
  name!: string;

  @IsString()
  @IsNotEmpty()
  code!: string;

  @IsString()
  @IsNotEmpty()
  instructor!: string;

  @Type(() => Number)
  @IsNumber()
  @Min(1)
  @Max(6)
  credits!: number;

  @IsString()
  @IsOptional()
  description?: string;
}
```

### 2. Validation Decorators

| Decorator | Purpose |
|-----------|---------|
| `@IsString()` | Must be a string |
| `@IsNotEmpty()` | Cannot be empty |
| `@IsNumber()` | Must be a number |
| `@Min(n)` | Minimum value |
| `@Max(n)` | Maximum value |
| `@IsOptional()` | Field is optional |
| `@Type(() => Number)` | Transform string to number |

---

## Global ValidationPipe (`main.ts`)

```typescript
async function bootstrap() {
  const app = await NestFactory.create(AppModule);
  
  app.useGlobalPipes(new ValidationPipe({
    whitelist: true,            // Remove fields not in DTO
    forbidNonWhitelisted: true, // Return 400 for unknown fields
    transform: true,            // Auto-convert types (string → number)
  }));
  
  app.setGlobalPrefix('api');   // All routes prefixed with /api
  await app.listen(process.env.PORT ?? 3000);
}
```

### ValidationPipe Options Explained

| Option | Effect |
|--------|--------|
| `whitelist: true` | Strips properties not defined in DTO |
| `forbidNonWhitelisted: true` | Returns 400 error for unknown properties |
| `transform: true` | Converts types automatically |

### Example Validation Error Response

```json
{
  "statusCode": 400,
  "message": [
    "name should not be empty",
    "credits must not be greater than 6",
    "instructor should not be empty"
  ],
  "error": "Bad Request"
}
```

---

## HTTP Routes

| HTTP Method | Route | Description |
|-------------|-------|-------------|
| `GET` | `/api/course` | Get all courses |
| `GET` | `/api/course/:id` | Get course by ID |
| `POST` | `/api/course` | Create new course |
| `PUT` | `/api/course/:id` | Full update |
| `PATCH` | `/api/course/:id` | Partial update |
| `DELETE` | `/api/course/:id` | Delete course |
| `POST` | `/api/course/:id/upload` | Upload course material |

---

## Controller Breakdown (`course.controller.ts`)

### Basic CRUD Routes

```typescript
@Controller('course')
export class CourseController {
  constructor(private readonly courseService: CourseService) {}

  @Post()
  create(@Body() createCourseDto: CreateCourseDto) {
    // DTO automatically validated by ValidationPipe
    return this.courseService.create(createCourseDto);
  }

  @Get()
  findAll() {
    return this.courseService.findAll();
  }

  @Get(':id')
  findOne(@Param('id') id: string) {
    return this.courseService.findOne(id);
  }

  @Put(':id')
  update(@Param('id') id: string, @Body() updateCourseDto: UpdateCourseDto) {
    return this.courseService.update(id, updateCourseDto);
  }

  @Patch(':id')
  patch(@Param('id') id: string, @Body() updateCourseDto: UpdateCourseDto) {
    return this.courseService.patch(id, updateCourseDto);
  }

  @Delete(':id')
  remove(@Param('id') id: string) {
    return this.courseService.remove(id);
  }
}
```

### File Upload Route

```typescript
@Post(':id/upload')
@UseInterceptors(
  FileInterceptor('file', {
    storage: diskStorage({
      destination: './uploads',
      filename: (_req, file, cb) => {
        const uniqueSuffix = Date.now() + '-' + file.originalname;
        cb(null, uniqueSuffix);
      },
    }),
    fileFilter: (_req, file, cb) => {
      const allowedExtensions = ['.jpg', '.jpeg', '.png', '.pdf'];
      const ext = file.originalname.toLowerCase().substring(
        file.originalname.lastIndexOf('.')
      );
      if (allowedExtensions.includes(ext)) {
        cb(null, true);
      } else {
        cb(null, false);  // Reject file
      }
    },
    limits: {
      fileSize: 2 * 1024 * 1024,  // 2MB max
    },
  }),
)
uploadCourseMaterial(
  @Param('id') id: string,
  @UploadedFile() file: any,
) {
  return this.courseService.uploadCourseMaterial(id, file);
}
```

### File Upload Configuration

| Option | Purpose |
|--------|---------|
| `destination` | Where files are saved |
| `filename` | Custom filename generator |
| `fileFilter` | Accept/reject files by type |
| `limits.fileSize` | Maximum file size in bytes |

---

## Service with Structured Responses (`course.service.ts`)

```typescript
@Injectable()
export class CourseService {
  private courses: any[] = [];

  create(createCourseDto: CreateCourseDto) {
    this.courses.push(createCourseDto);
    return {
      message: 'Course created successfully',
      data: createCourseDto,
    };
  }

  findAll() {
    return {
      message: 'All courses fetched successfully',
      data: this.courses,
    };
  }

  findOne(id: string) {
    return {
      message: 'Course fetched successfully',
      id,
    };
  }

  update(id: string, updateCourseDto: UpdateCourseDto) {
    return {
      message: 'Course updated successfully',
      id,
      data: updateCourseDto,
    };
  }

  patch(id: string, updateCourseDto: UpdateCourseDto) {
    const updatedFields = Object.keys(updateCourseDto);
    return {
      message: 'Course patched successfully',
      id,
      updatedFields,
    };
  }

  remove(id: string) {
    return {
      message: 'Course deleted successfully',
      id,
    };
  }

  uploadCourseMaterial(id: string, file: any) {
    return {
      message: 'Material uploaded successfully',
      courseId: id,
      filename: file.filename,
      path: file.path,
    };
  }
}
```

---

## Update DTO with `PartialType`

```typescript
// update-course.dto.ts
export class UpdateCourseDto extends PartialType(CreateCourseDto) {}
```

**Why `PartialType`?**
- Makes all properties optional
- Perfect for PATCH/PUT operations
- Inherits all validation rules from `CreateCourseDto`

---

## Module Configuration (`course.module.ts`)

```typescript
@Module({
  imports: [
    MulterModule.register({
      dest: './uploads',  // Default upload directory
    }),
  ],
  controllers: [CourseController],
  providers: [CourseService],
})
export class CourseModule {}
```

---

## Testing the API

### Valid Requests (200/201)

```bash
# Create course
curl -X POST http://localhost:3000/course \
  -H "Content-Type: application/json" \
  -d '{"name":"NestJS","code":"CS101","instructor":"John","credits":3}'

# Upload file
curl -X POST http://localhost:3000/course/1/upload \
  -F "file=@document.pdf"
```

### Invalid Requests (400)

```bash
# Empty name - validation error
curl -X POST http://localhost:3000/course \
  -H "Content-Type: application/json" \
  -d '{"name":"","code":"CS101","instructor":"John","credits":3}'

# Credits > 6 - validation error
curl -X POST http://localhost:3000/course \
  -H "Content-Type: application/json" \
  -d '{"name":"Test","code":"CS101","instructor":"John","credits":10}'

# Unknown field - forbidNonWhitelisted error
curl -X POST http://localhost:3000/course \
  -H "Content-Type: application/json" \
  -d '{"name":"Test","code":"CS101","instructor":"John","credits":3,"unknown":"field"}'

# Invalid file type
curl -X POST http://localhost:3000/course/1/upload \
  -F "file=@document.txt"
```

---

## Key Takeaways

### 1. DTOs + Validation
- DTOs define data shape
- Decorators enforce rules
- ValidationPipe auto-validates

### 2. Structured Responses
- Consistent JSON format
- `message` + `data` pattern
- Better API predictability

### 3. File Upload
- `FileInterceptor` handles multipart
- `fileFilter` validates extensions
- `limits` controls file size

### 4. Global Pipes
- Applied to all routes
- Consistent validation behavior
- Auto-transformation of types

---

## Comparison: Lab 1 vs Lab 2

| Feature | Lab 1 | Lab 2 |
|---------|-------|-------|
| Validation | ❌ None | ✅ DTOs + Decorators |
| Response Format | Plain strings | ✅ Structured JSON |
| Global Pipe | ❌ | ✅ ValidationPipe |
| File Upload | ❌ | ✅ Multer |
| Type Conversion | Manual | ✅ Auto (transform: true) |
| Unknown Fields | Allowed | ✅ Rejected |

---

## What's Next (Lab 3)

- ✅ Basic REST (Lab 1)
- ✅ Validation + File Upload (Lab 2)
- ⏭️ **Dependency Injection Patterns** (Lab 3)
  - Intra-Module DI
  - Inter-Module DI
  - Circular DI with `forwardRef()`
