#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_POINT_HPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_POINT_HPP_

#include <geometry/point.hpp>
#include <algorithm/randomized_incremental/abstract_point.hpp>

namespace algorithm
{

namespace randomized_incremental
{

template <typename Precision>
class Point : public AbstractPoint, public geometry::Point<2, Precision>
{
	
};

} // namespace randomized_incremental

} // namespace algorithm

#endif

