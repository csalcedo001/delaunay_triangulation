#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_DELAUNAY_TRIANGULATION_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_DELAUNAY_TRIANGULATION_HPP_

#include <vector>

#include <geometry/triangulation.hpp>

namespace geometry
{

// Declaration

template <int dimensions>
class DelaunayTriangulation : public Triangulation<dimensions>
{
public:
	typedef std::vector<Point<dimensions>> PointVector;

protected:
	PointVector point_vector_;

public:
	DelaunayTriangulation(PointVector point_vector);
};




// Definition

} // namespace geometry

#endif
