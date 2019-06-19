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

	friend std::ostream &operator<<(std::ostream &os, const Vector<dimensions, Precision> &vector)
	{
		// TODO : Define vector serialization function

		return os;
	}

	friend std::istream &operator>>(std::istream &is, const Vector<dimensions, Precision> &vector)
	{
		// TODO : Define vector deserialization function

		return is;
	}
};

} // namespace geometry

#include <geometry/impl/vector.ipp>

#endif
