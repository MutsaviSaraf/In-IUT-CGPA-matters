#ifndef COURSE_RESULT_H
#define COURSE_RESULT_H

#include "course.h"

typedef struct CourseResult
{
    Course *course;
    double marks;
} CourseResult;

CourseResult createCourseResult(Course *course, double marks);
void sortCourseResultsBySemester(CourseResult results[], int n_results);
void filterCourseResultsBySemester(CourseResult results[], int n_results, int semester, CourseResult filtered[]);
int countCourseResultsBeforeNull(CourseResult results[], int n_results);
void viewCourseResult(CourseResult result);

#endif