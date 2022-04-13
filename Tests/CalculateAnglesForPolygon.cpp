#include "pch.h"

#include <CppUnitTest.h>
#include <CppUnitTestAssert.h>
#include <vector>
#include "../PolygonInPoint/PolygonInPoint.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    /**
     * \brief Класс тестирования функции CalculateAngleForPolygon
     */
    TEST_CLASS(CalculateAnglesForPolygon)
    {
    public:
        /**
         * \brief один из рассчитанных углов  нулю
         */
        TEST_METHOD(OneOfCalculatedAnglesIsZero)
        {
            const std::vector<point2d> points = {
                {3, 8}, {6, 1}, {3, 3}, {4, 4}
            };
            polygon2d polygon(points);
            const point2d point{3, 4};


            polygon2d expectedPolygon(points);
            expectedPolygon.angles = {90, -45, -90, 0};

            calculate_angles_for_polygon(polygon, point);

            Assert::IsTrue(expectedPolygon == polygon);
        }

        /**
         * \brief Два из рассчитанных углов  нулю
         */
        TEST_METHOD(TwoOfCalculatedAnglesAreZero)
        {
            const std::vector<point2d> points = {
                {4, 2}, {5, 5}, {7, 2}, {2, 1}
            };
            polygon2d polygon(points);
            const point2d point{2, 2};


            polygon2d expectedPolygon(points);
            expectedPolygon.angles = {0, 45, 0, -90};

            calculate_angles_for_polygon(polygon, point);

            Assert::IsTrue(expectedPolygon == polygon);
        }

        /**
         * \brief Некоьорые рассчитанных углов  нулю
         */
        TEST_METHOD(SomeOfCalculatedAnglesAreZero)
        {
            const std::vector<point2d> points = {
                {2, 6}, {6, 4}, {8, 4}, {2, 2}, {4, 4}
            };
            polygon2d polygon(points);
            const point2d point{2, 4};

            polygon2d expectedPolygon(points);
            expectedPolygon.angles = {90, 0, 0, -90, 0};

            calculate_angles_for_polygon(polygon, point);

            Assert::IsTrue(expectedPolygon == polygon);
        }

        /**
         * \brief один из рассчитанных углов равен 90
         */
        TEST_METHOD(OneOfCalculatedAnglesIs90)
        {
            const std::vector<point2d> points = {
                {2, 6}, {6, 4}, {2, 2}, {4, 4}
            };
            polygon2d polygon(points);
            const point2d point{2, 4};


            polygon2d expectedPolygon(points);
            expectedPolygon.angles = {90, 0, -90, 0};

            calculate_angles_for_polygon(polygon, point);

            Assert::IsTrue(expectedPolygon == polygon);
        }

        /**
         * \brief один из рассчитанных углов равен 100
         */
        TEST_METHOD(OneOfCalculatedAnglesIs180)
        {
            const std::vector<point2d> points = {
                {4, 4}, {4, 6}, {2, 4}, {4, 2}, {6, 3}
            };
            polygon2d polygon(points);
            const point2d point{6, 4};


            polygon2d expectedPolygon(points);
            expectedPolygon.angles = {180, 135, 180, -135, -90};

            calculate_angles_for_polygon(polygon, point);

            Assert::IsTrue(expectedPolygon == polygon);
        }

        /**
         * \brief один из рассчитанных углов равен 270
         */
        TEST_METHOD(OneOfCalculatedAnglesIs270)
        {
            const std::vector<point2d> points = {
                {2, 6}, {6, 4}, {2, 2}, {4, 4}
            };
            polygon2d polygon(points);
            const point2d point{2, 4};


            polygon2d expectedPolygon(points);
            expectedPolygon.angles = {90, 0, -90, 0};

            calculate_angles_for_polygon(polygon, point);

            Assert::IsTrue(expectedPolygon == polygon);
        }

        /**
         * \brief расчетный угол находится в 1-й четверти
         */
        TEST_METHOD(CalculatedAnglesLocatedIn1stQuarter)
        {
            const std::vector<point2d> points = {
                {3, 3}, {6, 6}, {8, 3}, {6, 4}
            };
            polygon2d polygon(points);
            const point2d point{2, 2};


            polygon2d expectedPolygon(points);
            expectedPolygon.angles = {45, 45, 9.464, 26.565};

            calculate_angles_for_polygon(polygon, point);

            Assert::IsTrue(expectedPolygon == polygon);
        }

        /**
         * \brief расчетный угол находится в 2-й четверти
         */
        TEST_METHOD(CalculatedAnglesLocatedIn2ndQuarter)
        {
            const std::vector<point2d> points = {
                {2, 7}, {6, 9}, {5, 7}, {5, 4}
            };
            polygon2d polygon(points);
            const point2d point{7, 2};


            polygon2d expectedPolygon(points);
            expectedPolygon.angles = {135, 98.132, 111.801, 135};

            calculate_angles_for_polygon(polygon, point);

            Assert::IsTrue(expectedPolygon == polygon);
        }

        /**
         * \brief расчетный угол находится в 3-й четверти
         */
        TEST_METHOD(CalculatedAnglesLocatedIn3rdQuarter)
        {
            const std::vector<point2d> points = {
                {1, 7}, {4, 6}, {7, 7}, {3, 3}
            };
            polygon2d polygon(points);
            const point2d point{8, 8};


            polygon2d expectedPolygon(points);
            expectedPolygon.angles = {-171.87, -153.435, -135, -135};

            calculate_angles_for_polygon(polygon, point);

            Assert::IsTrue(expectedPolygon == polygon);
        }

        /**
         * \brief расчетный угол находится в 4-й четверти
         */
        TEST_METHOD(CalculatedAnglesLocatedIn4thQuarter)
        {
            const std::vector<point2d> points = {
                {3, 7}, {7, 3}, {3, 2}, {5, 4}
            };
            polygon2d polygon(points);
            const point2d point{2, 8};


            polygon2d expectedPolygon(points);
            expectedPolygon.angles = {-45, -45, -80.538, -53.13};

            calculate_angles_for_polygon(polygon, point);

            Assert::IsTrue(expectedPolygon == polygon);
        }

        /**
         * \brief расчетный угол расположен во всех четвертях
         */
        TEST_METHOD(CalculatedAnglesLocatedInAllQuarters)
        {
            const std::vector<point2d> points = {
                {7, 6}, {6, 4}, {7, 2}, {5, 3},
                {3, 2}, {4, 4}, {3, 6}, {5, 5}
            };
            polygon2d polygon(points);
            const point2d point{5, 4};


            polygon2d expectedPolygon(points);
            expectedPolygon.angles = {45, 0, -45, -90, -135, 180, 135, 90};

            calculate_angles_for_polygon(polygon, point);

            Assert::IsTrue(expectedPolygon == polygon);
        }
    };
}
