#ifndef DELAUNAY_TRIANGULATION_POINT_HPP_
#define DELAUNAY_TRIANGULATION_POINT_HPP_

#include <array>
#include <ostream>
#include <istream>

#include <geometry/coordinate.hpp>

// Class for a D-dimensional point
// 
// D: Dimensions
// id_: Unique point identifier
// coordinates_: Point coordinates in D-dimentional space
// 

namespace geometry
{

template <int dimensions>
struct Point
{
private:
	int id_;
	std::array<float, dimensions> coordinates_;

public:
	Point();
	Point(const Point<dimensions> &point);

	friend std::ostream &operator<<(std::ostream &os, const Point<dimensions> &point);
	friend std::istream &operator>>(std::istream &is, const Point<dimensions> &point);
};

} // namespace geometry

#endif
