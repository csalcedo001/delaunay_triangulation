#include <geometry/vector.hpp>

namespace geometry
{

template <int dimensions>
Vector<dimensions>::Vector()
{

}

template <int dimensions>
Vector<dimensions>::Vector(const Vector<dimensions>& coordinate) :
container_(coordinate.container_)
{

}

template class Vector<2>;
template class Vector<3>;

} // namespace geometry
