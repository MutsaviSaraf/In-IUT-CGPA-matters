#ifndef COURSE_H
#define COURSE_H

typedef struct Course
{
    char code[16];
    char name[100];
    double credit;
    int semester;
} Course;

extern const char null_course_code[];

Course createCourse(char code[], char name[], double credit, int semester);
int countCoursesBeforeNull(Course courses[], int n_courses);
void viewCourse(Course course);

#endif