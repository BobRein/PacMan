/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */
#include "line.h"
#include "SDL_Plotter.h"

Line::Line(const Point& a, const Point& b, const Color& c) {
	setP1(a);
	setP2(b);
	setColor(c);
}

Color Line::getColor() const {
	return color;
}

Point Line::getP1() const {
	return p1;
}
Point Line::getP2() const {
	return p2;
}


void Line::draw(SDL_Plotter& g) {
    drawLine(g, getP1(), getP2(), getColor());
}

void Line::setColor(const Color& c) {
	color = c;
}

void Line::setP1(const Point& p) {
	p1 = p;
}
void Line::setP2(const Point& p) {
	p2 = p;
}

bool Line::slope(double& m, const Point& p1, const Point& p2) {
	bool hasSlope = p1.x != p2.x;
	if(hasSlope) {
		m = (p2.y - p1.y) / (p2.x - p1.x);
	}
	return hasSlope;
}

double Line::yInt(const Point& p, double m) {
	double b = p.x * m + p.y;
	return b;
}

bool slope(double& m, const Point& p1, const Point& p2) {
	bool hasSlope = p1.x != p2.x;
	if(hasSlope) {
		m = (p2.y - p1.y) / (p2.x - p1.x);
	}
	return hasSlope;
}

double yInt(const Point& p, double m) {
	double b = p.x * m + p.y;
	return b;
}

void drawLine(SDL_Plotter& g, const Point& p1, const Point& p2, const Color& c) {
    int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    dx1 = fabs(dx);
    dy1 = fabs(dy);
    px = 2 * dy1 - dx1;
    py = 2 * dx1 - dy1;

    if(dy1 <= dx1) {
    	if(dx >= 0) {
    		x = p1.x;
    		y = p1.y;
    		xe = p2.x;
    	} else {
    		x = p2.x;
    		y = p2.y;
    		xe = p1.x;
    	}
    	plot(g, Point(x, y), c);
    	for(i = 0; x < xe; i++) {
    		x += 1;
    		if(px < 0) {
    			px += 2 * dy1;
    		} else {
    			if((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
    				y += 1;
    			} else {
    				y -= 1;
    			}
    			px += 2 * (dy1 - dx1);
    		}
    		plot(g, Point(x, y), c);
    	}
    } else {
    	if(dy >= 0) {
    		x = p1.x;
    		y = p1.y;
    		ye = p2.y;
    	} else {
    		x = p2.x;
    		y = p2.y;
    		ye = p1.y;
    	}
    	plot(g, Point(x, y), c);
    	for(i = 0; y < ye; i++) {
    		y += 1;
    		if(py <= 0) {
    			py += 2 * dx1;
    		} else {
    			if((dx < 0 && dy < 0) || (dx > 0 && dy > 0)) {
    				x += 1;
    			} else {
    				x -= 1;
    			}
    			py += 2 * (dx1 - dy1);
    		}
    		plot(g, Point(x, y), c);
    	}
    }
}
