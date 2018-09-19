/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */
#include "triangle.h"
#include "line.h"
#include "SDL_Plotter.h"

Triangle::Triangle() {

}

Triangle::Triangle(const Point& x, const Point& y, const Point& z, const Color& c) {
	setP1(x);
	setP2(y);
	setP3(z);
	setColor(c);
}

Color Triangle::getColor() const {
	return color;
}

Point Triangle::getP1() const {
	return p1;
}

Point Triangle::getP2() const {
	return p2;
}

Point Triangle::getP3() const {
	return p3;
}


void Triangle::draw(SDL_Plotter& g, bool filled) {
    Line ab(getP1(), getP2(), getColor());
    Line bc(getP2(), getP3(), getColor());
    Line ac(getP1(), getP3(), getColor());
    ab.draw(g);
    bc.draw(g);
    ac.draw(g);
	if (filled)
    {
		double delta = 0.000001;
		if(p2.x == p3.x) {
			if(p2.y > p3.y) {
				delta *= -1;
			}
			for(int y = p2.y; y != p3.y; y += 1) {
				drawLine(g, p1, Point(p2.x, y), getColor());
			}
		} else if(p2.y == p3.y) {
            if(p2.x > p3.x) {
                delta *= -1;
            }
            for(int x = p2.x; x != p3.x; x += 1) {
                drawLine(g, p1, Point(x, p2.y), getColor());
            }
		}

	    /*Point fakePoint;
	    Line filler(getP1(),fakePoint,getColor());
        if(p2.x==p3.x)
        {
            if(p2.y<p3.y) {
                fakePoint=p2;
            } else {
                fakePoint=p3;

            for (int i=0; i<abs(p2.y-p3.y);i++)
            {
               fakePoint.y++;
               filler.draw(g);
            }
        }
        if(p2.y==p3.y)
        {
            if(p2.x<p3.x)
                fakePoint=p2;
            else
                fakePoint=p3;
            for (int i=0; i<abs(p2.x-p3.x);i++)
            {
               fakePoint.x++;
               filler.draw(g);
            }
        }*/

    }

}

void Triangle::setColor(const Color& c) {
	color = c;
}

void Triangle::setP1(const Point& p) {
	p1 = p;
}

void Triangle::setP2(const Point& p) {
	p2 = p;
}

void Triangle::setP3(const Point& p) {
	p3 = p;
}
