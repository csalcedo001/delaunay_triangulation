#ifndef DELAUNAY_TRIANGULATION_S_HULL_DT_HPP_
#define DELAUNAY_TRIANGULATION_S_HULL_DT_HPP_

#include <vector>

#include <geometry/delaunay_triangulation.hpp>
#include <geometry/point.hpp>

#define S_HULL_DT_DIMENSIONS 2

class SHullDelaunayTriangulation : public geometry::DelaunayTriangulation<S_HULL_DT_DIMENSIONS>
{
public:
	typedef std::vector<geometry::Point<S_HULL_DT_DIMENSIONS>> PointVector;
private:
	// TODO : Add attribute and method declarations

public:
	SHullDelaunayTriangulation(PointVector point_vector);
};

SHullDelaunayTriangulation::SHullDelaunayTriangulation(PointVector point_vector) :
geometry::DelaunayTriangulation<S_HULL_DT_DIMENSIONS>(point_vector)
{
	// TODO : Initialize class
}

// TODO : Add method definitions

#endif
