/*
Class for Borke Algorithm

Inherits from Triangulation
*/

#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_BORKE_HPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_BORKE_HPP_

#include <iostream>
#include <stdlib.h> // for C qsort 
#include <cmath>
#include <time.h> // for random

#include <geometry.hpp>

using namespace geometry;


namespace algorithm 
{

template <int dimensions, typename Precision>
class Borke : public Triangulation<dimensions, Precision>
{
public:
  typedef std::vector<Point<dimensions, Precision>> PointVector;
	typedef std::vector<Line<Point<dimensions, Precision>>> LineVector;

  Borke(PointVector point_vector);

  void triangulate();

  bool circumcircle(double xp, double yp, double x1, double y1, double x2, double y2, 
                    double x3, double y3, double &xc, double &yc, double &r);
  static bool point_comparison(Point<dimensions, Precision> p1, Point<dimensions, Precision> p2);
};

} // namespace algorithm

const int MaxVertices = 500;
const int MaxTriangles = 1000;
const int n_MaxPoints = 50; // for the test programm
const double EPSILON = 0.000001;

struct ITRIANGLE
{
  int p1, p2, p3;
};

struct IEDGE{
int p1, p2;
};

struct XYZ{
double x, y, z;
};

#include <algorithm/impl/borke.ipp>

#endif
