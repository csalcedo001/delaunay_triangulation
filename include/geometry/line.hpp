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


namespace geometry
{

template <typename Point_>
struct Line
{
private:
	int id_;
	std::array<Point_, 2> points_;

public:
	Line();
	Line(const Line<Point_> &line);
	Line(const std::array<Point_, 2> points);

	void render();

    template <typename P_>
	friend std::ostream &operator<<(std::ostream &os, const Line<P_> &line);
};

} // namespace geometry

#include <geometry/impl/line.ipp>

#endif
