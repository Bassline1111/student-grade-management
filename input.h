#ifndef INPUT_H
#define INPUT_H

#include "student.h"
#include "file_ops.h"

// Calculate total and average scores
void calculate_scores(Student *student) {
    student->total = student->eng_score + student->c_score;
    student->average = student->total / 2.0;
}

// Check if student ID already exists
int is_student_number_exists(int num) {
    for (int i = 0; i < student_count; i++) {
        if (students[i].num == num) {
            return 1;  // Exists
        }
    }
    return 0;  // Does not exist
}

// Add student information
void add_student_info() {
    if (student_count >= MAX_STUDENTS) {
        printf("[ERROR] Student count has reached maximum limit (%d)\n", MAX_STUDENTS);
        return;
    }

    char ch[2];
    printf("\n--- Add Student Information ---\n");

    while (1) {
        Student new_student;

        // Input student ID
        printf("Please enter Student ID: ");
        scanf("%d", &new_student.num);
        getchar();  // Remove newline

        // Check if student ID already exists
        if (is_student_number_exists(new_student.num)) {
            printf("[ERROR] This student ID already exists\n");
            continue;
        }

        // Input other information
        printf("Please enter Name: ");
        fgets(new_student.name, sizeof(new_student.name), stdin);
        new_student.name[strcspn(new_student.name, "\n")] = 0;  // Remove newline

        printf("Please enter Class: ");
        fgets(new_student.class, sizeof(new_student.class), stdin);
        new_student.class[strcspn(new_student.class, "\n")] = 0;

        printf("Please enter Gender (Male/Female): ");
        fgets(new_student.sex, sizeof(new_student.sex), stdin);
        new_student.sex[strcspn(new_student.sex, "\n")] = 0;

        printf("Please enter English Score: ");
        scanf("%f", &new_student.eng_score);

        printf("Please enter C Language Score: ");
        scanf("%f", &new_student.c_score);
        getchar();  // Remove newline

        // Calculate total and average scores
        calculate_scores(&new_student);

        // Add to array
        students[student_count++] = new_student;
        printf("[SUCCESS] Student information added\n");

        // Ask if continue adding
        printf("Continue adding student information? (y/n): ");
        fgets(ch, sizeof(ch), stdin);
        if (ch[0] != 'y' && ch[0] != 'Y') {
            break;
        }
    }

    // Save to file
    save_students_to_file();
}

#endif
