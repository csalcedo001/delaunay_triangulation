#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_POINT_IPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_POINT_IPP_

#include <geometry/vector.hpp>

#include <array>
#include <ostream>
#include <istream>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Class for a D-dimensional point
// 
// D: Dimensions
// id_: Unique point identifier
// coordinates_: Point coordinates in D-dimentional space
// 

namespace geometry
{

template <int dimensions, typename Precision>
Point<dimensions, Precision>::Point()
{
	// TODO : Assign unique id to point
}

template <int dimensions, typename Precision>
Point<dimensions, Precision>::Point(const Point<dimensions, Precision> &point)
{
	for (int i = 0; i < dimensions; ++i) {
		coordinates_[i] = point.coordinates_[i];
	}
}

template <int dimensions, typename Precision>
Point<dimensions, Precision>::Point(const std::array<Precision, dimensions> coord)
	: coordinates_(coord)
{}

template <int dimensions, typename Precision>
Point<dimensions, Precision> Point<dimensions, Precision>::operator+(const Point<dimensions, Precision>& point) const
{
	std::array<Precision, dimensions> res;

	for (int i = 0; i < dimensions; ++i) {
		res[i] = coordinates_[i] + point.coordinates_[i];
	}

	return Point<dimensions, Precision>(res);
}

template <int dimensions, typename Precision>
Point<dimensions, Precision> Point<dimensions, Precision>::operator-(const Point<dimensions, Precision>& point) const
{
	std::array<Precision, dimensions> res;

	for (int i = 0; i < dimensions; ++i) {
		res[i] = coordinates_[i] - point.coordinates_[i];
	}

	return Point<dimensions, Precision>(res);
}

template <int dimensions, typename Precision>
Point<dimensions, Precision> Point<dimensions, Precision>::operator*(const Precision &scalar)
{
	std::array<Precision, dimensions> res;

	for (int i = 0; i<dimensions; ++i) {
		res[i] = coordinates_[i] * scalar;
	}

	return Point<dimensions, Precision>(res);
}

template <int dimensions, typename Precision>
Point<dimensions, Precision> operator*(Precision scalar, const Point<dimensions, Precision> &point){
	return point * scalar;
}

template <int dimensions, typename Precision>
Point<dimensions, Precision>& Point<dimensions, Precision>::operator=(const Point<dimensions, Precision> &point)
{
	if (this == &point)	return *this;

	for(int i = 0; i<dimensions; ++i) {
		coordinates_[i] = point.coordinates_[i];
	}

	return *this;
}

template <int dimensions, typename Precision>
Precision Point<dimensions, Precision>::dotProduct(const Point<dimensions,Precision> &point)
{
	Precision r = 0;
	for (int i = 0; i < dimensions; i++) {
		r += coordinates_[i] * point.coordinates_[i];
	}
	return r;
}

template <int dimensions, typename Precision>	
void Point<dimensions, Precision>::render() 
{
	GLfloat y = dimensions < 2 ? 0 : coordinates_[1];
	GLfloat z = dimensions < 3 ? 0 : coordinates_[2];

	glColor3f(255, 0, 0);
	glVertex3f(coordinates_[0], y, z);
}

template <int dimensions, typename Precision>
std::ostream &operator<<(std::ostream &os, const Point<dimensions, Precision> &point)
{
	os << point.coordinates_[0];
	
	for(int i = 1; i < dimensions; ++i) {
		os << " " << point.coordinates_[i];
	}

	return os;
}

template <int dimensions, typename Precision>
std::istream &operator>>(std::istream &is, Point<dimensions, Precision> &point)
{
	std::cout << "Ingrese " << dimensions << " coordenadas para el punto\n";

	for (auto &it:point.coordinates_)
		is >> it;

	return is;
}

template <int dimensions, typename Precision>
std::array<Precision, dimensions> Point<dimensions, Precision>::get_coordinates()
{
	return this->coordinates_;
}

} // namespace geometry

#endif
