#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

// Function to analyze a triangle based on its side lengths
char* analyzeTriangle(int side1, int side2, int side3) {
    char* result = ""; // Variable to store the result

    // Check if any side length is zero or negative
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        result = "Not a triangle"; // If any side is zero or negative, it's not a triangle
    }
    // Check if all sides are equal
    else if (side1 == side2 && side1 == side3) {
        result = "Equilateral triangle"; // If all sides are equal, it's an equilateral triangle
    }
    // Check if at least two sides are equal
    else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2)) {
        result = "Isosceles triangle"; // If two sides are equal but the third is different, it's an isosceles triangle
    }
    else {
        result = "Scalene triangle"; // If all sides are different, it's a scalene triangle
    }

    return result; // Return the result
}

// Function to check if one triangle is inside another triangle
bool isTriangleInsideTriangle(int x1, int y1, int x2, int y2, int x3, int y3,
    int x4, int y4, int x5, int y5, int x6, int y6) {
    // Check if the three vertices of the second triangle are inside the first triangle
    bool point1Inside = isPointInsideTriangle(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5);
    bool point2Inside = isPointInsideTriangle(x1, y1, x2, y2, x3, y3, x6, y6, x4, y4);
    bool point3Inside = isPointInsideTriangle(x1, y1, x2, y2, x3, y3, x6, y6, x5, y5);

    // Return true if all three points are inside, otherwise false
    return (point1Inside && point2Inside && point3Inside);
}

// Function to check if a point is inside a triangle
bool isPointInsideTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {
    // Calculate the area of the triangle formed by the three vertices
    float totalArea = calculateArea(x1, y1, x2, y2, x3, y3);

    // Calculate the area of the three smaller triangles formed by the point and each pair of vertices
    float area1 = calculateArea(x, y, x2, y2, x3, y3);
    float area2 = calculateArea(x1, y1, x, y, x3, y3);
    float area3 = calculateArea(x1, y1, x2, y2, x, y);

    // If the sum of the areas of the smaller triangles is equal to the area of the larger triangle, the point is inside
    return (totalArea == area1 + area2 + area3);
}

// Function to calculate the area of a triangle given its vertices
float calculateArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
