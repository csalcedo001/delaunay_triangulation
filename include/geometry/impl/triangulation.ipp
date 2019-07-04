/*
Class for Triangulation

point_vector_: Vector of points
triangle_vector_: Vector of triangles
*/

#ifndef DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGULATION_IPP_
#define DELAUNAY_TRIANGULATION_GEOMETRY_TRIANGULATION_IPP_


namespace geometry
{

template <int dimensions, typename Precision>
Triangulation<dimensions, Precision>::Triangulation(PointVector point_vector)
	: point_vector_(point_vector) 
{}

template <int dimensions, typename Precision>
std::vector<Triangle<dimensions, Precision>> incremental_triangulation()
{
	std::sort(this->point_vector_.begin(), this->point_vector_.end(), point_comparison);
}

template <int dimensions, typename Precision>
std::vector<Triangle<dimensions, Precision>> randomized_incremental_triangulation()
{}

template <int dimensions, typename Precision>
bool Triangulation<dimensions, Precision>::circumcircle(Triangle_ triangle, Point_ point, 
	Precision &xcentre, Precision &ycentre, Precision &radio)
{
	const double EPSILON = 0.000001;
	Precision xp, yp, x1, y1, x2, y2, x3, y3,
			  m1, mx1, my1, m2, mx2, my2,
			  dx, dy, rsqr, drsqr;
	
	xp = point.coordinates_[0];
	yp = point.coordinates_[1];

	x1 = triangle.points_[0].coordinates_[0];
	y1 = triangle.points_[0].coordinates_[1];
	x2 = triangle.points_[1].coordinates_[0];
	y2 = triangle.points_[1].coordinates_[1];
	x3 = triangle.points_[2].coordinates_[0];
	y3 = triangle.points_[2].coordinates_[1];
	
	/* Check for coincident points */
	if(abs(y1 - y2) < EPSILON && abs(y2 - y3) < EPSILON) 
	{
		return false;
	}
	
	if (abs(y2 - y1) < EPSILON)
	{ 
		m2 = - (x3 - x2) / (y3 - y2);
		mx2 = (x2 + x3) / 2.0;
		my2 = (y2 + y3) / 2.0;
		xcentre = (x2 + x1) / 2.0;
		ycentre = m2 * (xcentre - mx2) + my2;
	} else if (abs(y3 - y2) < EPSILON)
	{ 
        m1 = - (x2 - x1) / (y2 - y1);
        mx1 = (x1 + x2) / 2.0;
        my1 = (y1 + y2) / 2.0;
        xcentre = (x3 + x2) / 2.0;
        ycentre = m1 * (xcentre - mx1) + my1;
    } else
	{
		m1 = - (x2 - x1) / (y2 - y1); 
		m2 = - (x3 - x2) / (y3 - y2); 
		mx1 = (x1 + x2) / 2.0; 
		mx2 = (x2 + x3) / 2.0;
		my1 = (y1 + y2) / 2.0;
		my2 = (y2 + y3) / 2.0;
		xcentre = (m1 * mx1 - m2 * mx2 + my2 - my1) / (m1 - m2); 
		ycentre = m1 * (xcentre - mx1) + my1; 
    }

	dx = x2 - xcentre;
	dy = y2 - ycentre;
	rsqr = dx * dx + dy * dy;
	radio = sqrt(rsqr); 
	dx = xp - xcentre;
	dy = yp - ycentre;
	drsqr = dx * dx + dy * dy;
	return drsqr <= rsqr;
}

template <int dimensions, typename Precision>
bool Triangulation<dimensions, Precision>::point_comparison(Point<dimensions, Precision> p1, Point<dimensions, Precision> p2)
{
    auto p1_coord = p1.coordinates_;
    auto p2_coord = p2.coordinates_;
    return p1_coord[0] > p2_coord[0];
}

template <int dimensions, typename Precision>
Triangulation<dimensions, Precision>::PointVector Triangulation<dimensions, Precision>::get_points()
{
	return this->point_vector_;
}

} // namespace geometry

#endif
