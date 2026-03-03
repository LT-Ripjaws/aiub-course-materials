import { Controller, Delete, Get, Param, Patch, Post, Put, Body } from '@nestjs/common';
import { CourseService } from './course.service';

@Controller('course')
export class CourseController {
    constructor(private readonly courseService: CourseService ) {}

    @Get()
    getAllCourses(): string {
        return this.courseService.getAllCourses();
    }

    @Get(':id')
    getCourseById(@Param('id') id: string): string {
     return this.courseService.getCourseById(id);

    }

    @Post()
     createCourse(@Body('name') name: string) {
    return this.courseService.createCourse(name);
     }

    @Put(':id')
    updateCourse(
        @Param('id') id: string,
        @Body() updateData: any
    ) {
        return this.courseService.updateCourse(id, updateData);
    }

    @Patch(':id')
    patchCourse(
        @Param('id') id: string,
        @Body() patchData: any
    ) {
        return this.courseService.patchCourse(id, patchData);
    }

    @Delete(':id')
    deleteCourse(@Param('id') id: string) {
        return this.courseService.deleteCourse(id);
    }


}
