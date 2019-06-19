#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_POINT_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_POINT_HPP_

#include <array>
#include <ostream>
#include <istream>

#include <geometry/vector.hpp>

// Class for a D-dimensional point
// 
// D: Dimensions
// id_: Unique point identifier
// coordinates_: Point coordinates in D-dimentional space
// 

namespace geometry
{

template <int dimensions, typename Precision>
struct Point
{
private:
	int id_;
	std::array<float, dimensions> coordinates_;

public:
	Point();
	Point(const Point &point);

	template <int d, typename P>
	friend std::ostream &operator<<(std::ostream &os, const Point<d, P> &point);

	template <int d, typename P>
	friend std::istream &operator>>(std::istream &is, const Point<d, P> &point);
};

} // namespace geometry

#include <geometry/impl/point.ipp>

#endif
