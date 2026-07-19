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

void sortStudentsByCGPA(Student students[], int n_students)
{
    for (int i = 0; i < n_students; i++)
    {
        for (int j = i + 1; j < n_students; j++)
        {
            if (students[j].cgpa > students[i].cgpa)
            {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}