#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h> // Include stdlib.h for memory allocation

#include "rectangleSolver.h"

// Function to calculate the length of a line segment
int calculateLineLength(int x1, int y1, int x2, int y2);

// Function to analyze a set of points and determine if they form a rectangle
char* analyzeRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    // Assuming the points are entered in order, connecting points 1 & 2, 2 & 3, 3 & 4, and 4 & 1 will form the rectangle
    int line1 = calculateLineLength(x1, y1, x2, y2); // Calculate length of side 1
    int line2 = calculateLineLength(x2, y2, x3, y3); // Calculate length of side 2
    int line3 = calculateLineLength(x3, y3, x4, y4); // Calculate length of side 3
    int line4 = calculateLineLength(x4, y4, x1, y1); // Calculate length of side 4

    // Check if the sides form a rectangle
    if (line1 == line3 && line2 == line4) {
        int perimeter = line1 + line2 + line3 + line4; // Calculate perimeter
        int area = line1 * line2; // Calculate area

        // Allocate memory for the result string
        char* result = (char*)malloc(50 * sizeof(char));
        if (result == NULL) {
            printf_s("Memory allocation failed!\n");
            exit(1);
        }

        // Format result string
        sprintf_s(result, 50, "Perimeter: %d, Area: %d", perimeter, area);

        return result; // Return result
    }
    else {
        return "Not a rectangle"; // Return result
    }
}

// Function to calculate the length of a line segment
int calculateLineLength(int x1, int y1, int x2, int y2) {
    return (int)sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // Calculate and return length
}

// Function to get user input for rectangle points
int* getRectanglePoints(int* points) {
    printf_s("Enter the x and y coordinates for each of the four points of the rectangle:\n");
    for (int i = 0; i < 8; i += 2) {
        // Prompt for point coordinates
        printf_s("Point %d (x, y): ", (i / 2) + 1);

        // Read point coordinates from user
        while (scanf_s("%d %d", &points[i], &points[i + 1]) != 2) {
            // Clear input buffer
            while (getchar() != '\n');
            // Prompt user again
            printf_s("Invalid input. Please enter valid coordinates: ");
        }
    }
    return points; // Return updated points array
}
