#ifndef GPA_H
#define GPA_H

#include "courseResult.h"

extern const double gradeBoundaries[];
extern const double gradePoints[];
extern const char *gradeLetters[];

double getGradePoint(CourseResult result);
char *getLetterGrade(CourseResult result);
double calculateGPA(CourseResult results[], int n_results);

#endif