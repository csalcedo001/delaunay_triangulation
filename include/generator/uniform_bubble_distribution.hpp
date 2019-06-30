#ifndef DELAUNAY_TRIANGUATION_GENERATOR_UNIFORM_BUBBLE_DISTRIBUTION_HPP_
#define DELAUNAY_TRIANGUATION_GENERATOR_UNIFORM_BUBBLE_DISTRIBUTION_HPP_

#include <vector>

#include <generator/distribution.hpp>
#include <generator/normal_distribution.hpp>

namespace generator
{

template <int dimensions, typename Precision>
class UniformBubbleDistribution : public Distribution<dimensions, Precision>
{
private:
	std::vector<NormalDistribution<dimensions, Precision>> distributions_;

public:
	// Initialize MaliciousBubbleDistribution with number of boubbles
	// Initialize n NormalDistribution functors and generate points randomly
	UniformBubbleDistribution(int n);

	geometry::Point<dimensions, Precision> operator()();
};

} // namespace generator

#include <generator/impl/uniform_bubble_distribution.ipp>

#endif
