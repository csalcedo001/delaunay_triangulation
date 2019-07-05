/*
Class for a triangle

id_: Unique triangle identifier
points_: Triangle points
*/

#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGLE_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGLE_HPP_

#include <array>
#include <ostream>
#include <istream>

#include <geometry/vector.hpp>
#include <geometry/point.hpp>

namespace geometry
{

template <int dimensions, typename Precision>
struct Triangle
{
	int id_;
	std::array<Point<dimensions, Precision>*, 3> points_;
	bool checked = false;

	Triangle();
	Triangle(const Triangle<dimensions, Precision> &triangle);
	Triangle(const std::array<Point<dimensions, Precision>*, 3> points);

	void render();

	Triangle<dimensions, Precision>& operator=(const Triangle<dimensions, Precision> &triangle);

    template <int d, typename P_>
	friend std::ostream &operator<<(std::ostream &os, const Triangle<d, P_> &triangle);
};

} // namespace geometry

#include <geometry/impl/triangle.ipp>

#endif
