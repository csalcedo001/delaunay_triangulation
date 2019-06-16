#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_VECTOR_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_VECTOR_HPP_

#include <array>

namespace geometry
{

template <int dimensions, typename >
class Vector
{
public:
	typedef std::array<int, dimensions> Container;

private:
	Container container_;

public:
	Vector();
	Vector(const Vector<dimensions>& coordinate);
	Vector(Container coordinate_container);
};

} // namespace geometry

#endif
