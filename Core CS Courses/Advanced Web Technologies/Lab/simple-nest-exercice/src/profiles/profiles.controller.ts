import { UseGuards, Controller, Get, Param, Body, Post, Put, Query, Delete, HttpCode, HttpStatus, NotFoundException, ParseUUIDPipe} from '@nestjs/common';
import { CreateProfileDto } from './dto/create-profile.dto';
import { ProfilesService } from './profiles.service';
import type {UUID} from 'crypto';
import { ProfilesGuard } from './profiles.guard';

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
    create(@Body() createProfileDto : CreateProfileDto) {
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
