import { Injectable, NotFoundException } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { Products } from './entities/products.entity';
import { ILike, Repository } from 'typeorm';
import { CreateProductDto } from './dto/create-product.dto';
import { PartialUpdateProductDto } from './dto/partial-update-product.dto';
import { UpdateProductDto } from './dto/update-product.dto';

@Injectable()
export class ProductsService {
    constructor(
        @InjectRepository(Products)
        private productsRepository: Repository<Products>
    ) {}

    async create(createProductDto: CreateProductDto): Promise<Products> {
        const product = this.productsRepository.create(createProductDto);
        return await this.productsRepository.save(product);
    }

    async findAll(): Promise<Products[]> {
        const products = await this.productsRepository.find({
            order: {
                createdAt: 'DESC'
            }
        });
        return products;
    }

    async findOne(id: number): Promise<Products> {
        const product = await this.productsRepository.findOneBy({ id });
        if (!product) {
            throw new NotFoundException(`Product with id ${id} not found`);
        }
        return product;
    }

    async update(id: number, partialUpdateProductDto: PartialUpdateProductDto): Promise<Products> {
        const product = await this.findOne(id);
        Object.assign(product, partialUpdateProductDto);
        return await this.productsRepository.save(product);
    }

    async replace(id: number, updateProductDtio: UpdateProductDto): Promise<Products> {
        const product = await this.findOne(id);
        Object.assign(product, updateProductDtio);
        return await this.productsRepository.save(product);
    }

    async remove(id: number): Promise<void> {
        const product = await this.findOne(id);
        await this.productsRepository.remove(product);
    }

     async findByCategory(category: string): Promise<Products[]> {
        const products = await this.productsRepository.find({
            where: { category },
            order: {
                createdAt: 'DESC'
            }
        });
        return products;
    }

    async search(keyword: string): Promise<Products[]> {
        return this.productsRepository.find({
        where: { name: ILike(`%${keyword}%`) },
        });
    
    }

    async toggleActive(id: number): Promise<Products> {
        const product = await this.findOne(id);
        product.isActive = !product.isActive;
        return await this.productsRepository.save(product);
    }

}
