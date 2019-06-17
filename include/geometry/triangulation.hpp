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
	// Triangulation(PointVector point_vector);
};

} // namespace geometry

#include <geometry/impl/triangulation.ipp>

#endif
