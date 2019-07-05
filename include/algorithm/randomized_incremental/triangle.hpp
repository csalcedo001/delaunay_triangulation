#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_TRIANGLE_HPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_TRIANGLE_HPP_

#include <array>

#include <geometry/triangle.hpp>
#include <algorithm/randomized_incremental/abstract_point.hpp>

namespace algorithm
{

namespace randomized_incremental
{

template <typename Precision>
class Triangle : public geometry::Triangle<2, Precision>
{
	std::array<std::shared_ptr<AbstractPoint>, 3> points_;

public:
	// Initialize triangle with 3 points
	Triangle(AbstractPoint &p1, AbstractPoint &p2, AbstractPoint &p3);

	bool Contains(Point<Precision> point);
};

} // namespace randomized_incremental

} // namespace algorithm

#include <algorithm/randomized_incremental/impl/triangle.ipp>

#endif
