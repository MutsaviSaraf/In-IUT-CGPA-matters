#include <stdio.h>
#include "course.h"
#include "courseResult.h"

int testResultCourse()
{
    Course course = createCourse("CSE 4202", "Structured Programming II Lab", 1.5);
    CourseResult result = createCourseResult(&course, 77);
    return result.course == &course;
}

int testResultMarks()
{
    Course course = createCourse("CSE 4202", "Structured Programming II Lab", 1.5);
    CourseResult result = createCourseResult(&course, 77);
    return result.marks == 77;
}

int main()
{
    printf("Course result module tests\n");
    int passed = 0;
    int total = 0;

    total++;
    if (testResultCourse()) passed++;
    
    total++;
    if (testResultMarks()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}