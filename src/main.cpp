#include <window/canvas.hpp>
#include <iostream>

#include <geometry.hpp>
#include <generator/generator.hpp>


int main (void)
{
	generator::NormalDistribution<3, double> point_generator;

    std::vector<geometry::Point<3, double>> points;
	std::vector<geometry::Point<3, double>*> points_ptr;
	
	for (int i = 0; i < 10; i++)
	{
		geometry::Point<3, double> point = point_generator();
		point.coordinates_[2] = 0;
		geometry::Point<3, double> *point_ptr = new Point<3, double>(point.coordinates_);
		points.push_back(point);
		points_ptr.push_back(point_ptr);
	}

	for (int i = 0; i < points.size(); i++)
	{
		std::cout << points[i] << std::endl;
	}

	geometry::Triangulation<3, double> t(points_ptr);
	std::vector<geometry::Triangle<3, double>*> triangles = t.incremental_triangulation();
	std::cout << "Finished: " << triangles.size() << " triangles\n";
	for (auto &i : triangles)
	{
		std::cout << *i << "\n";
	}

    Window<Point<3, double>> w1(2, points_ptr);
	w1.display();

	Window<Triangle<3, double>> w2(1, triangles);
	w2.display();

	return 0;
};
