#include <stdio.h>
#include <string.h>
#include "student.h"
#include "gpa.h"

Student createStudent(char id[], char name[])
{
    Student student;
    strcpy(student.id, id);
    strcpy(student.name, name);
    student.n_results = 0;
    student.cgpa = 0.0;
    return student;
}

void addCourseResultToStudent(Student *student, CourseResult result)
{
    student->courseResults[student->n_results] = result;
    student->n_results = student->n_results + 1;
    student->cgpa = calculateGPA(student->courseResults, student->n_results);
}

void viewStudent(Student student)
{
    printf("ID: %s\n", student.id);
    printf("Name: %s\n", student.name);
    printf("CGPA: %.2f\n", student.cgpa);
}