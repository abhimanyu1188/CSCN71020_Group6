#include <stdio.h>
#include <stdbool.h>

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
