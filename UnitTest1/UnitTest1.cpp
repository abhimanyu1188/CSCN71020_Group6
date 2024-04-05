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
            TriangleType result = classifyTriangle(side1, side2, side3);

            // Assert
            Assert::AreEqual(Equilateral, result);
        }

        TEST_METHOD(TestIsoscelesTriangle)
        {
            // Arrange
            int side1 = 5;
            int side2 = 5;
            int side3 = 6;

            // Act
            TriangleType result = classifyTriangle(side1, side2, side3);

            // Assert
            Assert::AreEqual(Isosceles, result);
        }

        TEST_METHOD(TestScaleneTriangle)
        {
            // Arrange
            int side1 = 3;
            int side2 = 4;
            int side3 = 5;

            // Act
            TriangleType result = classifyTriangle(side1, side2, side3);

            // Assert
            Assert::AreEqual(Scalene, result);
        }

        TEST_METHOD(TestNotATriangle)
        {
            // Arrange
            int side1 = 1;
            int side2 = 2;
            int side3 = 10;

            // Act
            TriangleType result = classifyTriangle(side1, side2, side3);

            // Assert
            Assert::AreEqual(NotATriangle, result);
        }

        TEST_METHOD(TestCalculateTriangleAngles)
        {
            // Arrange
            int side1 = 3;
            int side2 = 4;
            int side3 = 5;
            double angle1, angle2, angle3;

            // Act
            calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);

            // Assert
            Assert::AreEqual(0.6435011087932844, angle1, 0.0001);
            Assert::AreEqual(0.9272952180016122, angle2, 0.0001);
            Assert::AreEqual(1.5707963267948966, angle3, 0.0001);
        }
    };
}
