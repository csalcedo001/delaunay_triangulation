#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_TRIANGULATION_HPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_TRIANGULATION_HPP_

#include <geometry/triangulation.hpp>

namespace algorithm
{

namespace randomized_incremental
{

template <typename Precision>
class Triangulation : public geometry::Triangulation<2, Precision>
{

};

} // namespace randomized_incremental

} // namespace alrogithm

#endif
