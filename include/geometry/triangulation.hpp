#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGULATION_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGULATION_HPP_

#include <vector>

#include <geometry/point.hpp>

namespace geometry
{

template <int dimensions, typename Precision>
class Triangulation
{
public:
	typedef std::vector<Point<dimensions, Precision>> PointVector;
	typedef std::vector<Line<Point<dimensions, Precision>>> LineVector;
protected:
	PointVector point_vector_;
	LineVector line_vector_;

public:
	Triangulation() = default;
	Triangulation(PointVector point_vector);
	Triangulation(const Triangulation &triangulation);

	virtual void triangulate();

	PointVector get_points();
	LineVector get_lines();

	template <int d, typename P>
	friend std::ostream &operator<<(std::ostream &os, const Triangulation<d, P> &triangulation);

	template <int d, typename P>
	friend std::istream &operator>>(std::istream &is, const Triangulation<d, P> &triangulation);
};

} // namespace geometry

#include <geometry/impl/triangulation.ipp>

#endif
