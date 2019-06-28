#ifndef DELAUNAY_TRIANGUATION_GENERATOR_DISTRIBUTION_IPP_
#define DELAUNAY_TRIANGUATION_GENERATOR_DISTRIBUTION_IPP_

#include <random>
#include <chrono>

namespace generator
{

template <int dimensions, typename Precision>
Distribution<dimensions, Precision>::Distribution() :
	generator_(std::chrono::system_clock::now().time_since_epoch().count())
{

}

} // namespace generator

#endif
