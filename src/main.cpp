// #include <window/canvas.hpp>
#include <iostream>

#include <geometry/point.hpp>
#include <generator/generator.hpp>

using namespace std;

int main (void)
{
//	Window w;
//	w.display(); 
	generator::NormalDistribution<2, float> point_generator;

	std::vector<geometry::Point<2, float>> points;
	
	for (int i = 0; i < 10; i++)
	{
		points.push_back(point_generator());
	}

	for (int i = 0; i < points.size(); i++)
	{
		cout << points[i] << endl;
	}

	

	return 0;
};
