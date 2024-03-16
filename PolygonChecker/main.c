#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int side = 0;

int main() {
    bool continueProgram = true;
    while (continueProgram) {
        printWelcome();

        int shapeChoice = printShapeMenu();

        switch (shapeChoice) {
        case 1:
            printf_s("Triangle selected.\n");
            int triangleSides[3] = { 0, 0, 0 };
            int* triangleSidesPtr = getTriangleSides(triangleSides);
            char* triangleResult = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
            printf_s("%s\n", triangleResult);
            break;
        case 2:
            printf_s("Rectangle selected.\n");
            int points[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
            int* pointsPtr = getRectanglePoints(points);
            char* rectangleResult = analyzeRectangle(pointsPtr[0], pointsPtr[1], pointsPtr[2], pointsPtr[3], pointsPtr[4], pointsPtr[5], pointsPtr[6], pointsPtr[7]);
            printf_s("%s\n", rectangleResult);
            break;
        case 0:
            continueProgram = false;
            break;
        default:
            printf_s("Invalid value entered.\n");
            break;
        }
    }
    return 0;
}

void printWelcome() {
    printf_s("\n");
    printf_s(" **********************\n");
    printf_s("**     Welcome to     **\n");
    printf_s("**   Polygon Checker  **\n");
    printf_s(" **********************\n");
}

int printShapeMenu() {
    printf_s("1. Triangle\n");
    printf_s("2. Rectangle\n");
    printf_s("0. Exit\n");

    int shapeChoice;

    printf_s("Enter number: ");
    scanf_s("%d", &shapeChoice);

    return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
    printf_s("Enter the three sides of the triangle: ");
    for (int i = 0; i < 3; i++) {
        scanf_s("%d", &triangleSides[i]);
    }
    return triangleSides;
}
