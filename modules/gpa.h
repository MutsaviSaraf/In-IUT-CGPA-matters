#ifndef GPA_H
#define GPA_H

#include "courseResult.h"

extern const double gradeBoundaries[];
extern const double gradePoints[];
extern const char *gradeLetters[];

double getGradePoint(CourseResult result);
char *getLetterGrade(CourseResult result);
double calculateGPA(CourseResult results[], int n_results);
double calculateExpectedCGPA(double current_cgpa, double completed_credits,
                             double expected_gpa, double future_credits);

#endif