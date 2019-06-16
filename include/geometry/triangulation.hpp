#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGULATION_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGULATION_HPP_

#include <vector>

#include <geometry/point.hpp>

namespace geometry
{

// Declaration

template <int dimensions>
class Triangulation
{
public:
	typedef std::vector<Point<dimensions>> PointVector;

protected:
	PointVector point_vector_;

public:
	Triangulation(PointVector point_vector);
};




// Definition

/* Code goes here */

} // namespace geometry

#endif
