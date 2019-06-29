#ifndef DELAUNAY_TRIANGUATION_GENERATOR_UNIFORM_DISTRIBUTION_HPP_
#define DELAUNAY_TRIANGUATION_GENERATOR_UNIFORM_DISTRIBUTION_HPP_

#include <vector>
#include <random>

#include <generator/distribution.hpp>

namespace generator
{

template <int dimensions, typename Precision>
class UniformDistribution : public Distribution<dimensions, Precision>
{
private:
	// std::default_random_engine generator_;
	std::vector<std::uniform_real_distribution<double>> distributions_;

public:
	// Initialize UniformDistribution from 0 to 1
	UniformDistribution();

	// Initialize hypercubic UniformDistribution
	UniformDistribution(int edge_size);

	// Initialize UniformDistribution functor with box margins
	UniformDistribution(std::array<std::pair<Precision, Precision>, dimensions> limits);

	geometry::Point<dimensions, Precision> operator()();
};

} // namespace generator

#include <generator/impl/uniform_distribution.ipp>

#endif
