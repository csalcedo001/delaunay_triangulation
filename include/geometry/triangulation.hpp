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

protected:
	PointVector point_vector_;

public:
	Triangulation() = default;
	Triangulation(const Triangulation &triangulation);

	template <int d, typename P>
	friend std::ostream &operator<<(std::ostream &os, const Triangulation<d, P> &triangulation);

	template <int d, typename P>
	friend std::istream &operator>>(std::istream &is, const Triangulation<d, P> &triangulation);
};

} // namespace geometry

#include <geometry/impl/triangulation.ipp>

#endif
