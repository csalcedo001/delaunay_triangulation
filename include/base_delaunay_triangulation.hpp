#ifndef DT_BASE_DELAUNAY_TRIANGULATION_HPP_
#define DT_BASE_DELAUNAY_TRIANGULATION_HPP_

#include <vector>

#include "point.hpp"

/*
* D: Dimensions
* point_vector_: Vector of D-dimentional points
*/ 
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
