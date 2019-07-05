#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_TRIANGULATE_IPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_TRIANGULATE_IPP_

#include <vector>

#include <algorithm/randomized_incremental/point.hpp>
#include <algorithm/randomized_incremental/triangle.hpp>
#include <algorithm/randomized_incremental/directed_acyclic_graph.hpp>

namespace algorithm
{

namespace randomized_incremental
{

template <typename Precision>
Triangulation<Precision> Triangulate(std::vector<Point<Precision>> &point_vector)
{
	// Define variables
	int n = point_vector.size(); // Number of points


	// Find maximum point in point_vector
	int max_index = 0;
	Point<Precision> max_element = point_vector[0];
	
	for (int i = 1; i < n; ++i)
	{
		if (point_vector[i] > max_element)
		{
			max_element = point_vector[i];
			max_index = i;
		}
	}

	
	// Move element to the front 
	std::swap(point_vector[max_index], point_vector[0]);

	DirectedAcyclicGraph<Precision> da_graph(max_element);

	for (int i = 1; i < n; ++i)
	{
		da_graph.InsertPoint(point_vector[i]);
	}



	// Remove infinite points
}

} // namespace randomized_incremental

} // namespace algorithm

#endif