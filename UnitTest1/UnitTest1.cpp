#include "pch.h"
#include "CppUnitTest.h"
#include "../PolygonChecker/main.h" 
#include "../PolygonChecker/triangleSolver.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestEquilateralTriangle)
        {
            // Arrange
            int side1 = 5;
            int side2 = 5;
            int side3 = 5;

            // Act
            char* result = analyzeTriangle(side1, side2, side3);

            // Assert
            Assert::AreEqual("Equilateral triangle", result);
        }

        TEST_METHOD(TestIsoscelesTriangle)
        {
            // Arrange
            int side1 = 5;
            int side2 = 5;
            int side3 = 6;

            // Act
            char* result = analyzeTriangle(side1, side2, side3);

            // Assert
            Assert::AreEqual("Isosceles triangle", result);
        }

        TEST_METHOD(TestTriangleInsideAngle)
        {
            // Arrange
            int side1 = 3;
            int side2 = 4;
            int side3 = 5;

            // Act
            char* result = analyzeTriangle(side1, side2, side3);

            // Assert
            Assert::AreEqual("Triangle with acute inside angles", result);
        }
    };
}
