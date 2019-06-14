#ifndef DELAUNAY_TRIANGULATION_POINT_HPP_
#define DELAUNAY_TRIANGULATION_POINT_HPP_

#include <array>
#include <ostream>
#include <istream>

// Class for a D-dimensional point
// 
// D: Dimensions
// id_: Unique point identifier
// coordinates_: Point coordinates in D-dimentional space
// 

template <int D>
struct Point
{
private:
	int id_;
	std::array<float, D> coordinates_;

public:
	Point();
	Point(const Point<D> &point);

	friend std::ostream &operator<<(std::ostream &os, const Point<D> &point);
	friend std::istream &operator>>(std::istream &is, const Point<D> &point);
};



template <int D>
Point<D>::Point()
{
	// TODO : Assign unique id to point
}

template <int D>
Point<D>::Point(const Point<D> &point)
{
	// TODO : Define copy constructor. Copy same id
}

template <int D>
std::ostream &operator<<(std::ostream &os, const Point<D> &point)
{
	// TODO : Define point output function

	return os;
}

template <int D>
std::istream &operator>>(std::istream &is, const Point<D> &point)
{
	// TODO : Define point input function

	return is;
}

#endif
