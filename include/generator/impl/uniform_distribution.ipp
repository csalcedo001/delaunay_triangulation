#ifndef DELAUNAY_TRIANGUATION_GENERATOR_UNIFORM_DISTRIBUTION_IPP_
#define DELAUNAY_TRIANGUATION_GENERATOR_UNIFORM_DISTRIBUTION_IPP_

#include <vector>
#include <random>
#include <chrono>

#include <generator/distribution.hpp>

namespace generator
{

template <int dimensions, typename Precision>
UniformDistribution<dimensions, Precision>::UniformDistribution() : Distribution<dimensions, Precision>()
{
	this->distributions_.resize(dimensions);

	for (int dimension = 0; dimension < dimensions; ++dimension)
	{
		std::uniform_real_distribution current_distribution(0., 1.);

		this->distributions_[dimension] = current_distribution;
	}
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
	std::array<Precision, dimensions> coordinates;

	for (int dimension = 0; dimension < dimensions; ++dimension)
	{
		coordinates[dimension] = this->distributions_[dimension](this->generator_);
	}

	geometry::Point<dimensions, Precision> point(coordinates);

	return point;
}

} // namespace generator

#endif
