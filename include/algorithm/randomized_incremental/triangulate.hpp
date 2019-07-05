#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_TRIANGULATE_HPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_TRIANGULATE_HPP_

#include <algorithm/randomized_incremental/point.hpp>
#include <algorithm/randomized_incremental/triangulation.hpp>

namespace algorithm
{

namespace randomized_incremental
{

template <typename Precision>
Triangulation<Precision> Triangulate(std::vector<Point<Precision>> point_vector);

} // namespace randomized_incremental

} // namespace algorithm

#include <algorithm/randomized_incremental/impl/triangulate.ipp>

#endif
