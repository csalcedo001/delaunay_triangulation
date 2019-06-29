#ifndef DELAUNAY_TRIANGUATION_GENERATOR_NORMAL_DISTRIBUTION_IPP_
#define DELAUNAY_TRIANGUATION_GENERATOR_NORMAL_DISTRIBUTION_IPP_

#include <generator/distribution.hpp>

namespace generator
{

template <int dimensions, typename Precision>
NormalDistribution<dimensions, Precision>::NormalDistribution()
{
	// TODO : Implement default normal distribution constructor
}

template <int dimensions, typename Precision>
NormalDistribution<dimensions, Precision>::NormalDistribution(std::array<std::pair<double, double>, dimensions> constants)
{
	// TODO : Implement user defined normal distribution constructor
}

template <int dimensions, typename Precision>
geometry::Point<dimensions, Precision> NormalDistribution<dimensions, Precision>::operator()()
{
	// TODO : Implement return function
	geometry::Point<dimensions, Precision> point;

	return point;
}

} // namespace generator

#endif
