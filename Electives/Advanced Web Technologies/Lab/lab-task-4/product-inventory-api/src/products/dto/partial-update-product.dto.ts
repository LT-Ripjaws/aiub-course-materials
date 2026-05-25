import { CreateProductDto } from "./create-product.dto";
import { PartialType } from "@nestjs/mapped-types";

export class PartialUpdateProductDto extends PartialType(CreateProductDto) {}

