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
