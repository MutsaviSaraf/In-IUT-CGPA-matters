#include <stdio.h>
#include <string.h>
#include "course.h"
#include "courseResult.h"
#include "student.h"

int testStudentId()
{
    Student student = createStudent("240041001", "Alice");
    return strcmp(student.id, "240041001") == 0;
}

int testStudentName()
{
    Student student = createStudent("240041001", "Alice");
    return strcmp(student.name, "Alice") == 0;
}

int testStudentInitialCGPA()
{
    Student student = createStudent("240041001", "Alice");
    return student.cgpa == 0.0;
}

int testAddCourseResultUpdatesCGPA()
{
    Course course = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    Student student = createStudent("240041001", "Alice");

    addCourseResultToStudent(&student, createCompletedCourseResult(&course, 252));
    return student.cgpa == 4.00;
}

int main()
{
    printf("Student module tests\n");
    int passed = 0;
    int total = 0;

    total++;
    if (testStudentId()) passed++;
    total++;
    if (testStudentName()) passed++;
    total++;
    if (testStudentInitialCGPA()) passed++;
    total++;
    if (testAddCourseResultUpdatesCGPA()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}