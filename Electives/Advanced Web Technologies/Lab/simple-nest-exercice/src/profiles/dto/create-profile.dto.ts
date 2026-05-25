import {IsString, Length} from 'class-validator';

export class CreateProfileDto{
    id: string;
    @IsString()
    @Length(3, 50)
    name: string;
    @IsString()
    @Length(9, 200)
    description: string;
}