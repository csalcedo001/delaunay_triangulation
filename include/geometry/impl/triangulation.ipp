#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGULATION_IPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGULATION_IPP_

#include <vector>

#include <geometry/point.hpp>

namespace geometry
{

template <int dimensions, typename Precision>
Triangulation<dimensions, Precision>::Triangulation(const Triangulation<dimensions, Precision> &triangulation)
{
	// TODO : Define copy constructor
}

template <int dimensions, typename Precision>
std::ostream &operator<<(std::ostream &os, const Triangulation<dimensions, Precision> &triangulation)
{
	// TODO : Define delaunay triangulation serialization function

	return os;
}

template <int dimensions, typename Precision>
std::istream &operator>>(std::istream &is, const Triangulation<dimensions, Precision> &triangulation)
{
	// TODO : Define delaunay triangulation deserialization function

	return is;
}

} // namespace geometry

#endif
