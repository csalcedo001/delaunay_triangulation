#include "geometry/point.hpp"

#include <array>
#include <ostream>
#include <istream>

#include "geometry/coordinate.hpp"

namespace geometry
{

template <int dimensions>
Point<dimensions>::Point()
{
	// TODO : Assign unique id to point
}

template <int dimensions>
Point<dimensions>::Point(const Point<dimensions> &point)
{
	// TODO : Define copy constructor. Copy same id
}

template <int dimensions>
std::ostream &operator<<(std::ostream &os, const Point<dimensions> &point)
{
	// TODO : Define point output function

	return os;
}

template <int dimensions>
std::istream &operator>>(std::istream &is, const Point<dimensions> &point)
{
	// TODO : Define point input function

	return is;
}

template class Point<2>;
template class Point<3>;

} // namespace geometry
