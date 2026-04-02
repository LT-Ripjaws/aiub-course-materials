import { Controller, Get, Post, Body } from '@nestjs/common';
import { EnrollmentService } from './enrollment.service';

@Controller('enrollment')
export class EnrollmentController {
  constructor(private readonly enrollmentService: EnrollmentService) {}

  @Get()
  getEnrollments() {
    return this.enrollmentService.getEnrollments();
  }

  @Post()
  enroll(@Body() body: { studentName: string; courseId: string }) {
    return this.enrollmentService.enrollStudent(body.studentName, body.courseId);
  }
}
