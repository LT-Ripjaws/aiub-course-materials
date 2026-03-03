import { Injectable } from '@nestjs/common';

@Injectable()
export class CourseService {

    getAllCourses(): string {
    return 'All courses';
    }

    getCourseById(id: string): string {
        return `Course with ID ${id}`;
    }

    createCourse(name: string): string {
        return `Course ${name} created`;
    }

    updateCourse(id: string, updateData: any): string {
        return `Course ${id} fully updated`;
    }

    patchCourse(id: string, patchData: any): string {
        return `Course ${id} partially updated`;
    }

    deleteCourse(id: string): string {
        return `Course ${id} deleted`;
    }
}
