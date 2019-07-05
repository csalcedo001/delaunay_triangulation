#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_TRIANGLE_IPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_RANDOMIZED_INCREMENTAL_TRIANGLE_IPP_

namespace algorithm
{

namespace randomized_incremental
{

template <typename Precision>
Triangle<Precision>::Triangle(AbstractPoint &p1, AbstractPoint &p2, AbstractPoint &p3)
{
	
	auto ptr1 = std::make_shared<AbstractPoint>(p1);
	auto ptr2 = std::make_shared<AbstractPoint>(p2);
	auto ptr3 = std::make_shared<AbstractPoint>(p3);

	this->points_ = {ptr1, ptr2, ptr3};
}

template <typename Precision>
bool Triangle<Precision>::Contains(Point<Precision> point)
{
	// TODO : Implement contention test
	
	return false;
}

} // namespace randomized_incremental

} // namespace algorithm

#endif
