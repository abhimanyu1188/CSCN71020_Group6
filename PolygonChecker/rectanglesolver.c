#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "rectangleSolver.h"

int calculateLineLength(int x1, int y1, int x2, int y2);

char* analyzeRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    // Assuming the points are entered in order, connecting points 1 & 2, 2 & 3, 3 & 4, and 4 & 1 will form the rectangle
    int line1 = calculateLineLength(x1, y1, x2, y2);
    int line2 = calculateLineLength(x2, y2, x3, y3);
    int line3 = calculateLineLength(x3, y3, x4, y4);
    int line4 = calculateLineLength(x4, y4, x1, y1);

    if (line1 == line3 && line2 == line4) {
        int perimeter = line1 + line2 + line3 + line4;
        int area = line1 * line2;
        printf("Perimeter: %d\n", perimeter);
        printf("Area: %d\n", area);
        return "Rectangle";
    }
    else {
        return "Not a rectangle";
    }
}

int calculateLineLength(int x1, int y1, int x2, int y2) {
    return (int)sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int* getRectanglePoints(int* points) {
    printf("Enter the x and y coordinates for each of the four points of the rectangle:\n");
    for (int i = 0; i < 8; i += 2) {
        printf("Point %d (x, y): ", (i / 2) + 1);
        scanf_s("%d %d", &points[i], &points[i + 1]); // Changed scanf to scanf_s
    }
    return points;
}
