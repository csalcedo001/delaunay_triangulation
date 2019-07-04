/*
Class for a triangle

id_: Unique triangle identifier
points_: Triangle points
*/

#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGLE_IPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGLE_IPP_

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

template <int dimensions, typename Precision>
Triangle<dimensions, Precision>::Triangle()
{
	// TODO : Assign unique id to triangle
}

template <int dimensions, typename Precision>
Triangle<dimensions, Precision>::Triangle(const Triangle<dimensions, Precision> &triangle)
{
	for (int i = 0; i < 3; ++i) {
		this->points_[i] = triangle.points_[i];
	}
}

template <int dimensions, typename Precision>
Triangle<dimensions, Precision>::Triangle(const std::array<Point<dimensions, Precision>, 3> points)
: points_(points)
{}

template <int dimensions, typename Precision>	
void Triangle<dimensions, Precision>::render() 
{
	auto a_coord = this->points_[0].coordinates_;
    auto b_coord = this->points_[1].coordinates_;
	auto c_coord = this->points_[2].coordinates_;

	glVertex3f(a_coord[0], a_coord[1], a_coord[2]);
    glVertex3f(b_coord[0], b_coord[1], b_coord[2]);

	glVertex3f(a_coord[0], a_coord[1], a_coord[2]);
    glVertex3f(c_coord[0], c_coord[1], c_coord[2]);

    glVertex3f(b_coord[0], b_coord[1], b_coord[2]);
	glVertex3f(c_coord[0], c_coord[1], c_coord[2]);
}

template <int d, typename P_>
std::ostream &operator<<(std::ostream &os, const Triangle<d, P_> &triangle)
{
	os << triangle.lines_[0] << " " << triangle.lines_[1] << " " << triangle.lines_[2] << "\n";
	return os;
}

} // namespace geometry

#endif
