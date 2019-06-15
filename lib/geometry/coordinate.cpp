#include <geometry/coordinate.hpp>

namespace geometry
{

template <int dimensions>
Coordinate<dimensions>::Coordinate()
{

}

template <int dimensions>
Coordinate<dimensions>::Coordinate(const Coordinate<dimensions>& coordinate) :
container_(coordinate.container_)
{

}

template class Coordinate<2>;
template class Coordinate<3>;

} // namespace geometry
