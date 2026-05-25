import { Controller, Get, Param, ParseIntPipe, Post, Query, Body, Patch, Put, Delete } from '@nestjs/common';
import { ProductsService } from './products.service';
import { CreateProductDto } from './dto/create-product.dto';
import { UpdateProductDto } from './dto/update-product.dto';
import { PartialUpdateProductDto } from './dto/partial-update-product.dto';

@Controller('products')
export class ProductsController {

    constructor(private readonly productsService: ProductsService) {}

    @Get()
    getAllProducts() {
        return this.productsService.findAll();
    }

    @Post()
    createProduct(@Body() createProductDto: CreateProductDto) {
        return this.productsService.create(createProductDto);
    }

    @Get('search')
    searchProducts(@Query('keyword') keyword: string) {
        return this.productsService.search(keyword);
    }

    @Get('category')
    getProductsByCategory(@Param('cat') cat: string) {
        return this.productsService.findByCategory(cat);
    }

    @Get(':id')
    getProductById(@Param('id', ParseIntPipe) id: number) {
        return this.productsService.findOne(id);
    }

    @Put(':id')
    updateProduct(@Param('id', ParseIntPipe) id: number, @Body() updateProductDto: UpdateProductDto) {
        return this.productsService.replace(id, updateProductDto);
    }

    @Patch(':id')
    partialUpdate(@Param('id', ParseIntPipe) id: number, @Body() partialUpdateDto: PartialUpdateProductDto) {
        return this.productsService.update(id, partialUpdateDto);
    }

    @Delete(':id')
    removeProduct(@Param('id', ParseIntPipe) id: number) {
        return this.productsService.remove(id);
    }

}
