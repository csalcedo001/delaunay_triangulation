#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_TRIANGULATE_HPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_TRIANGULATE_HPP_

namespace algorithm
{

namespace randomized_incremental
{

template <int dimensions, typedef Precision>
geometry::Triangulation<dimensions, Precision> Triangulate(std::vector<geometry::Point<dimensions, Precision>> point_vector);

} // namespace randomized_incremental

} // namespace algorithm

#endif
