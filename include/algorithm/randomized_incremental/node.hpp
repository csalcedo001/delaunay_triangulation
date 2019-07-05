#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_NODE_HPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_NODE_HPP_

#include <algorithm/randomized_incremental/triangle.hpp>

namespace algorithm
{

namespace randomized_incremental
{

template <typename Precision>
class Node
{
	Triangle<Precision> triangle_;
};

} // namespace randomized_incremental

} // namespace algorithm

#endif
