#ifndef DELETE_H
#define DELETE_H

#include "student.h"
#include "display.h"
#include "file_ops.h"

// Delete student information
void delete_student_info() {
    if (student_count == 0) {
        printf("[ERROR] No student data to delete\n");
        return;
    }

    display_all_students();

    int num;
    printf("\nPlease enter the Student ID to delete: ");
    scanf("%d", &num);
    getchar();

    // Find student
    int found_index = -1;
    for (int i = 0; i < student_count; i++) {
        if (students[i].num == num) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("[ERROR] Student not found\n");
        return;
    }

    // Confirm deletion
    char ch[2];
    printf("Confirm to delete this student? (y/n): ");
    fgets(ch, sizeof(ch), stdin);

    if (ch[0] == 'y' || ch[0] == 'Y') {
        // Delete operation: move elements forward
        for (int i = found_index; i < student_count - 1; i++) {
            students[i] = students[i + 1];
        }
        student_count--;
        printf("[SUCCESS] Student information deleted\n");
        save_students_to_file();
    } else {
        printf("[INFO] Deletion cancelled\n");
    }
}

#endif
