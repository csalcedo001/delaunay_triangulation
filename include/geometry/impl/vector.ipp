#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_VECTOR_IPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_VECTOR_IPP_

#include <array>

namespace geometry
{

template <int dimensions, typename Precision>
Vector<dimensions, Precision>::Vector(const Vector<dimensions, Precision> &vector) :
	container_(vector.container_)
{

}

} // namespace geometry

#endif
