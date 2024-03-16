#pragma once

// Function to analyze a rectangle based on its four points
char* analyzeRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

// Function to get the four points of a rectangle from the user
int* getRectanglePoints(int* points);

// Function to calculate the length of a line segment given its endpoints
int calculateLineLength(int x1, int y1, int x2, int y2);
