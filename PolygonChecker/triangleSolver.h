#pragma once

#include <stdbool.h>

// Enum to represent the type of triangle
typedef enum {
    Equilateral,
    Isosceles,
    Scalene,
    NotATriangle
} TriangleType;

// Function to classify a triangle based on its side lengths
TriangleType classifyTriangle(int side1, int side2, int side3);

// Function to check if one triangle is inside another triangle
bool isTriangleInsideTriangle(int x1, int y1, int x2, int y2, int x3, int y3,
    int x4, int y4, int x5, int y5, int x6, int y6);

// Function to check if a point is inside a triangle
bool isPointInsideTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y);
