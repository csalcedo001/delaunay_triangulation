/*
Class for a D-dimensional line

D: Dimensions
id_: Unique line identifier
points_: Line points in D-dimentional space
*/

#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_LINE_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_LINE_HPP_

#include <array>
#include <ostream>
#include <istream>

#include <geometry/vector.hpp>
#include <geometry/point.hpp>


namespace geometry
{

template <int dimensions, typename Precision>
struct Line
{
	int id_ = 1;
	std::array<Point<dimensions, Precision>, 2> points_;

	Line();
	Line(const Line<dimensions, Precision> &line);
	Line(const std::array<Point<dimensions, Precision>, 2> points);

	void render();

	Line<dimensions, Precision>& operator=(const Line<dimensions, Precision> &line);

    template <int d, typename P_>
	friend std::ostream &operator<<(std::ostream &os, const Line<d, P_> &line);
};

} // namespace geometry

#include <geometry/impl/line.ipp>

#endif
