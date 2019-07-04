/*
Class for a Triangulation

id_: Unique triangulation identifier
point_vector_: Vector of points
line_vector_: Vector of lines
triangle_vector_: Vector of triangles
*/

#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGULATION_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGULATION_HPP_

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
	typedef std::vector<Point<dimensions, Precision>> PointVector;
	typedef std::vector<Line<dimensions, Precision>> LineVector;
	typedef std::vector<Triangle<dimensions, Precision>> TriangleVector;

protected:
	PointVector point_vector_;
	LineVector line_vector_;
	TriangleVector triangle_vector_;

public:
	Triangulation() = default;
	Triangulation(PointVector point_vector);
	Triangulation(const Triangulation &triangulation);

	virtual void triangulate();

	PointVector get_points();
	LineVector get_lines();
	TriangleVector get_triangles();

	template <int d, typename P>
	friend std::ostream &operator<<(std::ostream &os, const Triangulation<d, P> &triangulation);

	template <int d, typename P>
	friend std::istream &operator>>(std::istream &is, const Triangulation<d, P> &triangulation);
};

} // namespace geometry

#include <geometry/impl/triangulation.ipp>

#endif
