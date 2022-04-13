#pragma once
#include <stdexcept>
#include <string>
#include <vector>
#include <istream>
#include <tuple>

struct point2d
{
    int x;
    int y;
};

/**
 * \brief Оператор сравнения на равенство структуры Unit
 * \param[in] first Левый операнд сравнения
 * \param[in] second Правый операнд сравнения
 * \return Признак сравненния
 */
inline bool operator==(const point2d first, const point2d second)
{
    return first.x == second.x && first.y == second.y;
}

/**
 * \brief Оператор сравнения на равенство структуры Unit
 * \param[in] first Левый операнд сравнения
 * \param[in] second Правый операнд сравнения
 * \return Массив строк
 */
inline bool operator<(const point2d first, const point2d second)
{
    return std::tie(first.x, first.y) < std::tie(second.x, second.y);
}

/**
 * \brief Оператор сравнения на равенство структуры Unit
 * \param[in] first Левый операнд сравнения
 * \param[in] second Правый операнд сравнения
 * \return Признак сравненния
 */
inline bool operator!=(const point2d first, const point2d second)
{
    return !(first == second);
}
/**
 * \brief Оператор сравнения на равенство структуры Unit
 * \param[in] in Левый операнд сравнения
 * \param[in] point Правый операнд сравнения
 * \return левю операнд
 */
inline std::istream& operator>>(std::istream& in, point2d& point)
{
    in >> point.x >> point.y;
    return in;
}

struct polygon2d
{
    explicit polygon2d(std::vector<point2d> points);
    explicit polygon2d(std::vector<double> angles);

    std::vector<point2d> points;
    std::vector<double> angles;

    void push_back(point2d tmp);

    [[nodiscard]] int points_count() const;

    void push_back(double angle);

    friend bool operator==(const polygon2d& first, const polygon2d& second);
};

struct ray2d
{
    ray2d(const int x, const int y) : x{x}, y{y}
    {
    }


    int x{};
    int y{};
    double angle{};
    double sin{2};
    double cos{2};
    double tg{};

    friend bool operator==(ray2d first, ray2d second);
};

/**
 * \brief результат проверки данных
 */
struct data_check_result
{
    bool is_correct;
    std::string reason;
};

/**
 * \brief ошибка проверки данных
 */
struct data_check_error final : std::invalid_argument
{
    using std::invalid_argument::invalid_argument;
};

bool is_point_inside_polygon(std::vector<point2d> polygon_points, point2d point);
data_check_result check_data(const polygon2d& polygon, point2d point);
bool is_point_on_edge_of_polygon(const polygon2d& polygon, struct point2d point);
int count_intersects(const polygon2d& polygon, ray2d ray);
bool ray_intersects_segment(point2d first, point2d last, ray2d ray);
bool two_segments_intersect(point2d first1, point2d last1, point2d first2, point2d last2);
void calculate_angles_for_polygon(polygon2d& polygon, struct point2d point);
void calculate_angle_of_rotation(ray2d& ray, const polygon2d& polygon);
bool is_point_on_segment(point2d first, point2d last, point2d p);
