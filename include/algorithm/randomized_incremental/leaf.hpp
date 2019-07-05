#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_LEAF_HPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_LEAF_HPP_

#include <array>

#include <algorithm/randomized_incremental/node.hpp>

namespace algorithm
{

namespace randomized_incremental
{

template <typename Precision>
class Leaf : public Node<Precision>
{
	std::array<Leaf<Precision>, 3> nodes_;
};

} // namespace randomized_incremental

} // namespace algorithm

#endif
