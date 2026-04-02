import { Injectable } from '@nestjs/common';

@Injectable()
export class CourseService {
  getAllCourses() {
    return { message: 'All courses fetched', data: [] };
  }

  getCourseById(id: string) {
    return { message: 'Course fetched', id };
  }

  createCourse(name: string, code: string) {
    return { message: 'Course created', data: { name, code } };
  }
}
