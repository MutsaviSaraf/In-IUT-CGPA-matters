#include <stdio.h>
#include <string.h>
#include "course.h"

const char null_course_code[] = "NULL";

Course createCourse(char code[], char name[], double credit, int semester)
{
    Course course;

    strcpy(course.code, code);
    strcpy(course.name, name);
    course.credit = credit;
    course.semester = semester;

    return course;
}

int countCoursesBeforeNull(Course courses[], int n_courses)
{
    int count = 0;

    while (count < n_courses)
    {
        if (strcmp(courses[count].code, null_course_code) == 0) return count;
        count++;
    }

    return count;
}

void viewCourse(Course course)
{
    printf("Code: %s\n", course.code);
    printf("Name: %s\n", course.name);
    printf("Credit: %.1f\n", course.credit);
    printf("Semester: %d\n", course.semester);
}