import { Module } from '@nestjs/common';
import { MulterModule } from '@nestjs/platform-express';
import { CourseService } from './course.service';
import { CourseController } from './course.controller';

@Module({
  imports: [
    MulterModule.register({
      dest: './uploads',
    }),
  ],
  controllers: [CourseController],
  providers: [CourseService],
})
export class CourseModule {}
