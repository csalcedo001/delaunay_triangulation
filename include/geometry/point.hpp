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

// Declaration

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




// Definition

template <int dimensions>
Point<dimensions>::Point()
{
	// TODO : Assign unique id to point
}

template <int dimensions>
Point<dimensions>::Point(const Point<dimensions> &point)
{
	// TODO : Define copy constructor. Copy same id
}

template <int dimensions>
std::ostream &operator<<(std::ostream &os, const Point<dimensions> &point)
{
	// TODO : Define point output function

	return os;
}

template <int dimensions>
std::istream &operator>>(std::istream &is, const Point<dimensions> &point)
{
	// TODO : Define point input function

	return is;
}

} // namespace geometry

#endif
