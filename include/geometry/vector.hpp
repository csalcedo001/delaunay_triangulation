#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_VECTOR_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_VECTOR_HPP_

#include <array>

namespace geometry
{

// Declaration

template <int dimensions, typename Precision>
class Vector
{
public:
	typedef std::array<Precision, dimensions> Container;

private:
	Container container_;

public:
	Vector();
	Vector(const Vector<dimensions, Precision>& coordinate);
	Vector(Container coordinate_container);
};




// Definition

template <int dimensions, typename Precision>
Vector<dimensions, Precision>::Vector()
{

}

template <int dimensions, typename Precision>
Vector<dimensions, Precision>::Vector(const Vector<dimensions, Precision>& coordinate) :
	container_(coordinate.container_)
{

}

} // namespace geometry

#endif
