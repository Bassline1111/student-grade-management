#ifndef SORT_H
#define SORT_H

#include "student.h"
#include "menu.h"
#include "query.h"

// Swap two students
void swap_students(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// Sort by student ID
void sort_by_num() {
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            if (students[i].num > students[j].num) {
                swap_students(&students[i], &students[j]);
            }
        }
    }
}

// Sort by English score
void sort_by_eng_score() {
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            if (students[i].eng_score > students[j].eng_score) {
                swap_students(&students[i], &students[j]);
            }
        }
    }
}

// Sort by C language score
void sort_by_c_score() {
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            if (students[i].c_score > students[j].c_score) {
                swap_students(&students[i], &students[j]);
            }
        }
    }
}

// Sort by total score
void sort_by_total() {
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            if (students[i].total > students[j].total) {
                swap_students(&students[i], &students[j]);
            }
        }
    }
}

// Sort by average score
void sort_by_average() {
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            if (students[i].average > students[j].average) {
                swap_students(&students[i], &students[j]);
            }
        }
    }
}

// Sort students information
void sort_students_info() {
    if (student_count == 0) {
        printf("[ERROR] No student data\n");
        return;
    }

    int choice = display_sort_menu();

    switch (choice) {
        case 1:
            sort_by_num();
            printf("[SUCCESS] Sorted by Student ID in ascending order\n");
            break;
        case 2:
            sort_by_eng_score();
            printf("[SUCCESS] Sorted by English Score in ascending order\n");
            break;
        case 3:
            sort_by_c_score();
            printf("[SUCCESS] Sorted by C Language Score in ascending order\n");
            break;
        case 4:
            sort_by_total();
            printf("[SUCCESS] Sorted by Total Score in ascending order\n");
            break;
        case 5:
            sort_by_average();
            printf("[SUCCESS] Sorted by Average Score in ascending order\n");
            break;
        default:
            printf("[ERROR] Invalid selection\n");
            return;
    }

    print_table_header();
    for (int i = 0; i < student_count; i++) {
        print_student(&students[i]);
    }
}

#endif
