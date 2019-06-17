#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_POINT_IPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_POINT_IPP_

#include <array>
#include <ostream>
#include <istream>

#include <geometry/vector.hpp>

// Class for a D-dimensional point
// 
// D: Dimensions
// id_: Unique point identifier
// coordinates_: Point coordinates in D-dimentional space
// 

namespace geometry
{

template <int dimensions, typename Precision>
Point<dimensions, Precision>::Point()
{
	// TODO : Assign unique id to point
}

template <int dimensions, typename Precision>
Point<dimensions, Precision>::Point(const Point<dimensions, Precision> &point)
{
	// TODO : Define copy constructor. Copy same id
}

} // namespace geometry

#endif
