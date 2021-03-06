#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_POINT_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_POINT_HPP_

#include <array>
#include <iostream>
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
	int id_ = 0;
	std::array<Precision, dimensions> coordinates_;

	Point();
	Point(const Point &point);
	Point(const std::array<Precision, dimensions> coord);
	Point(int id, const std::array<Precision, dimensions> coord);

	Point<dimensions, Precision> operator+(const Point<dimensions, Precision>&) const;
	Point<dimensions, Precision> operator-(const Point<dimensions, Precision>&) const;

	Point<dimensions, Precision> operator*(const Precision &scalar);
	Point<dimensions, Precision>& operator=(const Point<dimensions, Precision> &point);
	bool operator==(const Point<dimensions, Precision> &point);

	Precision dotProduct(const Point<dimensions,Precision> &point);

	void render();

	// template <int d, typename P>
	// friend void render(Point<d, P> point);

	template <int d, typename P>
	friend std::ostream &operator<<(std::ostream &os, const Point<d, P> &point);

	template <int d, typename P>
	friend std::istream &operator>>(std::istream &is, Point<d, P> &point);
};

} // namespace geometry

#include <geometry/impl/point.ipp>

#endif
