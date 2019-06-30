// #include <window/canvas.hpp>
#include <iostream>

#include <geometry/point.hpp>
#include <generator/generator.hpp>

using namespace std;

int main (void)
{
	// vector<Point<3, float>> points;
	// array<float, 3> coordinates;
	// coordinates[0] = 0;
	// coordinates[1] = 0;
	// coordinates[2] = 0;
	// points.emplace_back(coordinates);
	// coordinates[0] = 1;
	// coordinates[1] = 1;
	// coordinates[2] = 1;
	// points.emplace_back(coordinates);
	// Window w(points);
	// w.display();

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
