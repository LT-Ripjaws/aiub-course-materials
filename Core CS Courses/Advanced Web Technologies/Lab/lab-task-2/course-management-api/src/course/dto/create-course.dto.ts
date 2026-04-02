import {IsString, IsNotEmpty, IsNumber, Min, Max, IsOptional } from 'class-validator';
import { Type } from 'class-transformer';

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
