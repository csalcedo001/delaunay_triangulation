#include <iostream>

#include "delaunay_triangulation.hpp"

// randomized incremental approach

void legalize_edge(Point p, Edge e, Triangulation t)
{
	// something
};

Point* compute_random_permutation(Point set[], int size)
{
	Point random_permutation[size - 1];
	// compute random permutation p1..pn of set - {pH} 
	return random_permutation;
};

Point get_highest_point(Point set[], int size)
{
	// return the lexicographically highest point of P
	// that is, the rightmost among the points with largest y-coordinate
	Point highest_point;
	// something
	return highest_point;
};

Triangulation get_delaunay_triangulation(Point set[], int size)
{
	Point pH = get_highest_point(set, size);
	Point pA, pB;
	// we create pA and pB
	// two points in R^2
	// P is contained in the triangle pH pA pB
	Triangulation delaunay_triangulation(pH, pA, pB);
	Point *random_permutation;
	Triangle aux_triangle;
	random_permutation = compute_random_permutation(set, size);
	for (int i = 0; i < size; ++i)
	{
		delaunay_triangulation.insert(set[i]);
		aux_triangle = delaunay_triangulation.find_triangle(set[i]);
		if (aux_triangle.has_in_interior(set[i])) 
		{
			Triangle triangle_a(set[i], aux_triangle.a, aux_triangle.b);
			Triangle triangle_b(set[i], aux_triangle.a, aux_triangle.c);
			Triangle triangle_c(set[i], aux_triangle.b, aux_triangle.c);

			legalize_edge(set[i], aux_triangle.get_edge(aux_triangle.a, aux_triangle.b), delaunay_triangulation);
			legalize_edge(set[i], aux_triangle.get_edge(aux_triangle.a, aux_triangle.c), delaunay_triangulation);
			legalize_edge(set[i], aux_triangle.get_edge(aux_triangle.b, aux_triangle.c), delaunay_triangulation);
		}
		else if (aux_triangle.has_in_edge(set[i]))
		{
			// set[i] lies on an edge of pi pj pk, say the edge pi pj
			Point k = aux_triangle.get_k(set[i]);
			Edge edge = aux_triangle.get_lying_edge(set[i]);
			// add edges from set[i] to pk and 
			// to the third vertex pl of the other triangle that is incident to pi pj
			Triangle incident = delaunay_triangulation.get_incident(edge);
			Point l = incident.get_third_vertex();
			legalize_edge(set[i], incident.get_edge(l, aux_triangle.a), delaunay_triangulation);
			legalize_edge(set[i], incident.get_edge(l, aux_triangle.b), delaunay_triangulation);
			legalize_edge(set[i], aux_triangle.get_edge(aux_triangle.a, aux_triangle.c), delaunay_triangulation);
			legalize_edge(set[i], aux_triangle.get_edge(aux_triangle.b, aux_triangle.c), delaunay_triangulation);
		}
	}
	delaunay_triangulation.discard(pA);
	delaunay_triangulation.discard(pB);
	return delaunay_triangulation;
};

int main()
{
    const int size = 100;
	Point set[size];
	get_delaunay_triangulation(set, size);

	return 0;
};
