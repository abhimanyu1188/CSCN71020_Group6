#include "pch.h"
#include "CppUnitTest.h"
#include "../PolygonChecker/rectangleSolver.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleSolverTests
{
    TEST_CLASS(RectangleSolverTests)
    {
    public:

        TEST_METHOD(TestRectangleDetection)
        {
            // Arrange
            int x1 = 0, y1 = 0;
            int x2 = 0, y2 = 4;
            int x3 = 3, y3 = 4;
            int x4 = 3, y4 = 0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Rectangle", result);
        }

        TEST_METHOD(TestNonRectangleDetection)
        {
            // Arrange
            int x1 = 0, y1 = 0;
            int x2 = 0, y2 = 4;
            int x3 = 3, y3 = 3;
            int x4 = 3, y4 = 0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Not a rectangle", result);
        }

        TEST_METHOD(TestSquareDetection)
        {
            // Arrange
            int x1 = 0, y1 = 0;
            int x2 = 0, y2 = 4;
            int x3 = 4, y3 = 4;
            int x4 = 4, y4 = 0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Rectangle", result);
        }

        TEST_METHOD(TestNonSquareDetection)
        {
            // Arrange
            int x1 = 0, y1 = 0;
            int x2 = 0, y2 = 4;
            int x3 = 5, y3 = 4;
            int x4 = 5, y4 = 0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Not a rectangle", result);
        }

        TEST_METHOD(TestZeroAreaDetection)
        {
            // Arrange
            int x1 = 0, y1 = 0;
            int x2 = 0, y2 = 2;
            int x3 = 2, y3 = 2;
            int x4 = 2, y4 = 0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Rectangle", result);
        }

        TEST_METHOD(TestFourPointsFunctionality)
        {
            // Arrange
            int x1 = 0, y1 = 0;
            int x2 = 0, y2 = 4;
            int x3 = 4, y3 = 4;
            int x4 = 4, y4 = 0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Rectangle", result);
        }


    };
}
