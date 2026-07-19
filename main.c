#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"

int main()
{
    Course courses[1000];
    CourseResult results[1000];
    int n_courses = 0;

    courses[n_courses++] = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    courses[n_courses++] = createCourse("CSE 4108", "Structured Programming I Lab", 1.5, 1);
    courses[n_courses++] = createCourse("CSE 4203", "Discrete Mathematics", 3.0, 2);
    courses[n_courses++] = createCourse("CSE 4205", "Digital Logic Design", 3.0, 2);

    for (int i = 0; i < n_courses; i++)
    {
        double marks;
        printf("Marks for %s: ", courses[i].name);
        scanf("%lf", &marks);
        results[i] = createCourseResult(&courses[i], marks);
    }

    sortCourseResultsBySemester(results, n_courses);

    for (int semester = 1; semester <= 8; semester++)
    {
        CourseResult semesterResults[100];
        int n_semester_results;

        filterCourseResultsBySemester(results, n_courses, semester, semesterResults);
        n_semester_results = countCourseResultsBeforeNull(semesterResults, 100);

        if (n_semester_results > 0)
        {
            printf("Semester %d GPA: %.2f\n",
                   semester, calculateGPA(semesterResults, n_semester_results));
        }
    }

    printf("CGPA: %.2f\n", calculateGPA(results, n_courses));

    return 0;
}