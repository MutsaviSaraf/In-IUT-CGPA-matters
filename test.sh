#!/bin/sh
gcc -I modules tests/test_course.c modules/course.c -o test_course.out
chmod +x test_course.out
./test_course.out