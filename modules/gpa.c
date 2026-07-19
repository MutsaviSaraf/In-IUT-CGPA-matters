#include <string.h>
#include "gpa.h"

const double gradeBoundaries[] = {80, 75, 70, 65, 60, 55, 50, 45, 40};
const double gradePoints[] = {4.00, 3.75, 3.50, 3.25, 3.00, 2.75, 2.50, 2.25, 2.00};
const char *gradeLetters[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "D"};

// Defined first so other functions recognize it
double getPercentage(CourseResult result)
{
    double full_marks = result.course->credit * 100.0;
    if (full_marks <= 0.0) return 0.0;
    return (result.marks / full_marks) * 100.0;
}

double getGradePoint(CourseResult result)
{
    // Using your null_course_code logic instead of .completed
    if (strcmp(result.course->code, null_course_code) == 0) return 0.0;

    double percentage = getPercentage(result);
    for (int i = 0; i < 9; i++)
    {
        if (percentage >= gradeBoundaries[i]) return gradePoints[i];
    }
    return 0.0;
}

char *getLetterGrade(CourseResult result)
{
    // Using your null_course_code logic instead of .completed
    if (strcmp(result.course->code, null_course_code) == 0) return "I";

    double percentage = getPercentage(result);
    for (int i = 0; i < 9; i++)
    {
        if (percentage >= gradeBoundaries[i]) return (char *) gradeLetters[i];
    }
    return "F";
}

double calculateGPA(CourseResult results[], int n_results)
{
    double weighted_points = 0.0;
    double total_credits = 0.0;

    for (int i = 0; i < n_results; i++)
    {
        // Using your null_course_code logic instead of .completed
        if (strcmp(results[i].course->code, null_course_code) == 0) continue;
        
        weighted_points += getGradePoint(results[i]) * results[i].course->credit;
        total_credits += results[i].course->credit;
    }

    if (total_credits == 0.0) return 0.0;
    return weighted_points / total_credits;
}