#ifndef STUDENT_H
#define STUDENT_H

#include "courseResult.h"

typedef struct Student
{
    char id[20];
    char name[80];
    CourseResult courseResults[100];
    int n_results;
    double cgpa;
} Student;

Student createStudent(char id[], char name[]);
void addCourseResultToStudent(Student *student, CourseResult result);
void viewStudent(Student student);
void sortStudentsByCGPA(Student students[], int n_students);

#endif