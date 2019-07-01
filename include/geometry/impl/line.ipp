/*
Class for a D-dimensional line

D: Dimensions
id_: Unique line identifier
points_: Line points in D-dimentional space
*/

#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_LINE_IPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_LINE_IPP_

#include <geometry/vector.hpp>

#include <array>
#include <ostream>
#include <istream>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


namespace geometry
{

template <typename Point_>
Line<Point_>::Line()
{
	// TODO : Assign unique id to line
}

template <typename Point_>
Line<Point_>::Line(const Line<Point_> &line)
{
	for (int i = 0; i < 2; ++i) {
		this->points_[i] = line.points_[i];
	}
}

template <typename Point_>
Line<Point_>::Line(const std::array<Point_, 2> points)
: points_(points)
{}

template <typename Point_>	
void Line<Point_>::render() 
{
	auto a_coord = this->points_[0].get_coordinates();
    auto b_coord = this->points_[1].get_coordinates();

	glVertex3f(a_coord[0], a_coord[1], a_coord[2]);
    glVertex3f(b_coord[0], b_coord[1], b_coord[2]);
}

template <typename P_>
std::ostream &operator<<(std::ostream &os, const Line<P_> &line)
{
	os << line.points[0] << " " << line.points[1] << "\n";
	return os;
}

} // namespace geometry

#endif
