#include "pch.h"

#include <CppUnitTest.h>
#include <CppUnitTestAssert.h>
#include <vector>
#include "../PolygonInPoint/PolygonInPoint.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    /**
     * \brief Класс тестирования функции IsPointInsidePolygon
     */
    TEST_CLASS(IsPointInsidePolygon)
    {
    public:
        /**
         * \brief точка соответствует вершине
         */
        TEST_METHOD(PointMatchesVertex)
        {
            const std::vector<point2d> points = {
                {1, 1}, {4, 4}, {6, 1}, {4, 2}
            };
            const point2d point{4, 4};

            Assert::IsTrue(is_point_inside_polygon(points, point));
        }

        /**
         * \brief точка находится сбоку
         */
        TEST_METHOD(PointIsOnSide)
        {
            const std::vector<point2d> points = {
                {1, 1}, {4, 4}, {6, 1}, {4, 2}
            };
            const point2d point{3, 3};

            Assert::IsTrue(is_point_inside_polygon(points, point));
        }

        /**
         * \brief точка выше полигона
         */
        TEST_METHOD(PointIsAbovePolygon)
        {
            const std::vector<point2d> points = {
                {1, 1}, {4, 4}, {6, 1}, {4, 2}
            };
            const point2d point{1, 5};

            Assert::IsFalse(is_point_inside_polygon(points, point));
        }

        /**
         * \brief точка под полигона
         */
        TEST_METHOD(PointIsBelowPolygon)
        {
            const std::vector<point2d> points = {
                {1, 1}, {4, 4}, {6, 1}, {4, 2}
            };
            const point2d point{0, 0};

            Assert::IsFalse(is_point_inside_polygon(points, point));
        }

        /**
         * \brief точка точка находится справа от полигона
         */
        TEST_METHOD(PointIsOnTheRightToPolygon)
        {
            const std::vector<point2d> points = {
                {1, 1}, {4, 4}, {6, 1}, {4, 2}
            };
            const point2d point{6, 5};

            Assert::IsFalse(is_point_inside_polygon(points, point));
        }

        /**
         * \brief точка точка находится слева от полигона
         */
        TEST_METHOD(PointIsOnTheLeftToPolygon)
        {
            const std::vector<point2d> points = {
                {1, 1}, {4, 4}, {6, 1}, {4, 2}
            };
            const point2d point{1, 2};

            Assert::IsFalse(is_point_inside_polygon(points, point));
        }

        /**
         * \brief сложный Полигон и точка внутри
         */
        TEST_METHOD(ComplexPolygonAndPointInside)
        {
            const std::vector<point2d> points = {
                {2, 2}, {2, 5}, {4, 4}, {6, 5}, {6, 2}, {4, 1}
            };
            const point2d point{4, 3};

            Assert::IsTrue(is_point_inside_polygon(points, point));
        }
    };
}
