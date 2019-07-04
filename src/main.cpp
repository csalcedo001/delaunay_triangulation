#include <window/canvas.hpp>
#include <iostream>

#include <geometry.hpp>
#include <generator/generator.hpp>


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

	generator::NormalDistribution<3, float> point_generator;

	std::vector<geometry::Point<3, float>*> points;
	
	for (int i = 0; i < 10; i++)
	{
		geometry::Point<3, float> point = point_generator();
		geometry::Point<3, float> *point_ptr = new Point<3, float>(point.coordinates_);
		points.push_back(point_ptr);
	}

	for (int i = 0; i < points.size(); i++)
	{
		std::cout << *points[i] << std::endl;
	}

	geometry::Triangulation<3, float> t(points);
	std::vector<geometry::Triangle<3, float>> triangles = t.incremental_triangulation();
	std::cout << "Finished";

	// Window<Point<3, float>> w1(2, points);
	// w1.display();

	// Window<Triangle<3, float>> w2(1, ());
	// w2.display();

	return 0;
};
