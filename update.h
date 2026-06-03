#ifndef UPDATE_H
#define UPDATE_H

#include "student.h"
#include "display.h"
#include "file_ops.h"
#include "menu.h"
#include "input.h"

// Update student information
void update_student_info() {
    if (student_count == 0) {
        printf("[ERROR] No student data to update\n");
        return;
    }

    display_all_students();

    int num;
    printf("\nPlease enter the Student ID to update: ");
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

    printf("\n--- Update Student Information ---\n");
    printf("Student ID: %d\n", students[found_index].num);
    printf("Name: %s\n", students[found_index].name);
    printf("Class: %s\n", students[found_index].class);
    printf("Gender: %s\n", students[found_index].sex);
    printf("English Score: %.2f\n", students[found_index].eng_score);
    printf("C Language Score: %.2f\n", students[found_index].c_score);

    int choice;
    while (1) {
        choice = display_edit_menu();

        switch (choice) {
            case 1: {
                int new_num;
                printf("Enter new Student ID: ");
                scanf("%d", &new_num);
                getchar();

                // Check if new ID already exists
                int exists = 0;
                for (int i = 0; i < student_count; i++) {
                    if (i != found_index && students[i].num == new_num) {
                        exists = 1;
                        break;
                    }
                }

                if (exists) {
                    printf("[ERROR] New Student ID already exists\n");
                } else {
                    students[found_index].num = new_num;
                    printf("[SUCCESS] Student ID updated\n");
                }
                break;
            }
            case 2: {
                char name[20];
                printf("Enter new Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                strcpy(students[found_index].name, name);
                printf("[SUCCESS] Name updated\n");
                break;
            }
            case 3: {
                char class[20];
                printf("Enter new Class: ");
                fgets(class, sizeof(class), stdin);
                class[strcspn(class, "\n")] = 0;
                strcpy(students[found_index].class, class);
                printf("[SUCCESS] Class updated\n");
                break;
            }
            case 4: {
                char sex[5];
                printf("Enter new Gender: ");
                fgets(sex, sizeof(sex), stdin);
                sex[strcspn(sex, "\n")] = 0;
                strcpy(students[found_index].sex, sex);
                printf("[SUCCESS] Gender updated\n");
                break;
            }
            case 5: {
                float score;
                printf("Enter new English Score: ");
                scanf("%f", &score);
                getchar();
                students[found_index].eng_score = score;
                calculate_scores(&students[found_index]);
                printf("[SUCCESS] English Score updated\n");
                break;
            }
            case 6: {
                float score;
                printf("Enter new C Language Score: ");
                scanf("%f", &score);
                getchar();
                students[found_index].c_score = score;
                calculate_scores(&students[found_index]);
                printf("[SUCCESS] C Language Score updated\n");
                break;
            }
            case 0:
                printf("[SUCCESS] Modification completed\n");
                save_students_to_file();
                return;
            default:
                printf("[ERROR] Invalid selection, please try again\n");
        }
    }
}

#endif
