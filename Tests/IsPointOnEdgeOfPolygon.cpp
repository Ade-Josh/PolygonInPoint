#include "pch.h"
#include "CppUnitTest.h"
#include "../PolygonInPoint/PolygonInPoint.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    /**
     * \brief Класс тестирования функции IsPointOnEdgeOfPolygon
     */
    TEST_CLASS(IsPointOnEdgeOfPolygon)
    {
    public:
        /**
        * \brief точка на грани
        */
        TEST_METHOD(PointIsOnEdge)
        {
            const std::vector<point2d> points = {
                {2, 5}, {5, 5}, {4, 4}, {5, 2}, {2, 2}
            };
            const polygon2d polygon(points);
            const point2d point{2, 4};

            const auto result = is_point_on_edge_of_polygon(polygon, point);

            Assert::AreEqual(true, result);
        }
        /**
        * \brief точка является вершиной
        */
        TEST_METHOD(PointIsVertex)
        {
            const std::vector<point2d> points = {
                {2, 5}, {5, 5}, {4, 4}, {5, 2}, {2, 2}
            };
            const polygon2d polygon(points);
            const point2d point{2, 5};

            const auto result = is_point_on_edge_of_polygon(polygon, point);

            Assert::AreEqual(true, result);
        }

        /**
        * \brief точка находится внутри полигона
        */
        TEST_METHOD(PointIsInsideOfPolygon)
        {
            const std::vector<point2d> points = {
                {2, 5}, {5, 5}, {4, 4}, {5, 2}, {2, 2}
            };
            const polygon2d polygon(points);
            const point2d point{3, 4};

            const auto result = is_point_on_edge_of_polygon(polygon, point);

            Assert::AreEqual(false, result);
        }

        /**
        * \brief точка находится вне полигона
        */
        TEST_METHOD(PointIsOutsideOfPolygon)
        {
            const std::vector<point2d> points = {
                {2, 5}, {5, 5}, {4, 4}, {5, 2}, {2, 2}
            };
            const polygon2d polygon(points);
            const point2d point{2, 1};

            const auto result = is_point_on_edge_of_polygon(polygon, point);

            Assert::AreEqual(false, result);
        }
    };
}
