#ifndef UTILITY_H
#define UTILITY_H

#include <stdlib.h>

// Clear screen function (cross-platform)
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    printf("\n\n");
}

// Pause function
void pause_system() {
    printf("\nPress any key to continue...");
    getchar();
    getchar();
}

#endif
