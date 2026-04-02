import { Injectable } from '@nestjs/common';
import { CreateCourseDto } from './dto/create-course.dto';
import { UpdateCourseDto } from './dto/update-course.dto';

@Injectable()
export class CourseService {
  private courses: any[] = [];

  create(createCourseDto: CreateCourseDto) {
    this.courses.push(createCourseDto);
    return {
      message: 'Course created successfully',
      data: createCourseDto,
    };
  }

  findAll() {
    return {
      message: 'All courses fetched successfully',
      data: this.courses,
    };
  }

  findOne(id: string) {
    return {
      message: 'Course fetched successfully',
      id,
    };
  }

  update(id: string, updateCourseDto: UpdateCourseDto) {
    return {
      message: 'Course updated successfully',
      id,
      data: updateCourseDto,
    };
  }

  patch(id: string, updateCourseDto: UpdateCourseDto) {
    const updatedFields = Object.keys(updateCourseDto);
    return {
      message: 'Course patched successfully',
      id,
      updatedFields,
    };
  }

  remove(id: string) {
    return {
      message: 'Course deleted successfully',
      id,
    };
  }

  uploadCourseMaterial(id: string, file: Express.Multer.File) {
    return {
      message: 'Material uploaded successfully',
      courseId: id,
      filename: file.filename,
      path: file.path,
    };
  }
}
