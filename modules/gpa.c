#include "gpa.h"

const double gradeBoundaries[] = {80, 75, 70, 65, 60, 55, 50, 45, 40};
const double gradePoints[] = {4.00, 3.75, 3.50, 3.25, 3.00, 2.75, 2.50, 2.25, 2.00};
const char *gradeLetters[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "D"};

double getPercentage(CourseResult result)
{
    double full_marks = result.course->credit * 100.0;
    if (full_marks <= 0.0) return 0.0;
    return (result.marks / full_marks) * 100.0;
}

double getGradePoint(CourseResult result)
{
    double percentage = getPercentage(result);

    if (!result.completed) return 0.0;

    for (int i = 0; i < 9; i++)
    {
        if (percentage >= gradeBoundaries[i]) return gradePoints[i];
    }

    return 0.0;
}

char *getLetterGrade(CourseResult result)
{
    double percentage = getPercentage(result);

    if (!result.completed) return "I";

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
        if (!results[i].completed) continue;
        weighted_points += getGradePoint(results[i]) * results[i].course->credit;
        total_credits += results[i].course->credit;
    }

    if (total_credits == 0.0) return 0.0;
    return weighted_points / total_credits;
}

double calculateExpectedCGPA(double current_cgpa, double completed_credits,
                             double expected_gpa, double future_credits)
{
    double total_credits = completed_credits + future_credits;
    if (total_credits <= 0.0) return 0.0;
    return ((current_cgpa * completed_credits) +
            (expected_gpa * future_credits)) / total_credits;
}