#ifndef DELAUNAY_TRIANGULATION_H_
#define DELAUNAY_TRIANGULATION_H_

class Point {};

class Triangulation {
    Triangulation(Point a, Point b, Point c);
    void insert(Point a);
};

#endif
