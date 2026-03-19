#include <stdio.h>

// Define enum for colors
typedef enum {
    RED,
    YELLOW,
    GREEN,
    COLOR_COUNT  // Helper to count enum items
} Color;

int main() {
    // Array of enum names as strings
    const char *colorNames[] = {"RED", "YELLOW", "GREEN"};

    // Loop through enum values
    for (int i = 0; i < COLOR_COUNT; i++) {
        printf("%s=%d\n", colorNames[i], i);
    }

    return 0;
}