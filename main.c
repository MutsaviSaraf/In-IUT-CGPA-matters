#include "course.h"
#include "courseResult.h"
#include "student.h"

int main()
{
    Course cse4107 = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    Course cse4108 = createCourse("CSE 4108", "Structured Programming I Lab", 1.5, 1);

    Student students[2] = {
        createStudent("240041001", "Alice"),
        createStudent("240041002", "Bob")
    };

    addCourseResultToStudent(&students[0], createCompletedCourseResult(&cse4107, 252));
    addCourseResultToStudent(&students[0], createCompletedCourseResult(&cse4108, 135));
    addCourseResultToStudent(&students[1], createCompletedCourseResult(&cse4107, 228));
    addCourseResultToStudent(&students[1], createCompletedCourseResult(&cse4108, 123));

    for (int i = 0; i < 2; i++)
    {
        viewStudent(students[i]);
    }

    return 0;
}