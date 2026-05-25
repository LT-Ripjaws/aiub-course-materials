# Lab Task 4 - Product Inventory API (Database Integration with TypeORM)

## Overview
This lab introduces **database integration** in NestJS using **TypeORM** with **PostgreSQL**. We learn how to work with entities, repositories, DTOs, and perform full CRUD operations against a real database.

---

## Project Structure
```
product-inventory-api/
├── src/
│   ├── products/
│   │   ├── products.module.ts
│   │   ├── products.controller.ts
│   │   ├── products.service.ts
│   │   ├── dto/
│   │   │   ├── create-product.dto.ts
│   │   │   ├── update-product.dto.ts
│   │   │   └── partial-update-product.dto.ts
│   │   └── entities/
│   │       └── products.entity.ts
│   ├── app.module.ts
│   └── main.ts
```

---

## Core Concepts

### 1. TypeORM Architecture

```
┌─────────────────────────────────────────────────────────┐
│                    NestJS Application                    │
│                                                          │
│  ┌──────────────┐    ┌──────────────┐    ┌────────────┐ │
│  │  Controller  │ →  │   Service    │ →  │ Repository │ │
│  │              │    │              │    │  (TypeORM) │ │
│  └──────────────┘    └──────────────┘    └─────┬──────┘ │
│                                                │        │
│                                       ┌────────▼───────┐│
│                                       │   PostgreSQL   ││
│                                       │    Database    ││
│                                       └────────────────┘│
└─────────────────────────────────────────────────────────┘
```

### 2. Entity Definition (`products.entity.ts`)

Entities map TypeScript classes to database tables.

```typescript
@Entity()
export class Products {
    @PrimaryGeneratedColumn()
    id: number;

    @Column()
    name: string;

    @Column({ nullable: true })
    description: string;

    @Column({ type: 'decimal', precision: 10, scale: 2 })
    price: number;

    @Column({ default: 0 })
    stock: number;

    @Column()
    category: string;

    @Column({ default: true })
    isActive: boolean;

    @CreateDateColumn()
    createdAt: Date;

    @UpdateDateColumn()
    updatedAt: Date;
}
```

### Column Options Explained

| Option | Purpose |
|--------|---------|
| `@PrimaryGeneratedColumn()` | Auto-incrementing primary key |
| `@Column()` | Basic column with type inference |
| `{ nullable: true }` | Allows NULL values |
| `{ default: value }` | Sets default value |
| `{ type: 'decimal', precision: 10, scale: 2 }` | Precise decimal for currency |
| `@CreateDateColumn()` | Auto-set on creation |
| `@UpdateDateColumn()` | Auto-updated on every save |

---

## Database Configuration (`app.module.ts`)

```typescript
@Module({
  imports: [
    ProductsModule,
    TypeOrmModule.forRoot({
      type: 'postgres',              // Database driver
      host: 'localhost',
      port: 5432,
      username: 'postgres',
      password: 'postgres',
      database: 'product_inventory_db',
      autoLoadEntities: true,        // Auto-register entities
      synchronize: true,             // Auto-create tables (dev only!)
    }),
  ],
})
export class AppModule {}
```

### TypeORM Options Explained

| Option | Purpose |
|--------|---------|
| `type: 'postgres'` | Uses PostgreSQL driver |
| `autoLoadEntities: true` | Scans modules for `@Entity()` classes |
| `synchronize: true` | Syncs entity schema with DB (⚠️ disable in production) |

---

## Repository Injection (`products.service.ts`)

```typescript
@Injectable()
export class ProductsService {
    constructor(
        @InjectRepository(Products)
        private productsRepository: Repository<Products>
    ) {}
}
```

**Why `@InjectRepository(Products)`?**
- TypeORM provides a `Repository<T>` for each entity
- `@InjectRepository()` tells NestJS which entity's repository to inject
- Repository provides methods like `find()`, `save()`, `create()`, etc.

---

## Module Setup (`products.module.ts`)

```typescript
@Module({
  imports: [TypeOrmModule.forFeature([Products])],  // Registers repository
  controllers: [ProductsController],
  providers: [ProductsService],
})
export class ProductsModule {}
```

**Why `TypeOrmModule.forFeature([Products])`?**
- Registers the `Products` entity's repository in the module's DI container
- Required before you can `@InjectRepository(Products)`
- Different from `TypeOrmModule.forRoot()` which sets up the connection

---

## HTTP Routes

| HTTP Method | Route | Description |
|-------------|-------|-------------|
| `GET` | `/products` | Get all products (sorted by date) |
| `GET` | `/products/:id` | Get product by ID |
| `POST` | `/products` | Create new product |
| `PUT` | `/products/:id` | Full update |
| `PATCH` | `/products/:id` | Partial update |
| `DELETE` | `/products/:id` | Delete product |
| `GET` | `/products/search?keyword=...` | Search products by name |
| `GET` | `/products/category` | Get products by category |

---

## Controller Breakdown (`products.controller.ts`)

### ParseIntPipe for Route Parameters

```typescript
@Get(':id')
getProductById(@Param('id', ParseIntPipe) id: number) {
    return this.productsService.findOne(id);
}
```

**Why `ParseIntPipe`?**
- Converts string route param to number
- Returns 400 if value is not a valid integer
- No manual `parseInt()` needed

### Search Route

```typescript
@Get('search')
searchProducts(@Query('keyword') keyword: string) {
    return this.productsService.search(keyword);
}
```

**Important:** Define `/search` **before** `/:id` in the controller, otherwise NestJS will treat "search" as an ID.

---

## Service Methods (`products.service.ts`)

### Create

```typescript
async create(createProductDto: CreateProductDto): Promise<Products> {
    const product = this.productsRepository.create(createProductDto);
    return await this.productsRepository.save(product);
}
```

**`.create()` vs `.save()`**
- `.create()` creates entity instance (doesn't save to DB)
- `.save()` persists to database

### Find All

```typescript
async findAll(): Promise<Products[]> {
    return await this.productsRepository.find({
        order: { createdAt: 'DESC' }
    });
}
```

### Find One

```typescript
async findOne(id: number): Promise<Products> {
    const product = await this.productsRepository.findOneBy({ id });
    if (!product) {
        throw new NotFoundException(`Product with id ${id} not found`);
    }
    return product;
}
```

### Update (PATCH)

```typescript
async update(id: number, partialUpdateProductDto: PartialUpdateProductDto): Promise<Products> {
    const product = await this.findOne(id);
    Object.assign(product, partialUpdateProductDto);
    return await this.productsRepository.save(product);
}
```

### Replace (PUT)

```typescript
async replace(id: number, updateProductDto: UpdateProductDto): Promise<Products> {
    const product = await this.findOne(id);
    Object.assign(product, updateProductDto);
    return await this.productsRepository.save(product);
}
```

### Delete

```typescript
async remove(id: number): Promise<void> {
    const product = await this.findOne(id);
    await this.productsRepository.remove(product);
}
```

### Search with ILike

```typescript
async search(keyword: string): Promise<Products[]> {
    return this.productsRepository.find({
        where: { name: ILike(`%${keyword}%`) },
    });
}
```

**Why `ILike`?**
- Case-insensitive pattern matching
- `%keyword%` matches anywhere in the string
- Better UX than exact match

### Filter by Category

```typescript
async findByCategory(category: string): Promise<Products[]> {
    return this.productsRepository.find({
        where: { category },
        order: { createdAt: 'DESC' }
    });
}
```

---

## DTOs

### Create DTO (`create-product.dto.ts`)

```typescript
export class CreateProductDto {
    @IsString()
    @IsNotEmpty()
    name: string;

    @IsString()
    @IsOptional()
    description: string;

    @IsNumber()
    @IsPositive()
    @Type(() => Number)
    price: number;

    @IsInt()
    @Min(0)
    @IsOptional()
    @Type(() => Number)
    stock: number;

    @IsString()
    @IsNotEmpty()
    category: string;

    @IsBoolean()
    @IsOptional()
    isActive: boolean;
}
```

### Update DTO

```typescript
export class UpdateProductDto extends CreateProductDto {}
```

All fields required (full replacement).

### Partial Update DTO

```typescript
export class PartialUpdateProductDto extends PartialType(CreateProductDto) {}
```

All fields optional (partial update).

---

## ValidationPipe (`main.ts`)

```typescript
app.useGlobalPipes(new ValidationPipe({
    whitelist: true,
    forbidNonWhitelisted: true,
    transform: true,
}));
```

Same configuration as Lab 2 — consistent validation across all labs.

---

## Testing the API

### Database Setup

1. Install PostgreSQL
2. Create database:
```sql
CREATE DATABASE product_inventory_db;
```
3. Update credentials in `app.module.ts` if different

### Start the Server

```bash
npm run start:dev
```

Tables are auto-created due to `synchronize: true`.

### Using cURL

```bash
# Create product
curl -X POST http://localhost:3000/products \
  -H "Content-Type: application/json" \
  -d '{"name":"Laptop","description":"Gaming laptop","price":1299.99,"stock":10,"category":"Electronics"}'

# Get all products
curl http://localhost:3000/products

# Get product by ID
curl http://localhost:3000/products/1

# Search products
curl "http://localhost:3000/products/search?keyword=laptop"

# Get products by category
curl "http://localhost:3000/products/category?cat=Electronics"

# Update product (partial)
curl -X PATCH http://localhost:3000/products/1 \
  -H "Content-Type: application/json" \
  -d '{"price":1199.99}'

# Replace product (full)
curl -X PUT http://localhost:3000/products/1 \
  -H "Content-Type: application/json" \
  -d '{"name":"Laptop Pro","description":"Updated","price":1499.99,"stock":5,"category":"Electronics","isActive":true}'

# Delete product
curl -X DELETE http://localhost:3000/products/1
```

### Validation Errors

```bash
# Missing required field
curl -X POST http://localhost:3000/products \
  -H "Content-Type: application/json" \
  -d '{"description":"No name"}'
# → 400: "name should not be empty"

# Invalid price
curl -X POST http://localhost:3000/products \
  -H "Content-Type: application/json" \
  -d '{"name":"Test","price":-10}'
# → 400: "price must be a positive number"

# Unknown field
curl -X POST http://localhost:3000/products \
  -H "Content-Type: application/json" \
  -d '{"name":"Test","price":10,"unknown":"field"}'
# → 400: "property unknown should not exist"
```

---

## Key Takeaways

### 1. TypeORM Entities
- Map classes to tables
- Decorators define columns and constraints
- Auto-managed with `synchronize: true`

### 2. Repository Pattern
- `@InjectRepository(Entity)` injects repository
- Provides CRUD methods out of the box
- No raw SQL for basic operations

### 3. Query Operations
- `.find()` with `where`, `order`, etc.
- `ILike` for case-insensitive search
- `.findOneBy()` for single record lookup

### 4. Module Registration
- `TypeOrmModule.forRoot()` — DB connection (root module)
- `TypeOrmModule.forFeature([Entity])` — registers repository (feature module)

### 5. Validation
- Same DTOs + ValidationPipe pattern as Lab 2
- `ParseIntPipe` for route parameters
- Consistent error handling

---

## Comparison: Lab 1 → Lab 4

| Feature | Lab 1 | Lab 2 | Lab 3 | Lab 4 |
|---------|-------|-------|-------|-------|
| Data Storage | In-memory | In-memory | In-memory | ✅ PostgreSQL |
| ORM | ❌ | ❌ | ❌ | ✅ TypeORM |
| Entities | ❌ | ❌ | ❌ | ✅ `@Entity()` |
| Repository | ❌ | ❌ | ❌ | ✅ `Repository<T>` |
| Validation | ❌ | ✅ DTOs | ❌ | ✅ DTOs |
| Global Pipe | ❌ | ✅ | ❌ | ✅ |
| DI Patterns | Basic | Basic | ✅ Advanced | Basic |

---

## What We Learned

✅ TypeORM entity definition with decorators
✅ Repository injection pattern
✅ Database connection configuration
✅ CRUD operations with real persistence
✅ Case-insensitive search with `ILike`
✅ Query filtering and ordering
✅ `ParseIntPipe` for route parameters
✅ Auto-sync schema in development
