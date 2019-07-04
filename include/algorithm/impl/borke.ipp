/*
Class for Borke Algorithm

Inherits from Triangulation
*/

#ifndef DELAUNAY_TRIANGULATION_ALGORITHM_BORKE_IPP_
#define DELAUNAY_TRIANGULATION_ALGORITHM_BORKE_IPP_

#include <algorithm>
#include <vector>
#include <ostream>
#include <istream>


namespace algorithm
{

template <int dimensions, typename Precision>
Borke<dimensions, Precision>::Borke(PointVector point_vector)
    : Triangulation<dimensions, Precision>(point_vector) 
{}

template <int dimensions, typename Precision>
void Borke<dimensions, Precision>::triangulate()
{
/* 
    Triangulation subroutine
    Takes as input n points
    Returned is a list of ntri triangular faces in the array v
    These triangles are arranged in a consistent clockwise order.
    The triangle array 'v' should be malloced to 3 * nv
    The vertex array pxyz must be big enough to hold 3 more points
    The vertex array must be sorted in increasing x values say 
*/
    std::sort(this->point_vector_.begin(), this->point_vector_.end(), point_comparison); 

    // pxyz: vector of points
    // v : vector of triangles
    // edges : vector of edges

    int n_points = this->point_vector_.size();

    int ntri; // size of v
    ITRIANGLE v[3 * n_points];

    int *complete = NULL;
    IEDGE *edges = NULL; 
    IEDGE *p_EdgeTemp;
    int nedge = 0;
    int trimax, emax;
    int status = 0;
    int inside;
    int i, j, k;
    double xp, yp, x1, y1, x2, y2, x3, y3, xc, yc, r;
    double xmin, xmax, ymin, ymax, xmid, ymid;
    double dx, dy, dmax; 

    /* Allocate memory for the completeness list, flag for each triangle */
    trimax = 4 * n_points;
    complete = new int[trimax];

    /* Allocate memory for the edge list */
    emax = 200;
    edges = new IEDGE[emax];

    /* 
        Find the maximum and minimum vertex bounds.
        This is to allow calculation of the bounding triangle 
    */

    xmin = this->point_vector_[0].coordinates_[0];
    ymin = this->point_vector_[0].coordinates_[1];
    xmax = xmin;
    ymax = ymin;
    for(i = 1; i < n_points; i++)
    {
        if (this->point_vector_[i].coordinates_[0] < xmin) xmin = this->point_vector_[i].coordinates_[0];
        if (this->point_vector_[i].coordinates_[0] > xmax) xmax = this->point_vector_[i].coordinates_[0];
        if (this->point_vector_[i].coordinates_[1] < ymin) ymin = this->point_vector_[i].coordinates_[1];
        if (this->point_vector_[i].coordinates_[1] > ymax) ymax = this->point_vector_[i].coordinates_[1];
    }
    dx = xmax - xmin;
    dy = ymax - ymin;
    dmax = (dx > dy) ? dx : dy;
    xmid = (xmax + xmin) / 2.0;
    ymid = (ymax + ymin) / 2.0;

    /* 
        Set up the supertriangle
        This is a triangle which encompasses all the sample points.
        The supertriangle coordinates are added to the end of the
        vertex list. The supertriangle is the first triangle in
        the triangle list. 
    */
    std::array<Precision, dimensions> coord;

    coord[0] = xmid - 20 * dmax;
    coord[1] = ymid - dmax;
    this->point_vector_.emplace_back(coord);

    coord[0] = xmid;
    coord[1] = ymid + 20 * dmax;
    this->point_vector_.emplace_back(coord);

    coord[0] = xmid + 20 * dmax;
    coord[1] = ymid - dmax;
    this->point_vector_.emplace_back(coord);

    v[0].p1 = n_points;
    v[0].p2 = n_points + 1;
    v[0].p3 = n_points + 2;
    complete[0] = false;
    ntri = 1;


    /* Include each point one at a time into the existing mesh */
    for(i = 0; i < n_points; i++) // for each point
    {
        xp = this->point_vector_[i].coordinates_[0];
        yp = this->point_vector_[i].coordinates_[1];
        nedge = 0;
        
        /*
            Set up the edge buffer.
            If the point (xp,yp) lies inside the circumcircle then the
            three edges of that triangle are added to the edge buffer
            and that triangle is removed.
        */

        for(j = 0; j < ntri; j++)
        {
            if (complete[j]) continue;

            x1 = this->point_vector_[v[j].p1].coordinates_[0];
            y1 = this->point_vector_[v[j].p1].coordinates_[1];
            x2 = this->point_vector_[v[j].p2].coordinates_[0];
            y2 = this->point_vector_[v[j].p2].coordinates_[1];
            x3 = this->point_vector_[v[j].p3].coordinates_[0];
            y3 = this->point_vector_[v[j].p3].coordinates_[1];

            inside = this->circumcircle(xp, yp, x1, y1, x2, y2, x3, y3, xc, yc, r);
            if (xc + r < xp)
            {
                /* Suggested: if (xc + r + EPSILON < xp) */
                complete[j] = true;   
            }
            if (inside)
            {
                /* Check that we haven't exceeded the edge list size */
                if(nedge + 3 >= emax) 
                {
                    emax += 100;
                    p_EdgeTemp = new IEDGE[emax];
                    for (int i = 0; i < nedge; i++) { // Fix by John Bowman
                        p_EdgeTemp[i] = edges[i];   
                    }
                    delete []edges;
                    edges = p_EdgeTemp;
                }
                
                edges[nedge+0].p1 = v[j].p1;
                edges[nedge+0].p2 = v[j].p2;
                edges[nedge+1].p1 = v[j].p2;
                edges[nedge+1].p2 = v[j].p3;
                edges[nedge+2].p1 = v[j].p3;
                edges[nedge+2].p2 = v[j].p1;
                nedge += 3;
                v[j] = v[ntri-1];
                complete[j] = complete[ntri-1];
                ntri--;
                j--;
            }
        }

        /*
            Tag multiple edges
            Note: if all triangles are specified anticlockwise then all
            interior edges are opposite pointing in direction.
        */

        for(j = 0; j < nedge - 1; j++)
        {
            for(k = j + 1; k < nedge; k++)
            {
                if((edges[j].p1 == edges[k].p2) && (edges[j].p2 == edges[k].p1))
                {
                    edges[j].p1 = -1;
                    edges[j].p2 = -1;
                    edges[k].p1 = -1;
                    edges[k].p2 = -1;
                }
                /* Shouldn't need the following, see note above */
                if((edges[j].p1 == edges[k].p1) && (edges[j].p2 == edges[k].p2))
                {
                    edges[j].p1 = -1;
                    edges[j].p2 = -1;
                    edges[k].p1 = -1;
                    edges[k].p2 = -1;
                }
            }
        }

        /*  
            Form new triangles for the current point
            Skipping over any tagged edges.
            All edges are arranged in clockwise order.
        */

        for(j = 0; j < nedge; j++) 
        {
            if(edges[j].p1 < 0 || edges[j].p2 < 0)
            continue;
            v[ntri].p1 = edges[j].p1;
            v[ntri].p2 = edges[j].p2;
            v[ntri].p3 = i;
            complete[ntri] = false;
            ntri++;
        }

    } // for each point

    /*
        Remove triangles with supertriangle vertices
        These are triangles which have a vertex number greater than n_points
    */
    
    for(i = 0; i < ntri; i++) 
    {
        if (v[i].p1 >= n_points || v[i].p2 >= n_points || v[i].p3 >= n_points) 
        {
            v[i] = v[ntri-1];
            ntri--;
            i--;
        }
    }

    delete[] edges;
    delete[] complete;
}

template <int dimensions, typename Precision>
bool Borke<dimensions, Precision>::circumcircle(double xp, double yp, double x1, double y1, double x2, 
double y2, double x3, double y3, double &xc, double &yc, double &r)
{
/*
    Return true if a point (xp,yp) is inside the circumcircle made up
    of the points (x1,y1), (x2,y2), (x3,y3)
    The circumcircle centre is returned in (xc,yc) and the radius r
    Note: A point on the edge is inside the circumcircle
*/

    double m1, m2, mx1, mx2, my1, my2;
    double dx, dy, rsqr, drsqr;

    /* Check for coincident points */
    if (abs(y1 - y2) < EPSILON && abs(y2 - y3) < EPSILON)
    {
        return false;
    }
    
    if (abs(y2-y1) < EPSILON)
    { 
        m2 = - (x3 - x2) / (y3 - y2);
        mx2 = (x2 + x3) / 2.0;
        my2 = (y2 + y3) / 2.0;
        xc = (x2 + x1) / 2.0;
        yc = m2 * (xc - mx2) + my2;
    } else if (abs(y3 - y2) < EPSILON)
    { 
        m1 = - (x2 - x1) / (y2 - y1);
        mx1 = (x1 + x2) / 2.0;
        my1 = (y1 + y2) / 2.0;
        xc = (x3 + x2) / 2.0;
        yc = m1 * (xc - mx1) + my1;
    } else 
    {
        m1 = - (x2 - x1) / (y2 - y1); 
        m2 = - (x3 - x2) / (y3 - y2); 
        mx1 = (x1 + x2) / 2.0; 
        mx2 = (x2 + x3) / 2.0;
        my1 = (y1 + y2) / 2.0;
        my2 = (y2 + y3) / 2.0;
        xc = (m1 * mx1 - m2 * mx2 + my2 - my1) / (m1 - m2); 
        yc = m1 * (xc - mx1) + my1; 
    }
    
    dx = x2 - xc;
    dy = y2 - yc;
    rsqr = dx * dx + dy * dy;
    r = sqrt(rsqr); 
    dx = xp - xc;
    dy = yp - yc;
    drsqr = dx * dx + dy * dy;

    return drsqr <= rsqr;
}

template <int dimensions, typename Precision>
bool Borke<dimensions, Precision>::point_comparison(Point<dimensions, Precision> p1, Point<dimensions, Precision> p2)
{
    auto p1_coord = p1.coordinates_;
    auto p2_coord = p2.coordinates_;
    return p1_coord[0] > p2_coord[0];
}

}

#endif
