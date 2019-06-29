#include <window/canvas.hpp>

int main (void)
{
	vector<Point<3, float>> points;
	array<float, 3> coordinates;
	coordinates[0] = 0;
	coordinates[1] = 0;
	coordinates[2] = 0;
	points.emplace_back(coordinates);
	coordinates[0] = 1;
	coordinates[1] = 1;
	coordinates[2] = 1;
	points.emplace_back(coordinates);
	Window w(points);
	w.display(); 
	return 0;
};
