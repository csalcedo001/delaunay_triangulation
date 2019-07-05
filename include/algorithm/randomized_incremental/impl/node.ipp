#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_NODE_IPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_NODE_IPP_

namespace algorithm
{

namespace randomized_incremental
{

template <typename Precision>
Node<Precision>::Node(std::shared_ptr<Triangle<Precision>> triangle) : triangle_(triangle)
{

}

} // namespace randomized_incremental

} // namespace algorithm

#endif
