/*
Class for Triangulation

id_: Unique triangulation identifier
point_vector_: Vector of points
line_vector_: Vector of lines
*/

#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGULATION_IPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGULATION_IPP_

#include <vector>
#include <ostream>
#include <istream>


namespace geometry
{

template <int dimensions, typename Precision>
Triangulation<dimensions, Precision>::Triangulation(PointVector point_vector)
	: point_vector_(point_vector) 
{}

template <int dimensions, typename Precision>
Triangulation<dimensions, Precision>::Triangulation(const Triangulation<dimensions, Precision> &triangulation)
{
	// TODO : Define copy constructor
}

template <int dimensions, typename Precision>
void Triangulation<dimensions, Precision>::triangulate()
{}

template <int dimensions, typename Precision>
std::vector<Point<dimensions, Precision>> Triangulation<dimensions, Precision>::get_points()
{
	return this->points_vector_;
}

template <int dimensions, typename Precision>
std::vector<Line<Point<dimensions, Precision>>> Triangulation<dimensions, Precision>::get_lines()
{
	return this->line_vector_;
}

template <int dimensions, typename Precision>
std::ostream &operator<<(std::ostream &os, const Triangulation<dimensions, Precision> &triangulation)
{
	std::cout << "Points:\n";
	for (auto &i : triangulation.point_vector_)
	{
		std::cout << i;
	} 

	std::cout << "Lines:\n";
	for (auto &i : triangulation.line_vector_)
	{
		std::cout << i;
	}
	
	return os;
}

template <int dimensions, typename Precision>
std::istream &operator>>(std::istream &is, const Triangulation<dimensions, Precision> &triangulation)
{
	// TODO : Define triangulation deserialization function

	return is;
}

} // namespace geometry

#endif
