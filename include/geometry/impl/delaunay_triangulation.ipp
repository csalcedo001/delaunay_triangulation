#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_DELAUNAY_TRIANGULATION_IPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_DELAUNAY_TRIANGULATION_IPP_

#include <vector>

#include <geometry/triangulation.hpp>

namespace geometry
{

template <int dimensions, typename Precision>
DelaunayTriangulation<dimensions, Precision>::DelaunayTriangulation(
	const DelaunayTriangulation<dimensions, Precision> &delaunay_triangulation)
{
	// Define copy constructor
}

template <int dimensions, typename Precision>
std::ostream &operator<<(std::ostream &os, const DelaunayTriangulation<dimensions, Precision> &delaunay_triangulation)
	{
		// TODO : Define triangulation serialization function
	
		return os;
	}

template <int dimensions, typename Precision>
std::istream &operator>>(std::istream &is, const DelaunayTriangulation<dimensions, Precision> &delaunay_triangulation)
	{
		// TODO : Define triangulation deserialization function
	
		return is;
	}

} // namespace geometry

#endif
