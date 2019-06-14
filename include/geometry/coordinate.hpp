#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_COORDINATE_H_
#define DELAUNAY_TRIANGULATION_GEOMETRY_COORDINATE_H_

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


template <int dimensions>
Coordinate<dimensions>::Coordinate()
{

}

template <int dimensions>
Coordinate<dimensions>::Coordinate(const Coordinate<dimensions>& coordinate) :
container_(coordinate.container_)
{

}

} // namespace geometry

#endif
