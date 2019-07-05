#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_DIRECTED_ACYCLIC_GRAPH_HPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_DIRECTED_ACYCLIC_GRAPH_HPP_

#include <geometry/triangulation.hpp>

namespace algorithm
{

namespace randomized_incremental
{

template <typename Precision>
class DirectedAcyclicGraph
{
private:
	Triangle last_visited_
	
public:
	DirectedAcyclicGraph();

	Triangle Find(Point);
};

} // namespace randomized_incremental

} // namespace alrogithm

#endif
