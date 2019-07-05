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

public:
	Leaf(std::shared_ptr<Triangle<Precision>> triangle) : Node<Precision>(triangle) {}
};

} // namespace randomized_incremental

} // namespace algorithm

#endif
