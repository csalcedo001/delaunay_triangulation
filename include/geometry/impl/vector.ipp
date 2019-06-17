#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_VECTOR_IPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_VECTOR_IPP_

#include <array>

namespace geometry
{

template <int dimensions, typename Precision>
Vector<dimensions, Precision>::Vector(const Vector<dimensions, Precision>& coordinate) :
	container_(coordinate.container_)
{

}

template <int dimensions, typename Precision>
std::ostream &operator<<(std::ostream &os, const Vector<dimensions, Precision> &vector)
{
	// TODO : Define vector serialization function

	return os;
}

template <int dimensions, typename Precision>
std::istream &operator>>(std::istream &is, const Vector<dimensions, Precision> &vector)
{
	// TODO : Define vector deserialization function

	return is;
}

} // namespace geometry

#endif
