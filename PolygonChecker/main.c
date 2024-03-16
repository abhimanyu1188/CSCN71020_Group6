// Including necessary header files
#include <stdio.h>
#include <stdbool.h>

// Including custom header files
#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

// Global variable declaration
int side = 0;

// Main function
int main() {
    // Variable to control program execution
    bool continueProgram = true;

    // Main program loop
    while (continueProgram) {
        // Printing welcome message
        printWelcome();

        // Getting user's shape choice
        int shapeChoice = printShapeMenu();

        // Switching based on user's choice
        switch (shapeChoice) {
        case 1:
            // Triangle selected
            printf_s("Triangle selected.\n");
            // Initializing array to store triangle sides
            int triangleSides[3] = { 0, 0, 0 };
            // Getting triangle sides from user
            int* triangleSidesPtr = getTriangleSides(triangleSides);
            // Analyzing triangle and printing result
            char* triangleResult = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
            printf_s("%s\n", triangleResult);
            break;
        case 2:
            // Rectangle selected
            printf_s("Rectangle selected.\n");
            // Initializing array to store rectangle points
            int points[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
            // Getting rectangle points from user
            int* pointsPtr = getRectanglePoints(points);
            // Analyzing rectangle and printing result
            char* rectangleResult = analyzeRectangle(pointsPtr[0], pointsPtr[1], pointsPtr[2], pointsPtr[3], pointsPtr[4], pointsPtr[5], pointsPtr[6], pointsPtr[7]);
            printf_s("%s\n", rectangleResult);
            break;
        case 0:
            // Exiting program
            continueProgram = false;
            break;
        default:
            // Handling invalid input
            printf_s("Invalid value entered.\n");
            break;
        }
    }
    return 0;
}

// Function to print welcome message
void printWelcome() {
    printf_s("\n");
    printf_s(" **********************\n");
    printf_s("**     Welcome to     **\n");
    printf_s("**   Polygon Checker  **\n");
    printf_s(" **********************\n");
}

// Function to print shape selection menu and get user's choice
int printShapeMenu() {
    // Printing menu options
    printf_s("1. Triangle\n");
    printf_s("2. Rectangle\n");
    printf_s("0. Exit\n");

    int shapeChoice;

    // Getting user input
    printf_s("Enter number: ");
    scanf_s("%d", &shapeChoice);

    return shapeChoice;
}

// Function to get triangle sides from user
int* getTriangleSides(int* triangleSides) {
    printf_s("Enter the three sides of the triangle: ");
    // Getting user input for triangle sides
    for (int i = 0; i < 3; i++) {
        scanf_s("%d", &triangleSides[i]);
    }
    return triangleSides;
}
