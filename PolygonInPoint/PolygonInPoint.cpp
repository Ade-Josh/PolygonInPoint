#include "PolygonInPoint.h"

#include <algorithm>
#include <functional>
#include <set>
bool operator==(const polygon2d& first, const polygon2d& second)
{
    if (first.points_count() != second.points_count())
        return false;

    for (int i = 0; i < first.points_count(); i++)
        if (abs(first.points[i].x - second.points[i].x) > 0.01 ||
            abs(first.points[i].y - second.points[i].y) > 0.01)
            return false;

    for (int i = 0; i < first.points_count(); i++)
        if (abs(first.angles[i] - second.angles[i]) > 0.01)
            return false;

    return true;
}

constexpr int point_max_value = 1000;
constexpr int point_min_value = -1000;
const std::string point_max_value_string = std::to_string(point_max_value);
const std::string point_min_value_string = std::to_string(point_min_value);
constexpr int min_point_count = 3;
constexpr int max_point_count = 50;

bool is_point_valid(const point2d point)
{
    return point.x >= point_min_value && point.x <= point_max_value && point.y >= point_min_value && point.y <=
        point_max_value;
}

bool any_points_match(const polygon2d& polygon)
{
    std::set<point2d> visited;

    for (const auto point : polygon.points)
    {
        if (visited.count(point) > 0)
            return true;
        visited.insert(point);
    }

    return false;
}

bool any_polygon_sides_intersect(const polygon2d& polygon)
{
    const int count = polygon.points_count();
    for (int i = 0; i <= count - 2; i++)
    {
        for (int j = 0; j <= count - 2; j++)
        {
            if (two_segments_intersect(polygon.points[i], polygon.points[i + 1],
                                       polygon.points[j], polygon.points[j + 1])
                && i != j && abs(i - j) != 1)
            {
                return true;
            }
        }
    }

    for (int i = 1; i <= count - 3; i++)
    {
        if (two_segments_intersect(polygon.points[0], polygon.points[count - 1],
                                   polygon.points[i], polygon.points[i + 1]))
        {
            return true;
        }
    }

    return false;
}

data_check_result check_data(const polygon2d& polygon, const point2d point)
{
    if (const int count = polygon.points_count(); count < min_point_count || count > max_point_count)
    {
        return {
            false,
            "The number of points must be in the range [" + std::to_string(min_point_count) + "; " + std::to_string(
                max_point_count) + "]"
        };
    }

    if (!is_point_valid(point))
    {
        return {
            false,
            "The coordinates of the point must not exceed the allowed range [" + point_min_value_string + "; " +
            point_max_value_string + "]"
        };
    }

    if (const auto not_valid_point_iter =
            std::find_if(polygon.points.begin(),
                         polygon.points.end(),
                         std::not_fn(is_point_valid));
        not_valid_point_iter != polygon.points.end())
    {
        return {
            false,
            "The coordinates of the polygon's point " + std::to_string(not_valid_point_iter - polygon.points.begin()) +
            " must not exceed the allowed range [" + point_min_value_string + "; " + point_max_value_string + "]"
        };
    }

    if (any_points_match(polygon))
    {
        return {false, "The points of the polygon must not match"};
    }

    if (any_polygon_sides_intersect(polygon))
    {
        return {false, "The polygon sides must not intersect"};
    }

    return {true, ""};
}

bool is_point_on_segment(const point2d first, const point2d last, const point2d p)
{
    const bool is_segment_vertical = first.x == last.x;
    const bool is_segment_horizontal = first.y == last.y;
    if (is_segment_vertical)
    {
        if (first.x == p.x &&
            (first.y >= p.y && p.y >= last.y ||
                last.y >= p.y && p.y >= first.y))
            return true;
    }
    else if (is_segment_horizontal)
    {
        if (first.y == p.y &&
            (first.x >= p.x && p.x >= last.x ||
                last.x >= p.x && p.x >= first.x))
            return true;
    }
    else
    {
        if ((p.x - first.x) * (last.y - first.y) - (p.y - first.y) * (last.x - first.x) == 0 && (first.x <= p.x && p.x
            <= last.x || last.x <= p.x && p.x <= first.x))
            return true;
    }


    return false;
}

bool is_point_on_edge_of_polygon(const polygon2d& polygon, const point2d point)
{
    if (is_point_on_segment(polygon.points[0],
                            polygon.points[polygon.points_count() - 1], point))
        return true;

    for (int i = 0; i < polygon.points_count() - 1; i++)
    {
        if (is_point_on_segment(polygon.points[i], polygon.points[i + 1], point))
            return true;
    }

    return false;
}
