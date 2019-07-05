#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_DIRECTED_ACYCLIC_GRAPH_HPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_DIRECTED_ACYCLIC_GRAPH_HPP_

#include <algorithm/randomized_incremental/node.hpp>
#include <algorithm/randomized_incremental/infinite_point.hpp>
#include <algorithm/randomized_incremental/point.hpp>

namespace algorithm
{

namespace randomized_incremental
{

template <typename Precision>
class DirectedAcyclicGraph
{
	std::shared_ptr<Node<Precision>> head_;
	InfinitePoint left_point_;
	InfinitePoint right_point_;

public:
	// Create first triangle and node with left_point_, right_point_ and initial_point
	DirectedAcyclicGraph(Point<Precision> &initial_point);
	
	void InsertPoint(Point<Precision> &new_point);
};

} // namespace randomized_incremental

} // namespace algorithm

#endif

