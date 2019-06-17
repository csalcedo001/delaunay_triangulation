#include <iostream>

#include <geometry/delaunay_triangulation.hpp>

using namespace std;

int main (void)
{
	geometry::Vector<2, float> c1;
	geometry::Vector<2, float> c2(c1);

	geometry::Point<2, float> p;

	std::vector<geometry::Point<2, float>> a;

	geometry::Triangulation<2, float> t;
	//TODO : Write main program with structures from delaunay_triangulation.h

//	A a;
//
//	auto start = std::chrono::high_resolution_clock::now();
//	
//	a.returnCopy();
//	
//	auto end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<double> elapsed = end - start;
//	std::cout << "Time in seconds: " << std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count() << '\n';
//
//	start = std::chrono::high_resolution_clock::now();
//	
//	a.returnReference();
//	
//	end = std::chrono::high_resolution_clock::now();
//	elapsed = end - start;
//	std::cout << "Time in seconds: " << std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count() << '\n';

	return 0;
}
