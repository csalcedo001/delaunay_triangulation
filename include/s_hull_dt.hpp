#ifndef DELAUNAY_TRIANGULATION_S_HULL_DT_HPP_
#define DELAUNAY_TRIANGULATION_S_HULL_DT_HPP_

#include <vector>

#include "base_dt.hpp"

#define S_HULL_DT_DIMENSIONS 2

class SHullDelaunayTriangulation : public BaseDelaunayTriangulation<S_HULL_DT_DIMENSIONS>
{
public:
	typedef std::vector<Point<S_HULL_DT_DIMENSIONS>> PointVector;
private:
	// TODO : Add attribute and method declarations

public:
	SHullDelaunayTriangulation(PointVector point_vector);
};

SHullDelaunayTriangulation::SHullDelaunayTriangulation(PointVector point_vector) :
BaseDelaunayTriangulation(point_vector)
{
	// TODO : Initialize class
}

// TODO : Add method definitions

#endif
