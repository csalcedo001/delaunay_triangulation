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
class Point : public geometry::Point<2, Precision>
{
private:
	int distance_;

public:
	static inline bool IsCloser(Point p1, Point p2)
	{
		return p1.distance_ < p2.distance_;
	}

	inline const Precision X() const
	{
		return this->coordinates_[0];
	}
	inline const Precision Y() const
	{
		return this->coordinates_[1];
	};

	void SetDistance(int distance)
	{
		this->distance_ = distance;
	}
};

} // quick_hull

} // delaunay_triangulation

} // geometry

#endif
