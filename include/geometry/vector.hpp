#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_VECTOR_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_VECTOR_HPP_

#include <array>

namespace geometry
{

template <int dimensions, typename Precision>
class Vector
{
public:
	typedef std::array<Precision, dimensions> Container;

private:
	Container container_;

public:
	Vector();
	Vector(const Vector<dimensions, Precision>& coordinate);

	friend std::ostream &operator<<(std::ostream &os, const Vector<dimensions, Precision> &point);
	friend std::istream &operator>>(std::istream &is, const Vector<dimensions, Precision> &point);
};

} // namespace geometry

#include <geometry/impl/vector.ipp>

#endif
