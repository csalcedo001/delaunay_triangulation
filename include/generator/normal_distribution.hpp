#ifndef DELAUNAY_TRIANGUATION_GENERATOR_NORMAL_DISTRIBUTION_HPP_
#define DELAUNAY_TRIANGUATION_GENERATOR_NORMAL_DISTRIBUTION_HPP_

#include <generator/distribution.hpp>

namespace generator
{

template <int dimensions, typename Precision>
class NormalDistribution : public Distribution<dimensions, Precision>
{
private:
	std::vector<std::normal_distribution<double>> distributions_;

public:
	// Initialize NormalDistribution with default mean = 0 and variance = 1
	NormalDistribution();

	// Initialize NormalDistribution functor with a list of mean-variance pairs
	NormalDistribution(std::array<std::pair<double, double>, dimensions> constants);

	geometry::Point<dimensions, Precision> operator()();
};

} // namespace generator

#include <generator/impl/normal_distribution.ipp>

#endif
