#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_DELAUNAY_TRIANGULATION_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_DELAUNAY_TRIANGULATION_HPP_

#include <vector>

#include <geometry/triangulation.hpp>

namespace geometry
{

template <int dimensions, typename Precision>
class DelaunayTriangulation : public Triangulation<dimensions, Precision>
{
public:
	typedef std::vector<Point<dimensions, Precision>> PointVector;

protected:
	PointVector point_vector_;

public:
	DelaunayTriangulation() = default;
	DelaunayTriangulation(const DelaunayTriangulation<dimensions, Precision> &delaunay_triangulation);

	friend std::ostream &operator<<(std::ostream &os, const DelaunayTriangulation<dimensions, Precision> &delaunay_triangulation)
	{
		// TODO : Define triangulation serialization function
	
		return os;
	}

	friend std::istream &operator>>(std::istream &is, const DelaunayTriangulation<dimensions, Precision> &delaunay_triangulation)
	{
		// TODO : Define triangulation deserialization function
	
		return is;
	}
};

} // namespace geometry

#include <geometry/impl/delaunay_triangulation.ipp>

#endif
