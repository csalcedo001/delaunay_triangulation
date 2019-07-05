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
protected:
	std::shared_ptr<Triangle<Precision>> triangle_;

public:
	Node(std::shared_ptr<Triangle<Precision>> triangle);
};

} // namespace randomized_incremental

} // namespace algorithm

#include <algorithm/randomized_incremental/impl/node.ipp>

#endif
