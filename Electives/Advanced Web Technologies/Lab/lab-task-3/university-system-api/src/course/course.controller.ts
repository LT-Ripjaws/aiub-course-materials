import { Controller, Get, Post, Body, Param } from '@nestjs/common';
import { CourseService } from './course.service';

@Controller('course')
export class CourseController {
  constructor(private readonly courseService: CourseService) {}

  @Get()
  getAll() {
    return this.courseService.getAllCourses();
  }

  @Get(':id')
  getById(@Param('id') id: string) {
    return this.courseService.getCourseById(id);
  }

  @Post()
  create(@Body() body: { name: string; code: string }) {
    return this.courseService.createCourse(body.name, body.code);
  }
}
