/*
Class for a triangle

id_: Unique triangle identifier
lines_: Triangle lines
*/

#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGLE_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGLE_HPP_

#include <array>
#include <ostream>
#include <istream>

#include <geometry/vector.hpp>
#include <geometry/line.hpp>

namespace geometry
{

template <int dimensions, typename Precision>
struct Triangle
{
private:
	int id_;
	std::array<Line<dimensions, Precision>, 3> lines_;

public:
	Triangle();
	Triangle(const Triangle<dimensions, Precision> &triangle);
	Triangle(const std::array<Line<dimensions, Precision>, 3> lines);

	void render();

    template <int d, typename P_>
	friend std::ostream &operator<<(std::ostream &os, const Triangle<d, P_> &triangle);
};

} // namespace geometry

#include <geometry/impl/triangle.ipp>

#endif
