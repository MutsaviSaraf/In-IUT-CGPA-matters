#include <stdio.h>
#include "course.h"
#include "courseResult.h"

int testCompletedResult()
{
    Course course = createCourse("CSE 4202", "Structured Programming II Lab", 1.5, 2);
    // Updated: added 1 as the third argument
    CourseResult result = createCourseResult(&course, 120, 1);
    return result.course == &course;
}

int testCompletedMarks()
{
    Course course = createCourse("CSE 4202", "Structured Programming II Lab", 1.5, 2);
    // Updated: added 1 as the third argument
    CourseResult result = createCourseResult(&course, 120, 1);
    return result.marks == 120;
}

int testSortBySemester()
{
    Course courses[3] = {
        createCourse("CSE 4203", "Discrete Mathematics", 3.0, 2),
        createCourse("CSE 4107", "Structured Programming I", 3.0, 1),
        createCourse("CSE 4108", "Structured Programming I Lab", 1.5, 1)
    };
    CourseResult results[3] = {
        // Updated: added 1 to each call
        createCourseResult(&courses[0], 210, 1),
        createCourseResult(&courses[1], 240, 1),
        createCourseResult(&courses[2], 105, 1)
    };

    sortCourseResultsBySemester(results, 3);

    return results[0].course->semester == 1 && results[2].course->semester == 2;
}

int testFilterBySemester()
{
    Course courses[3] = {
        createCourse("CSE 4107", "Structured Programming I", 3.0, 1),
        createCourse("CSE 4108", "Structured Programming I Lab", 1.5, 1),
        createCourse("CSE 4203", "Discrete Mathematics", 3.0, 2)
    };
    CourseResult results[3] = {
        createCourseResult(&courses[0], 240, 1),
        createCourseResult(&courses[1], 105, 1),
        createCourseResult(&courses[2], 210, 1)
    };
    CourseResult filtered[4];

    filterCourseResultsBySemester(results, 3, 1, filtered);

    return countCourseResultsBeforeNull(filtered, 4) == 2;
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
    if (testSortBySemester()) passed++;
    total++;
    if (testFilterBySemester()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}