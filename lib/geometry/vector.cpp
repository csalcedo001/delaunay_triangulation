#include <geometry/vector.hpp>

namespace geometry
{

template <int dimensions, typename Precision>
Vector<dimensions, Precision>::Vector()
{

}

template <int dimensions, typename Precision>
Vector<dimensions, Precision>::Vector(const Vector<dimensions, Precision>& coordinate) :
	container_(coordinate.container_)
{

}

template class Vector<2, float>;
template class Vector<3, float>;

} // namespace geometry
