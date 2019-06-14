#include <iostream>

#include "delaunay_triangulation.h"

Point get_highest_point(Point set[], int size)
{
	// return the lexicographically highest point of P
	// that is, the rightmost among the points with largest y-coordinate
	Point highest_point;
	// something
	return highest_point;
}

Triangulation get_delaunay_triangulation(Point set[], int size)
{
	Point pH = get_highest_point(set, size);
	Point pA, pB;
	// pA and pB are two points in R^2 sufficiently far away
	// such that P is contained in the triangle pH pA pB
	Triangulation delaunay_triangulation(pH, pA, pB);
	for (int i = 0; i < size; ++i)
	{
		delaunay_triangulation.insert(set[i]);
		
	}
	return delaunay_triangulation;
}

int main (void)
{
    const int size = 100;
	Point set[size];
	get_delaunay_triangulation(set, size);

	return 0;
}
