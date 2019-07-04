#include <window/canvas.hpp>
#include <iostream>

#include <geometry.hpp>
#include <generator/generator.hpp>


int main (void)
{
	generator::NormalDistribution<3, float> point_generator;

    std::vector<geometry::Point<3, float>> points;
	std::vector<geometry::Point<3, float>*> points_ptr;
	
	for (int i = 0; i < 10; i++)
	{
		geometry::Point<3, float> point = point_generator();
		geometry::Point<3, float> *point_ptr = new Point<3, float>(point.coordinates_);
		points.push_back(point);
		points_ptr.push_back(point_ptr);
	}

	for (int i = 0; i < points.size(); i++)
	{
		std::cout << points[i] << std::endl;
	}

	geometry::Triangulation<3, float> t(points_ptr);
	std::vector<geometry::Triangle<3, float>> triangles = t.incremental_triangulation();
	std::cout << "Finished";

    Window<Point<3, float>> w1(2, points);
	w1.display();

	Window<Triangle<3, float>> w2(1, triangles);
	w2.display();

	return 0;
};
