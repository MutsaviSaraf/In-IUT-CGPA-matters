gcc -I modules tests/test_course.c modules/course.c -o test_course.exe
.\test_course.exe

gcc -I modules tests/test_course_result.c modules/course.c modules/courseResult.c -o test_course_result.exe
.\test_course_result.exe

gcc -I modules tests/test_gpa.c modules/course.c modules/courseResult.c modules/gpa.c -o test_gpa.exe
.\test_gpa.exe

gcc -I modules tests/test_student.c modules/course.c modules/courseResult.c modules/gpa.c modules/student.c -o test_student.exe
.\test_student.exe