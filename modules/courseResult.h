#ifndef COURSE_RESULT_H
#define COURSE_RESULT_H

#include "course.h"

typedef struct CourseResult
{
    Course *course;
    double marks;
    int completed;
} CourseResult;

CourseResult createCourseResult(Course *course, double marks, int completed);
CourseResult createCompletedCourseResult(Course *course, double marks);
CourseResult createIncompleteCourseResult(Course *course);

void sortCourseResultsBySemester(CourseResult results[], int n_results);
void filterCourseResultsBySemester(CourseResult results[], int n_results, int semester, CourseResult filtered[]);
int countCourseResultsBeforeNull(CourseResult results[], int n_results);
void viewCourseResult(CourseResult result);

#endif