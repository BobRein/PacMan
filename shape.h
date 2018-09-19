#ifndef SHAPE_H_
#define SHAPE_H_

#include "point.h"

bool slope(double& m, const Point& p1, const Point& p2);

double yIntercept(const Point& p, double m);

void drawCircle(const Point& p, int r);

void drawLine(const Point& p1, const Point& p2);

void drawRect(const Point& p, const Point& b);

void drawTriangle(const Point& p1, const Point& p2, const Point& p3);

class Polygon {
	private:
		Point location;
	public:
		Point getLocation() const;

};



#endif /* SHAPE_H_ */
