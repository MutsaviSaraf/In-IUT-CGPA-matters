#ifndef COURSE_RESULT_H
#define COURSE_RESULT_H

#include "course.h"

typedef struct CourseResult
{
    Course *course;
    double marks;
} CourseResult;

CourseResult createCourseResult(Course *course, double marks);
void viewCourseResult(CourseResult result);

#endif