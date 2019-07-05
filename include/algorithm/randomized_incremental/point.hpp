#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_POINT_HPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_POINT_HPP_

#include <geometry/point.hpp>
#include <algorithm/randomized_incremental/abstract_point.hpp>

namespace algorithm
{

namespace randomized_incremental
{

template <typename Precision>
class Point : public AbstractPoint, public geometry::Point<2, Precision>
{
public:
	Point() = default;
	Point(const geometry::Point<2, Precision> &point);

	friend bool operator<(Point<Precision> p1, Point<Precision> p2);

	inline const Precision X() const
	{
		return this->coordinates_[0];
	}
	inline const Precision Y() const
	{
		return this->coordinates_[1];
	}
};

} // namespace randomized_incremental

} // namespace algorithm

#endif

