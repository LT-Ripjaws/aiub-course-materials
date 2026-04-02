import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { CourseModule } from './course/course.module';
import { EnrollmentModule } from './enrollment/enrollment.module';
import { NotificationModule } from './notification/notification.module';

@Module({
  imports: [CourseModule, EnrollmentModule, NotificationModule],
  controllers: [AppController],
  providers: [AppService],
})
export class AppModule {}
