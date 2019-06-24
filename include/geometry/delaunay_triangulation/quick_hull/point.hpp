#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_DELAUNAY_TRIANGULATION_QUICK_HULL_POINT_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_DELAUNAY_TRIANGULATION_QUICK_HULL_POINT_HPP_

#include <geometry/point.hpp>

namespace geometry
{

namespace delaunay_triangulation
{

namespace quick_hull
{

template <typename Precision>
class Point : geometry::Point<2, Precision>
{
public:
	inline const Precision X() const
	{
		return this->coordinates_[0];
	}
	inline const Precision Y() const
	{
		return this->coordinates_[1]
	};
};

} // quick_hull

} // delaunay_triangulation

} // geometry

#endif
