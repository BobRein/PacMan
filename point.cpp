/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */
#include "point.h"
#include "color.h"
#include "SDL_Plotter.h"

Point::Point(int a, int b) {
	x = a;
	y = b;
}

double Point::distTo(const Point& p) {
	return pow(pow(x - p.x, 2.0) + pow(y - p.y, 2.0), 0.5);
}

void plot(SDL_Plotter& g, const Point& p, const Color& c) {
	if(0 <= p.y && p.y <= W_HEIGHT) {
		g.plotPixel(p.x, p.y, c.r, c.g, c.b);
	}
}
