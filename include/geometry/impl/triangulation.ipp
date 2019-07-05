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
std::vector<Triangle<dimensions, Precision>*> Triangulation<dimensions, Precision>::incremental_triangulation()
{
	TriangleVector triangulation;

	/* Get bounds */
	Precision xmin, ymin, xmax, ymax, dx, dy, dmax, xmid, ymid;
	int n_points = this->point_vector_.size();
	
	std::sort(this->point_vector_.begin(), this->point_vector_.end(), point_comparison);

	xmin = this->point_vector_[0]->coordinates_[0];
    ymin = this->point_vector_[0]->coordinates_[1];
    xmax = xmax;
    ymax = ymin;

	for (auto point_it = this->point_vector_.begin(); 
		 point_it != this->point_vector_.end(); ++point_it)
	{
        if ((*point_it)->coordinates_[0] > xmax) { xmax = (*point_it)->coordinates_[0]; }
        if ((*point_it)->coordinates_[1] < ymin) { ymin = (*point_it)->coordinates_[1]; }
        if ((*point_it)->coordinates_[1] > ymax) { ymax = (*point_it)->coordinates_[1]; }
    }

	dx = xmax - xmin;
	dy = ymax - ymin;
	dmax = std::max(dx, dy);
	xmid = (xmax + xmin) / 2.0;
	ymid = (ymax + ymin) / 2.0;

	/* Set up supertriangle */
	std::array<Precision, dimensions> coord;
	std::array<Point_*, 3> points;
    coord[2] = 0;
	
	coord[0] = xmid - 20 * dmax;
    coord[1] = ymid - dmax;
   	Point_* p1 = new Point_(n_points, coord);
    points[0] = p1;
    this->point_vector_.push_back(p1);

	coord[0] = xmid;
    coord[1] = ymid + 20 * dmax;
    Point_* p2 = new Point_(n_points + 1, coord);
    points[1] = p2;
    this->point_vector_.push_back(p2);

    coord[0] = xmid + 20 * dmax;
    coord[1] = ymid - dmax;
    Point_* p3 = new Point_(n_points + 2, coord);
    points[2] = p3;
    this->point_vector_.push_back(p3);

	Triangle_* supertriangle = new Triangle_(points);
	triangulation.push_back(supertriangle);

	/* Include each point one at a time into the existing mesh */
	bool in_circumcircle;
	Precision xcentre, ycentre, radio;
	Line_ edges[1000];
	int n_edges;
    
	for (auto point_it = this->point_vector_.begin(); 
		 point_it != this->point_vector_.end(); ++point_it)
	{
		if ((*point_it)->id_ >= n_points) { break; }

		n_edges = 0;

		auto triangle_it = triangulation.begin();
		while (triangle_it != triangulation.end())
		{
			if ((*triangle_it)->checked) { continue; }

			in_circumcircle = this->circumcircle((*triangle_it), (*point_it), 
				xcentre, ycentre, radio);
			if (xcentre + radio < (*point_it)->coordinates_[0])
			{
				(*triangle_it)->checked = true;
			}
			if (in_circumcircle)
			{
				std::array<Point_*, 2> pair1;
				pair1[0] = (*triangle_it)->points_[0];
				pair1[1] = (*triangle_it)->points_[1];
				edges[n_edges] = Line_(pair1);

				std::array<Point_*, 2> pair2;
				pair2[0] = (*triangle_it)->points_[0];
				pair2[1] = (*triangle_it)->points_[2];
				edges[n_edges + 1] = Line_(pair2);

				std::array<Point_*, 2> pair3;
				pair3[0] = (*triangle_it)->points_[1];
				pair3[1] = (*triangle_it)->points_[2];
				edges[n_edges + 2] = Line_(pair3);
				
				n_edges += 3;

				triangle_it = triangulation.erase(triangle_it);
			} else
			{
				++triangle_it;
			}
		}

		for (int i = 0; i < n_edges - 1; ++i)
		{
			for (int j = i + 1; j < n_edges; ++j)
			{
				if ((edges[i].points_[0] == edges[j].points_[1]) 
					&& (edges[i].points_[1] == edges[j].points_[0]))
				{
					edges[i].points_[1]->id_ = -1;
					edges[i].points_[0]->id_ = -1;
					edges[j].points_[1]->id_ = -1;
					edges[j].points_[0]->id_ = -1;
				}
				if ((edges[i].points_[0] == edges[j].points_[0]) 
					&& (edges[i].points_[1] == edges[j].points_[1]))
				{
					edges[i].points_[1]->id_ = -1;
					edges[i].points_[0]->id_ = -1;
					edges[j].points_[1]->id_ = -1;
					edges[j].points_[0]->id_ = -1;
				}
			}
		}
		
		for (int i = 0; i < n_edges; ++i)
		{
			if (edges[i].points_[0]->id_ == -1) { continue; }
			
			std::array<Point_*, 3> triangle_points;
			triangle_points[0] = edges[i].points_[0];
			triangle_points[1] = edges[i].points_[1];
			triangle_points[2] = (*point_it);

			Triangle_* triangle = new Triangle_(triangle_points);
			triangulation.push_back(triangle);
		}
	}

	/* Delete supertriangle edges */
	auto triangle_it = triangulation.begin();
	while (triangle_it != triangulation.end())
	{
		if ((*triangle_it)->points_[0]->id_ >= n_points 
            || (*triangle_it)->points_[1]->id_ >= n_points 
            || (*triangle_it)->points_[2]->id_ >= n_points) 
		{
			triangle_it = triangulation.erase(triangle_it);
		} else
		{
			++triangle_it;
		}
	}

	return triangulation;
}

template <int dimensions, typename Precision>
std::vector<Triangle<dimensions, Precision>> randomized_incremental_triangulation()
{}

template <int dimensions, typename Precision>
bool Triangulation<dimensions, Precision>::circumcircle(Triangle_ *triangle, Point_ *point, 
	Precision &xcentre, Precision &ycentre, Precision &radio)
{
	const double EPSILON = 0.000001;
	Precision xp, yp, x1, y1, x2, y2, x3, y3,
			  m1, mx1, my1, m2, mx2, my2,
			  dx, dy, rsqr, drsqr;
	
	xp = point->coordinates_[0];
	yp = point->coordinates_[1];

	x1 = triangle->points_[0]->coordinates_[0];
	y1 = triangle->points_[0]->coordinates_[1];
	x2 = triangle->points_[1]->coordinates_[0];
	y2 = triangle->points_[1]->coordinates_[1];
	x3 = triangle->points_[2]->coordinates_[0];
	y3 = triangle->points_[2]->coordinates_[1];
	
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
int Triangulation<dimensions, Precision>::point_comparison(Point<dimensions, Precision>* p1, Point<dimensions, Precision>* p2)
{
    auto p1_coord = p1->coordinates_;
    auto p2_coord = p2->coordinates_;
	if (p1_coord[0] < p2_coord[0]) { return -1;}
	else if (p1_coord[0] > p2_coord[0]) {return 1;}
    else {return 0;}
}

template <int dimensions, typename Precision>
std::vector<Point<dimensions, Precision>*> Triangulation<dimensions, Precision>::get_points()
{
	return this->point_vector_;
}

} // namespace geometry

#endif
