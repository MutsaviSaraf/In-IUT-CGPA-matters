#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"

int testCGPA()
{
    Course courses[3] = {
        createCourse("CSE 4107", "Structured Programming I", 3.0, 1),
        createCourse("CSE 4108", "Structured Programming I Lab", 1.5, 1),
        createCourse("CSE 4203", "Discrete Mathematics", 3.0, 2)
    };
    CourseResult results[3] = {
        createCompletedCourseResult(&courses[0], 240),
        createCompletedCourseResult(&courses[1], 105),
        createIncompleteCourseResult(&courses[2])
    };
    double cgpa = calculateGPA(results, 3);
    return cgpa > 3.83 && cgpa < 3.84;
}

int testGradePoint()
{
    Course course = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    CourseResult result = createCompletedCourseResult(&course, 240);
    return getGradePoint(result) == 4.00;
}

int testLetterGrade()
{
    Course course = createCourse("CSE 4108", "Structured Programming I Lab", 1.5, 1);
    CourseResult result = createCompletedCourseResult(&course, 105);
    return getLetterGrade(result)[0] == 'A' && getLetterGrade(result)[1] == '-';
}

int testExpectedCGPA()
{
    double expected = calculateExpectedCGPA(3.50, 90, 4.00, 30);
    return expected > 3.62 && expected < 3.63;
}

int main()
{
    printf("GPA module tests\n");
    int passed = 0;
    int total = 0;

    total++;
    if (testCGPA()) passed++;
    total++;
    if (testGradePoint()) passed++;
    total++;
    if (testLetterGrade()) passed++;
    total++;
    if (testExpectedCGPA()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}