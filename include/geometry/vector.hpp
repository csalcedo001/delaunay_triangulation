#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_VECTOR_HPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_VECTOR_HPP_

#include <array>
#include <fstream>

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
	Vector() = default;
	Vector(const Vector<dimensions, Precision>& coordinate);

	template <int d, typename P>
	friend std::ostream &operator<<(std::ostream &os, const Vector<d, P> &vector);

	template <int d, typename P>
	friend std::istream &operator>>(std::istream &is, const Vector<d, P> &vector);
};

} // namespace geometry

#include <geometry/impl/vector.ipp>

#endif
