#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_TRIANGLE_HPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_TRIANGLE_HPP_

#include <array>

#include <geometry/triangle.hpp>
#include <algorithm/randomized_incremental/abstract_point.hpp>

namespace algorithm
{

namespace randomized_incremental
{

template <typename Precision>
class Triangle : public geometry::Triangle<2, Precision>
{
	std::array<std::shared_ptr<AbstractPoint>, 3> points_;

	
};

} // namespace randomized_incremental

} // namespace algorithm

#endif
