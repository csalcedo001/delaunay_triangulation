#ifndef DELAUNAY_TRIANGUATION_GENERATOR_DISTRIBUTION_HPP_
#define DELAUNAY_TRIANGUATION_GENERATOR_DISTRIBUTION_HPP_

#include <random>

#include <geometry/point.hpp>

namespace generator
{

template <int dimensions, typename Precision>
class Distribution
{
protected:
	std::default_random_engine generator_;

	Distribution();

public:

	// Abstract virtual function for the distribution generator
	virtual geometry::Point<dimensions, Precision> operator()() = 0;
};

} // namespace generator

#include <generator/impl/distribution.ipp>

#endif
