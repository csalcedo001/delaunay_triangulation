#ifndef DELAUNAY_TRIANGUATION_GENERATOR_UNIFORM_BUBBLE_DISTRIBUTION_IPP_
#define DELAUNAY_TRIANGUATION_GENERATOR_UNIFORM_BUBBLE_DISTRIBUTION_IPP_

#include <generator/distribution.hpp>
#include <generator/normal_distribution.hpp>

namespace generator
{

template <int dimensions, typename Precision>
UniformBubbleDistribution<dimensions, Precision>::UniformBubbleDistribution(int n) : Distribution<dimensions, Precision>()
{
	// TODO : Define uniform bubble distribution constructor
}

template <int dimensions, typename Precision>
geometry::Point<dimensions, Precision> UniformBubbleDistribution<dimensions, Precision>::operator()()
{
	// TODO : Define call to uniform bubble distribution

	geometry::Point<dimensions, Precision> point;

	return point;
}

} // namespace generator

#endif
