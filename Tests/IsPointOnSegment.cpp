#include "pch.h"
#include "CppUnitTest.h"
#include "../PolygonInPoint/PolygonInPoint.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    /**
     * \brief Класс тестирования функции IsPointOnSegment
     */
    TEST_CLASS(IsPointOnSegment)
    {
    public:
        /**
         * \brief точка на вершине
         */
        TEST_METHOD(PointOnVertex)
        {
            const point2d first{1, 1};
            const point2d last{4, 2};
            const point2d point{1, 1};

            const bool result = is_point_on_segment(first, last, point);

            Assert::AreEqual(true, result);
        }

        /**
         * \brief точка на вертикали
         */
        TEST_METHOD(PointOnVertical)
        {
            const point2d first{2, 2};
            const point2d last{2, 5};
            const point2d point{2, 3};

            const bool result = is_point_on_segment(first, last, point);

            Assert::AreEqual(true, result);
        }

        /**
         * \brief точка на горизонтали
         */
        TEST_METHOD(PointOnHorizontal)
        {
            const point2d first{1, 1};
            const point2d last{4, 1};
            const point2d point{2, 1};

            const bool result = is_point_on_segment(first, last, point);

            Assert::AreEqual(true, result);
        }

        /**
         * \brief точка на сегменте
         */
        TEST_METHOD(PointOnSegment)
        {
            const point2d first{3, 2};
            const point2d last{6, 5};
            const point2d point{4, 3};

            const bool result = is_point_on_segment(first, last, point);

            Assert::AreEqual(true, result);
        }

        /**
         * \brief точка ниже горизонтальной стороны
         */
        TEST_METHOD(BelowHorizontalSide)
        {
            const point2d first{1, 1};
            const point2d last{4, 2};
            const point2d point{2, 0};

            const bool result = is_point_on_segment(first, last, point);

            Assert::AreEqual(false, result);
        }

        /**
         * \brief правая горизонтальная сторона
         */
        TEST_METHOD(RightHorizontalSide)
        {
            const point2d first{1, 1};
            const point2d last{4, 2};
            const point2d point{6, 1};

            const bool result = is_point_on_segment(first, last, point);

            Assert::AreEqual(false, result);
        }

        /**
         * \brief выше вертикали
         */
        TEST_METHOD(AboveVertical)
        {
            const point2d first{2, 2};
            const point2d last{2, 5};
            const point2d point{2, 6};

            const bool result = is_point_on_segment(first, last, point);

            Assert::AreEqual(false, result);
        }

        /**
         * \brief левый вертикальный
         */
        TEST_METHOD(LeftVertical)
        {
            const point2d first{2, 2};
            const point2d last{2, 5};
            const point2d point{1, 3};

            const bool result = is_point_on_segment(first, last, point);

            Assert::AreEqual(false, result);
        }

        /**
         * \brief вне квадрата сегмента
         */
        TEST_METHOD(OutsideOfSegmentSquare)
        {
            const point2d first{3, 2};
            const point2d last{6, 5};
            const point2d point{9, 0};

            const bool result = is_point_on_segment(first, last, point);

            Assert::AreEqual(false, result);
        }
    };
}
