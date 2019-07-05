#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_DIRECTED_ACYCLIC_GRAPH_IPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_DIRECTED_ACYCLIC_GRAPH_IPP_

#include <algorithm/randomized_incremental/infinite_point.hpp>
#include <algorithm/randomized_incremental/point.hpp>
#include <algorithm/randomized_incremental/node.hpp>
#include <algorithm/randomized_incremental/leaf.hpp>

namespace algorithm
{

namespace randomized_incremental
{

template <typename Precision>
DirectedAcyclicGraph<Precision>::DirectedAcyclicGraph(Point<Precision> &initial_point)
{
	std::shared_ptr<Triangle<Precision>> new_triangle(
		new Triangle<Precision>(initial_point, this->right_point_, this->left_point_)
	);

	this->head_ = std::make_shared<Node<Precision>>(new Leaf(new_triangle));
}

template <typename Precision>
void DirectedAcyclicGraph<Precision>::InsertPoint(Point<Precision> &new_point)
{

}

} // namespace randomized_incremental

} // namespace algorithm

#endif

