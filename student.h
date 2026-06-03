#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Student information structure definition
typedef struct {
    int num;              // Student ID
    char name[20];        // Student Name
    char class[20];       // Class
    char sex[5];          // Gender
    float eng_score;      // English Score
    float c_score;        // C Language Score
    float total;          // Total Score
    float average;        // Average Score
} Student;

#define MAX_STUDENTS 100  // Maximum number of students
#define DATA_FILE "students.dat"  // Data file name

Student students[MAX_STUDENTS];  // Global student array
int student_count = 0;           // Current number of students

#endif
