#ifndef DELAUNAY_TRIANGULATION_H_
#define DELAUNAY_TRIANGULATION_H_

struct Point {
    Point() {};
};

struct Edge {
    Edge() {};
    bool illegal() {};
};

struct Triangle {
    Point a;
    Point b;
    Point c;
    Triangle() {};
    Triangle(Point _a, Point _b, Point _c) {};
    bool has_in_interior(Point _a) {};
    bool has_in_edge(Point _a) {};
    Edge get_edge(Point _a, Point _b) {};
    Edge get_lying_edge(Point _a) {};
    Point get_k(Point _a) {};
    Point get_third_vertex() {};
};

struct Triangulation {
    Triangle *triangles;
    Triangulation(Point _a, Point _b, Point _c) {};
    void insert(Point _a) {};
    void discard(Point _a) {};
    Triangle find_triangle(Point _a) {};
    Triangle get_incident(Edge _a) {};
};

#endif
