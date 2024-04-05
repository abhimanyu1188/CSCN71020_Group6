#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

// Function to classify a triangle based on its side lengths
TriangleType classifyTriangle(int side1, int side2, int side3) {
    // Check if any side length is zero or negative
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        return NotATriangle;
    }
    // Check if all sides are equal
    else if (side1 == side2 && side1 == side3) {
        return Equilateral;
    }
    // Check if at least two sides are equal
    else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2)) {
        return Isosceles;
    }
    else {
        return Scalene;
    }
}

// Function to calculate the internal angles of a triangle
void calculateTriangleAngles(int side1, int side2, int side3, double* angle1, double* angle2, double* angle3) {
    // Check if the triangle is valid
    if (classifyTriangle(side1, side2, side3) == NotATriangle) {
        // Set angles to NaN (not a number) if triangle is not valid
        *angle1 = NAN;
        *angle2 = NAN;
        *angle3 = NAN;
    }
    else {
        *angle1 = acos((pow(side2, 2) + pow(side3, 2) - pow(side1, 2)) / (2.0 * side2 * side3));
        *angle2 = acos((pow(side1, 2) + pow(side3, 2) - pow(side2, 2)) / (2.0 * side1 * side3));
        *angle3 = acos((pow(side1, 2) + pow(side2, 2) - pow(side3, 2)) / (2.0 * side1 * side2));
    }
}

// Function to check if one triangle is inside another triangle
bool isTriangleInsideTriangle(int x1, int y1, int x2, int y2, int x3, int y3,
    int x4, int y4, int x5, int y5, int x6, int y6) {
    // Implement the function to check if one triangle is inside another triangle
    return false; // Placeholder return
}

// Function to check if a point is inside a triangle
bool isPointInsideTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {
    // Implement the function to check if a point is inside a triangle
    return false; // Placeholder return
}
