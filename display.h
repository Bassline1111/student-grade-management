#ifndef DISPLAY_H
#define DISPLAY_H

#include "student.h"
#include "query.h"

// Display all student information
void display_all_students() {
    if (student_count == 0) {
        printf("[ERROR] No student data\n");
        return;
    }

    print_table_header();
    for (int i = 0; i < student_count; i++) {
        print_student(&students[i]);
    }
    printf("\nTotal: %d students\n", student_count);
}

#endif
