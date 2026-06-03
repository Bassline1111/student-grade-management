#ifndef FILE_OPS_H
#define FILE_OPS_H

#include "student.h"

// Load student data from file
void load_students_from_file() {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (fp == NULL) {
        printf("[INFO] Data file does not exist, will create new file\n");
        return;
    }

    student_count = 0;
    while (fread(&students[student_count], sizeof(Student), 1, fp) == 1) {
        if (student_count < MAX_STUDENTS) {
            student_count++;
        } else {
            printf("[WARNING] Student count exceeds maximum limit %d\n", MAX_STUDENTS);
            break;
        }
    }
    fclose(fp);
    printf("[SUCCESS] Loaded %d student records\n", student_count);
}

// Save student data to file
int save_students_to_file() {
    FILE *fp = fopen(DATA_FILE, "wb");
    if (fp == NULL) {
        printf("[ERROR] Cannot open data file for writing\n");
        return 0;
    }

    int success = 0;
    for (int i = 0; i < student_count; i++) {
        if (fwrite(&students[i], sizeof(Student), 1, fp) == 1) {
            success++;
        }
    }
    fclose(fp);
    printf("[SUCCESS] Saved %d student records\n", success);
    return success == student_count;
}

// Export to CSV file
void export_to_csv() {
    FILE *fp = fopen("students_export.csv", "w");
    if (fp == NULL) {
        printf("[ERROR] Cannot create export file\n");
        return;
    }

    // Write header
    fprintf(fp, "StudentID,Name,Class,Gender,EnglishScore,CScore,TotalScore,AverageScore\n");

    // Write data
    for (int i = 0; i < student_count; i++) {
        fprintf(fp, "%d,%s,%s,%s,%.2f,%.2f,%.2f,%.2f\n",
                students[i].num,
                students[i].name,
                students[i].class,
                students[i].sex,
                students[i].eng_score,
                students[i].c_score,
                students[i].total,
                students[i].average);
    }
    fclose(fp);
    printf("[SUCCESS] Exported to students_export.csv\n");
}

#endif
