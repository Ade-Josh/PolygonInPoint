#include "pch.h"

#include <CppUnitTest.h>
#include <CppUnitTestAssert.h>
#include <vector>
#include "../PolygonInPoint/PolygonInPoint.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::string_literals;

namespace Tests
{
    /**
     * \brief Класс тестирования функции CheckData
     */
    TEST_CLASS(CheckData)
    {
    public:
        /**
        * \brief все правильно
        */
        TEST_METHOD(EverythingIsCorrect)
        {
            const std::vector<point2d> points = {
                {2, 2}, {4, 5}, {6, 2}, {4, 3}
            };
            const polygon2d polygon(points);
            const point2d point{1, 1};

            const auto [is_correct, reason] = check_data(polygon, point);

            Assert::AreEqual(true, is_correct);
            Assert::AreEqual(""s, reason);
        }

        /**
        * \brief слишком мало очков
        */
        TEST_METHOD(TooFewPoints)
        {
            const std::vector<point2d> points = {
                {2, 2}, {4, 5}
            };
            const polygon2d polygon(points);
            const point2d point{1, 1};

            const auto [is_correct, reason] = check_data(polygon, point);

            Assert::AreEqual(false, is_correct);
            Assert::AreEqual("The number of points must be in the range [3; 50]"s, reason);
        }

        /**
        * \brief слишком много очков
        */
        TEST_METHOD(TooMuchPoints)
        {
            const std::vector<point2d> points = {
                {2, 2}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5},
                {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5},
                {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5},
                {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}, {4, 5}
            };
            const polygon2d polygon(points);
            const point2d point{1, 1};

            const auto [is_correct, reason] = check_data(polygon, point);

            Assert::AreEqual(false, is_correct);
            Assert::AreEqual("The number of points must be in the range [3; 50]"s, reason);
        }

        /**
         * \brief два очка совпадают
         */
        TEST_METHOD(TwoPointsMatch)
        {
            const std::vector<point2d> points = {
                {2, 2}, {2, 2}, {6, 2}, {4, 3}
            };
            const polygon2d polygon(points);
            const point2d point{1, 1};

            const auto [is_correct, reason] = check_data(polygon, point);

            Assert::AreEqual(false, is_correct);
            Assert::AreEqual("The points of the polygon must not match"s, reason);
        }

        /**
         * \brief стороны полигона пересекаются
         */
        TEST_METHOD(PolygonSidesIntersect)
        {
            const std::vector<point2d> points = {
                {2, 2}, {6, 5}, {2, 5}, {6, 2}
            };
            const polygon2d polygon(points);
            const point2d point{1, 1};

            const auto [is_correct, reason] = check_data(polygon, point);

            Assert::AreEqual(false, is_correct);
            Assert::AreEqual("The polygon sides must not intersect"s, reason);
        }

        /**
         * \brief целевая точка находится вне досягаемости
         */
        TEST_METHOD(TargetPointIsOutOfRange)
        {
            const std::vector<point2d> points = {
                {2, 2}, {4, 5}, {6, 2}, {4, 3}
            };
            const polygon2d polygon(points);
            const point2d point{1, 1500};

            const auto [is_correct, reason] = check_data(polygon, point);

            Assert::AreEqual(false, is_correct);
            Assert::AreEqual("The coordinates of the point must not exceed the allowed range [-1000; 1000]"s, reason);
        }

        /**
        * \brief одна из точек многоугольника находится вне диапазонаи
        */
        TEST_METHOD(OneOfPolygonPointsIsOutOfRange)
        {
            const std::vector<point2d> points = {
                {2, 2}, {4, 56460561}, {6, 2}, {4, 3}
            };
            const polygon2d polygon(points);
            const point2d point{1, 1};

            const auto [is_correct, reason] = check_data(polygon, point);

            Assert::AreEqual(false, is_correct);
            Assert::AreEqual(
                "The coordinates of the polygon's point 2 must not exceed the allowed range [-1000; 1000]"s, reason);
        }
    };
}
