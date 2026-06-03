#ifndef STATISTICS_H
#define STATISTICS_H

#include "student.h"
#include "query.h"
#include <math.h>

// Show highest score
void show_max_score() {
    if (student_count == 0) {
        printf("[ERROR] No student data\n");
        return;
    }

    int max_index = 0;
    for (int i = 1; i < student_count; i++) {
        if (students[i].total > students[max_index].total) {
            max_index = i;
        }
    }

    printf("\n--- Student with Highest Score ---\n");
    print_table_header();
    print_student(&students[max_index]);
}

// Score group statistics
void score_group_statistics() {
    if (student_count == 0) {
        printf("[ERROR] No student data\n");
        return;
    }

    float threshold;
    printf("\nPlease enter the threshold score: ");
    scanf("%f", &threshold);
    getchar();

    printf("\n--- Students with Total Score >= %.2f ---\n", threshold);
    print_table_header();
    int count1 = 0;
    for (int i = 0; i < student_count; i++) {
        if (students[i].total >= threshold) {
            print_student(&students[i]);
            count1++;
        }
    }
    printf("Total: %d students\n", count1);

    printf("\n--- Students with Total Score < %.2f ---\n", threshold);
    print_table_header();
    int count2 = 0;
    for (int i = 0; i < student_count; i++) {
        if (students[i].total < threshold) {
            print_student(&students[i]);
            count2++;
        }
    }
    printf("Total: %d students\n", count2);
}

// Class score summary
void class_summary() {
    if (student_count == 0) {
        printf("[ERROR] No student data\n");
        return;
    }

    // Collect all class names
    char classes[MAX_STUDENTS][20];
    int class_count = 0;

    for (int i = 0; i < student_count; i++) {
        int found = 0;
        for (int j = 0; j < class_count; j++) {
            if (strcmp(students[i].class, classes[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(classes[class_count++], students[i].class);
        }
    }

    printf("\n--- Class Score Summary ---\n");
    printf("%-12s%-10s%-10s%-10s%-10s\n", "Class", "Students", "Average", "Highest", "Lowest");
    printf("=====================================================\n");

    for (int i = 0; i < class_count; i++) {
        float sum = 0;
        float max_score = 0;
        float min_score = 200;
        int count = 0;

        for (int j = 0; j < student_count; j++) {
            if (strcmp(students[j].class, classes[i]) == 0) {
                sum += students[j].total;
                if (students[j].total > max_score) {
                    max_score = students[j].total;
                }
                if (students[j].total < min_score) {
                    min_score = students[j].total;
                }
                count++;
            }
        }

        float avg = count > 0 ? sum / count : 0;
        printf("%-12s%-10d%-10.2f%-10.2f%-10.2f\n",
               classes[i], count, avg, max_score, min_score);
    }
}

#endif
