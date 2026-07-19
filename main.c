#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"

void showMenu()
{
    printf("1. Add Course\n");
    printf("2. Edit Course\n");
    printf("3. Delete Course\n");
    printf("4. View Courses\n");
    printf("5. Add Course Result\n");
    printf("6. Edit Course Result\n");
    printf("7. Delete Course Result\n");
    printf("8. View Marksheet\n");
    printf("9. Exit\n");
    printf("Enter Choice: ");
}

void addCourse(Course courses[], int *n_courses)
{
    char code[16];
    char name[100];
    double credit;
    int semester;

    printf("Course Code: ");
    scanf("%s", code);
    printf("Course Name: ");
    scanf(" %[^\n]", name);
    printf("Credit: ");
    scanf("%lf", &credit);
    printf("Semester: ");
    scanf("%d", &semester);

    courses[*n_courses] = createCourse(code, name, credit, semester);
    *n_courses = *n_courses + 1;
}

void viewCourses(Course courses[], int n_courses)
{
    for (int i = 0; i < n_courses; i++)
    {
        printf("%d. ", i + 1);
        viewCourse(courses[i]);
    }
}

void editCourse(Course courses[], int n_courses)
{
    int course_no;
    char code[16];
    char name[100];
    double credit;
    int semester;

    printf("Course Number: ");
    scanf("%d", &course_no);

    if (course_no < 1 || course_no > n_courses) return;

    printf("Course Code: ");
    scanf("%s", code);
    printf("Course Name: ");
    scanf(" %[^\n]", name);
    printf("Credit: ");
    scanf("%lf", &credit);
    printf("Semester: ");
    scanf("%d", &semester);

    courses[course_no - 1] = createCourse(code, name, credit, semester);
}

void deleteCourse(Course courses[], int *n_courses,
                  CourseResult results[], int *n_results)
{
    int course_no;

    printf("Course Number: ");
    scanf("%d", &course_no);

    if (course_no < 1 || course_no > *n_courses) return;

    Course *deleted = &courses[course_no - 1];
    int kept = 0;

    for (int i = 0; i < *n_results; i++)
    {
        if (results[i].course == deleted) continue;
        if (results[i].course > deleted) results[i].course--;
        results[kept] = results[i];
        kept++;
    }
    *n_results = kept;

    for (int i = course_no - 1; i < *n_courses - 1; i++)
    {
        courses[i] = courses[i + 1];
    }
    *n_courses = *n_courses - 1;
}

void addCourseResult(Course courses[], int n_courses,
                     CourseResult results[], int *n_results)
{
    int course_no;
    int completed;
    double marks;

    printf("Course Number: ");
    scanf("%d", &course_no);

    if (course_no < 1 || course_no > n_courses) return;

    printf("%s: %s Completed?\n",
           courses[course_no - 1].code, courses[course_no - 1].name);
    printf("1. YES.\n");
    printf("2. NO.\n");
    printf("Enter Choice: ");
    scanf("%d", &completed);

    if (completed == 1)
    {
        printf("Marks for %s: ", courses[course_no - 1].name);
        scanf("%lf", &marks);
        results[*n_results] = createCompletedCourseResult(&courses[course_no - 1], marks);
    }
    else
    {
        results[*n_results] = createIncompleteCourseResult(&courses[course_no - 1]);
    }

    *n_results = *n_results + 1;
}

void editCourseResult(CourseResult results[], int n_results)
{
    int result_no;
    int completed;
    double marks;

    printf("Course Result Number: ");
    scanf("%d", &result_no);

    if (result_no < 1 || result_no > n_results) return;

    Course *course = results[result_no - 1].course;

    printf("%s: %s Completed?\n", course->code, course->name);
    printf("1. YES.\n");
    printf("2. NO.\n");
    printf("Enter Choice: ");
    scanf("%d", &completed);

    if (completed == 1)
    {
        printf("Marks for %s: ", course->name);
        scanf("%lf", &marks);
        results[result_no - 1] = createCompletedCourseResult(course, marks);
    }
    else
    {
        results[result_no - 1] = createIncompleteCourseResult(course);
    }
}

void deleteCourseResult(CourseResult results[], int *n_results)
{
    int result_no;

    printf("Course Result Number: ");
    scanf("%d", &result_no);

    if (result_no < 1 || result_no > *n_results) return;

    for (int i = result_no - 1; i < *n_results - 1; i++)
    {
        results[i] = results[i + 1];
    }
    *n_results = *n_results - 1;
}

void viewMarksheet(CourseResult results[], int n_results)
{
    sortCourseResultsBySemester(results, n_results);

    for (int i = 0; i < n_results; i++)
    {
        printf("%d. ", i + 1);
        viewCourseResult(results[i]);
    }

    for (int semester = 1; semester <= 8; semester++)
    {
        CourseResult semesterResults[100];
        int n_semester_results;

        filterCourseResultsBySemester(results, n_results, semester, semesterResults);
        n_semester_results = countCourseResultsBeforeNull(semesterResults, 100);

        if (n_semester_results > 0)
        {
            printf("Semester %d GPA: %.2f\n",
                   semester, calculateGPA(semesterResults, n_semester_results));
        }
    }

    printf("CGPA: %.2f\n", calculateGPA(results, n_results));
}

int main()
{
    Course courses[1000];
    CourseResult results[1000];
    int n_courses = 0;
    int n_results = 0;
    int choice = 0;

    while (choice != 9)
    {
        showMenu();
        scanf("%d", &choice);

        if (choice == 1) addCourse(courses, &n_courses);
        else if (choice == 2) editCourse(courses, n_courses);
        else if (choice == 3) deleteCourse(courses, &n_courses, results, &n_results);
        else if (choice == 4) viewCourses(courses, n_courses);
        else if (choice == 5) addCourseResult(courses, n_courses, results, &n_results);
        else if (choice == 6) editCourseResult(results, n_results);
        else if (choice == 7) deleteCourseResult(results, &n_results);
        else if (choice == 8) viewMarksheet(results, n_results);
    }

    return 0;
}