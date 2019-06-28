#ifndef DELAUNAY_TRIANGUATION_GENERATOR_UNIFORM_DISTRIBUTION_IPP_
#define DELAUNAY_TRIANGUATION_GENERATOR_UNIFORM_DISTRIBUTION_IPP_

#include <vector>
#include <random>
#include <chrono>

namespace generator
{

template <int dimensions, typename Precision>
UniformDistribution<dimensions, Precision>::UniformDistribution()
{
	// TODO : Implement constructor
}

template <int dimensions, typename Precision>
UniformDistribution<dimensions, Precision>::UniformDistribution(int edge_size)
{
	// TODO : Implement constructor
}

template <int dimensions, typename Precision>
UniformDistribution<dimensions, Precision>::UniformDistribution(std::array<std::pair<Precision, Precision>, dimensions> limits)
{
	// TODO : Implement constructor
}

template <int dimensions, typename Precision>
geometry::Point<dimensions, Precision> UniformDistribution<dimensions, Precision>::operator()()
{
	// TODO : Implement operator()

	geometry::Point<dimensions, Precision> p;

	return p;
}

} // namespace generator

#endif
