#ifndef DELAUNAY_TRIANGUATION_GENERATOR_NORMAL_DISTRIBUTION_IPP_
#define DELAUNAY_TRIANGUATION_GENERATOR_NORMAL_DISTRIBUTION_IPP_

#include <generator/distribution.hpp>

namespace generator
{

template <int dimensions, typename Precision>
NormalDistribution<dimensions, Precision>::NormalDistribution() : Distribution<dimensions, Precision>()
{
	this->distributions_.resize(dimensions);

	for (int dimension = 0; dimension < dimensions; ++dimension)
	{
		std::normal_distribution<double> current_distribution(0., 1.);

		this->distributions_[dimension] = current_distribution;
	}
}

template <int dimensions, typename Precision>
NormalDistribution<dimensions, Precision>::NormalDistribution(std::array<std::pair<double, double>, dimensions> constants)
{
	// TODO : Implement user defined normal distribution constructor
}

template <int dimensions, typename Precision>
geometry::Point<dimensions, Precision> NormalDistribution<dimensions, Precision>::operator()()
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
