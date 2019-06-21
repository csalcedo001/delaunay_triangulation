#include <iostream>

#include <geometry/delaunay_triangulation.hpp>
#include <window/canvas.hpp>

using namespace std;

int main (void)
{
	Window m(100,100, 2000, "Testing");
	m.display();
	// geometry::Vector<2, float> v;
	// geometry::Point<2, float> p;
	// geometry::Triangulation<2, float> t;
	// geometry::DelaunayTriangulation<2, float> dt;

	// cin >> v;
	// cin >> p;
	// cin >> t;
	// cin >> dt;

	// cout << v;
	// cout << p;
	// cout << t;
	// cout << dt;

	// TODO : Test structures: Write test units.

	//TODO : Write main program with structures from delaunay_triangulation.h

// TODO : Test execution times
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
