#include <stdio.h>
#include "course.h"
#include "courseResult.h"

int testCompletedResult()
{
    Course course = createCourse("CSE 4202", "Structured Programming II Lab", 1.5);
    CourseResult result = createCompletedCourseResult(&course, 120);
    return result.completed == 1;
}

int testCompletedMarks()
{
    Course course = createCourse("CSE 4202", "Structured Programming II Lab", 1.5);
    CourseResult result = createCompletedCourseResult(&course, 120);
    return result.marks == 120;
}

int testIncompleteMarks()
{
    Course course = createCourse("CSE 4202", "Structured Programming II Lab", 1.5);
    CourseResult incomplete = createIncompleteCourseResult(&course);
    return incomplete.marks == 0.0;
}

int testIncompleteResult()
{
    Course course = createCourse("CSE 4202", "Structured Programming II Lab", 1.5);
    CourseResult incomplete = createIncompleteCourseResult(&course);
    return incomplete.completed == 0;
}

int main()
{
    printf("Course result module tests\n");
    int passed = 0;
    int total = 0;

    total++;
    if (testCompletedResult()) passed++;
    total++;
    if (testCompletedMarks()) passed++;
    total++;
    if (testIncompleteMarks()) passed++;
    total++;
    if (testIncompleteResult()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}