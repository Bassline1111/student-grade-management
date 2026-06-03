#ifndef MENU_H
#define MENU_H

#include <stdio.h>

// Display main menu
void display_main_menu() {
    printf("\n\n");
    printf("\t\t=====================================================\n");
    printf("\t\t|                                                   |\n");
    printf("\t\t|    *** Student Grade Management System ***        |\n");
    printf("\t\t|              (Optimized Version v2.0)             |\n");
    printf("\t\t|                                                   |\n");
    printf("\t\t|         1.  Add Student Information                |\n");
    printf("\t\t|         2.  Delete Student Information             |\n");
    printf("\t\t|         3.  Update Student Information             |\n");
    printf("\t\t|         4.  Query Student Information              |\n");
    printf("\t\t|         5.  Display All Students                   |\n");
    printf("\t\t|         6.  Sort Students by Score                 |\n");
    printf("\t\t|         7.  Show Highest Score                     |\n");
    printf("\t\t|         8.  Score Group Statistics                 |\n");
    printf("\t\t|         9.  Class Score Summary                    |\n");
    printf("\t\t|        10.  Export to CSV                          |\n");
    printf("\t\t|         0.  Exit System                            |\n");
    printf("\t\t|                                                   |\n");
    printf("\t\t|===================================================|\n");
}

// Display sort menu
int display_sort_menu() {
    int choice;
    printf("\n--- Sort Options ---\n");
    printf("1. Sort by Student ID (Ascending)\n");
    printf("2. Sort by English Score (Ascending)\n");
    printf("3. Sort by C Language Score (Ascending)\n");
    printf("4. Sort by Total Score (Ascending)\n");
    printf("5. Sort by Average Score (Ascending)\n");
    printf("Please select (1-5): ");
    scanf("%d", &choice);
    return choice;
}

// Display edit menu
int display_edit_menu() {
    int choice;
    printf("\n--- Select Information to Modify ---\n");
    printf("1. Student ID\n");
    printf("2. Name\n");
    printf("3. Class\n");
    printf("4. Gender\n");
    printf("5. English Score\n");
    printf("6. C Language Score\n");
    printf("0. Finish Modification\n");
    printf("Please select (0-6): ");
    scanf("%d", &choice);
    return choice;
}

#endif
