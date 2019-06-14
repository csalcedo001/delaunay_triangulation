#ifndef DELAUNAY_TRIANGULATION_BASE_DT_HPP_
#define DELAUNAY_TRIANGULATION_BASE_DT_HPP_

#include <vector>

#include "point.hpp"

// Base class for a Delaunay Triangulation algorithm
// 
// D: Dimensions
// point_vector_: Vector of D-dimensional points
//  

template <int D>
class BaseDelaunayTriangulation
{
public:
	typedef std::vector<Point<D>> PointVector;

protected:
	PointVector point_vector_;

public:
	BaseDelaunayTriangulation(PointVector point_vector);
};

#endif
