#include <stdio.h>
#include "courseResult.h"

CourseResult createCourseResult(Course *course, double marks)
{
    CourseResult result;
    result.course = course;
    result.marks = marks;
    return result;
}

void viewCourseResult(CourseResult result)
{
    printf("%s: %s\t\t [Credit: %.1f]\n",
           result.course->code, result.course->name, result.course->credit);
    printf("Marks: %.2f\n", result.marks);
}