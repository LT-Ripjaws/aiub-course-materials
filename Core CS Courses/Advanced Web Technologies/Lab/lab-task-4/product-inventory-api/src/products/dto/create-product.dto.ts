import { Type } from 'class-transformer';
import { IsBoolean, isInt, isNotEmpty, isNumber, IsOptional, isPositive, isString, Min } from 'class-validator';

export class CreateProductDto {
    @isString()
    @isNotEmpty()
    name: string;

    @isString()
    @IsOptional()
    description: string;

    @isNumber()
    @isPositive()
    @Type(() => Number)
    price: number;

    @isInt()
    @Min(0)
    @IsOptional()
    @Type(() => Number)
    stock: number;

    @isString()
    @isNotEmpty()
    category: string;

    @IsBoolean()
    @IsOptional()
    isActive: boolean;
}
