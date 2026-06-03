#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "menu.h"
#include "file_ops.h"
#include "input.h"
#include "delete.h"
#include "update.h"
#include "query.h"
#include "display.h"
#include "sort.h"
#include "statistics.h"
#include "utility.h"

int main() {
    int choice;

    // System initialization
    load_students_from_file();

    // Main loop
    while (1) {
        display_main_menu();
        printf("Please select function (0-10): ");
        scanf("%d", &choice);
        getchar();  // Remove newline

        switch (choice) {
            case 1:
                add_student_info();
                break;
            case 2:
                delete_student_info();
                break;
            case 3:
                update_student_info();
                break;
            case 4:
                query_student_info();
                break;
            case 5:
                display_all_students();
                break;
            case 6:
                sort_students_info();
                break;
            case 7:
                show_max_score();
                break;
            case 8:
                score_group_statistics();
                break;
            case 9:
                class_summary();
                break;
            case 10:
                export_to_csv();
                break;
            case 0:
                printf("\n[INFO] Thank you for using Student Grade Management System. Goodbye!\n\n");
                return 0;
            default:
                printf("[ERROR] Invalid selection, please try again\n");
                break;
        }

        printf("\n");
    }

    return 0;
}
