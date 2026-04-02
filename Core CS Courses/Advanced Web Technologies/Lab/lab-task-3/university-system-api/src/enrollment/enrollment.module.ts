import { Module, forwardRef } from '@nestjs/common';
import { CourseModule } from '../course/course.module';
import { NotificationModule } from '../notification/notification.module';
import { EnrollmentController } from './enrollment.controller';
import { EnrollmentService } from './enrollment.service';

@Module({
  imports: [CourseModule, forwardRef(() => NotificationModule)],
  controllers: [EnrollmentController],
  providers: [EnrollmentService],
  exports: [EnrollmentService],
})
export class EnrollmentModule {}
