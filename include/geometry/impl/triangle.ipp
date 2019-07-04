/*
Class for a triangle

id_: Unique triangle identifier
lines_: Triangle lines
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
		this->lines_[i] = line.lines_[i];
	}
}

template <int dimensions, typename Precision>
Triangle<dimensions, Precision>::Triangle(const std::array<Line<dimensions, Precision>, 3> lines)
: lines_(lines)
{}

template <int dimensions, typename Precision>	
void Triangle<dimensions, Precision>::render() 
{
	for (auto &i : this->lines_) 
    {
        i.render();
    }
}

template <int d, typename P_>
std::ostream &operator<<(std::ostream &os, const Triangle<d, P_> &line)
{
	os << line.lines_[0] << " " << line.lines_[1] << " " << line.lines_[2] << "\n";
	return os;
}

} // namespace geometry

#endif
