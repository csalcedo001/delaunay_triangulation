#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_DELAUNAY_TRIANGULATION_QUICK_HULL_QUICK_HULL_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_DELAUNAY_TRIANGULATION_QUICK_HULL_QUICK_HULL_HPP_

#include <geometry/triangulation.hpp>

namespace geometry
{

namespace delaunay_triangulation
{

namespace quick_hull
{

template <typename Precision>
class QuickHull
{
public:
	Triangulation<2, Precision> operator()(std::vector<Point<2, Precision>> point_set>;
};

} // namespace quick_hull

} // namespace delaunay_triangulation

} // namespace geometry

#endif
