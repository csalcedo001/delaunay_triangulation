/*
Class for a Triangulation

point_vector_: Vector of points
triangle_vector_: Vector of triangles
*/

#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGULATION_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGULATION_HPP_

#include <algorithm>
#include <vector>

#include <geometry/point.hpp>
#include <geometry/line.hpp>
#include <geometry/triangle.hpp>


namespace geometry
{

template <int dimensions, typename Precision>
class Triangulation
{
public:
	typedef Point<dimensions, Precision> Point_;
	typedef Line<dimensions, Precision> Line_;
	typedef Triangle<dimensions, Precision> Triangle_;
	typedef std::vector<Point_*> PointVector;
	typedef std::vector<Line_*> LineVector;
	typedef std::vector<Triangle_*> TriangleVector;

protected:
	PointVector point_vector_;

public:
	Triangulation() = default;
	Triangulation(PointVector point_vector);

	TriangleVector incremental_triangulation();
	TriangleVector randomized_incremental_triangulation();

	bool circumcircle(Triangle_* triangle, Point_* point, 
        Precision &xcentre, Precision &ycentre, Precision &radio);
	static bool point_comparison(Point_* p1, Point_* p2);

	PointVector get_points();
};

} // namespace geometry

#include <geometry/impl/triangulation.ipp>

#endif
