#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_POINT_IPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_POINT_IPP_

#include <geometry/point.hpp>
#include <algorithm/randomized_incremental/abstract_point.hpp>

namespace algorithm
{

namespace randomized_incremental
{

template <typename Precision>
Point(const geometry::Point<2, Precision> &point)
{
	this->coordinates_ = point.coordinates_;
}

template <typename Precision>
bool operator<(Point<Precision> p1, Point<Precision> p2)
{
	return p1.Y() == p2.Y() ? p1.X() < p2.X() : p1.Y() < p2.Y();
}

} // namespace randomized_incremental

} // namespace algorithm

#endif

