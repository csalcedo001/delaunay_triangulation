#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_COORDINATE_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_COORDINATE_HPP_

#include <array>

namespace geometry
{

template <int dimensions>
class Coordinate
{
public:
	typedef Coordinate<dimensions> CoordinateClass;
	typedef std::array<int, dimensions> Container;

private:
	Container container_;

public:
	Coordinate();
	Coordinate(const CoordinateClass& coordinate);
	Coordinate(Container coordinate_container);
};

} // namespace geometry

#endif
