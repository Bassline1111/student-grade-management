#ifndef QUERY_H
#define QUERY_H

#include "student.h"

// Print table header
void print_table_header() {
    printf("\n");
    printf("%-8s%-12s%-12s%-8s%-10s%-10s%-10s%-10s\n",
           "ID", "Name", "Class", "Gender", "English", "C Lang", "Total", "Average");
    printf("=====================================================================\n");
}

// Print student information
void print_student(const Student *student) {
    printf("%-8d%-12s%-12s%-8s%-10.2f%-10.2f%-10.2f%-10.2f\n",
           student->num,
           student->name,
           student->class,
           student->sex,
           student->eng_score,
           student->c_score,
           student->total,
           student->average);
}

// Query student information
void query_student_info() {
    if (student_count == 0) {
        printf("[ERROR] No student data\n");
        return;
    }

    printf("\n--- Query Student Information ---\n");
    printf("1. Query by Student ID\n");
    printf("2. Query by Name\n");
    printf("Please select (1-2): ");

    int choice;
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        int num;
        printf("Please enter Student ID: ");
        scanf("%d", &num);
        getchar();

        int found = 0;
        for (int i = 0; i < student_count; i++) {
            if (students[i].num == num) {
                print_table_header();
                print_student(&students[i]);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("[ERROR] Student not found\n");
        }
    } else if (choice == 2) {
        char name[20];
        printf("Please enter Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;

        int found = 0;
        print_table_header();
        for (int i = 0; i < student_count; i++) {
            if (strcmp(students[i].name, name) == 0) {
                print_student(&students[i]);
                found = 1;
            }
        }

        if (!found) {
            printf("[ERROR] Student not found\n");
        }
    } else {
        printf("[ERROR] Invalid selection\n");
    }
}

#endif
