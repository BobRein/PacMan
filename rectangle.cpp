/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */
#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include "pacman.h"
#include "SDL_Plotter.h"

Rectangle::Rectangle() {
	color = black;
	direction = STATIC;
	isFilled = true;
	lr = Point();
	ul = Point();
	direction = STATIC;
}

Rectangle::Rectangle(const Point& _ul, const Point& _lr, const Color& c) {
	ul = _ul;
	lr = _lr;
	color = c;
	isFilled = true;
	direction = STATIC;
}

Rectangle::Rectangle(const Point& _ul, const Point& _lr, const Color& c, bool filled){
	ul =_ul;
	lr = _lr;
	color = c;
	isFilled = filled;
}

bool Rectangle::collides(Circle c) {
    bool flag = false;
    //Top & Bottom
    for(int x = ul.x; x <= lr.x && !flag; x++) {
        if(Point(x, ul.y).distTo(c.getLocation()) <= c.getRadius() ||
           Point(x, lr.y).distTo(c.getLocation()) <= c.getRadius()) {
            flag = true;
        }
    }

    //Left & Right
    for(int y = ul.y; y <= lr.y && !flag; y++) {
        if(Point(ul.x, y).distTo(c.getLocation()) <= c.getRadius() ||
           Point(lr.x, y).distTo(c.getLocation()) <= c.getRadius()) {
            flag = true;
        }
    }

	return flag;
}

bool Rectangle::getFilled() const {
	return isFilled;
}

Color Rectangle::getColor() const {
	return color;
}

Direction Rectangle::getDirection() const {
	return direction;
}

Point Rectangle::getUL() const {
    return ul;
}

Point Rectangle::getLR() const {
    return lr;
}

int Rectangle::getThickness() const {
    return thickness;
}


void Rectangle::draw(SDL_Plotter& g) {
    if(isFilled) {
        for(int y = ul.y; y < lr.y; y++) {
            drawLine(g, Point(ul.x, y), Point(lr.x, y), color);
        }
    } else {
        for(int i = 0; i < thickness; i++) {
            //Top
            drawLine(g, Point(ul.x, ul.y + i), Point(lr.x, ul.y + i), color);
            //Left
            drawLine(g, Point(ul.x + i, ul.y), Point(ul.x + i, lr.y), color);
            //Bottom
            drawLine(g, Point(lr.x, lr.y - i), Point(ul.x, lr.y - i), color);
            //Right
            drawLine(g, Point(lr.x - i, lr.y), Point(lr.x - i, ul.y), color);
        }
    }
}

void Rectangle::setColor(const Color& c) {
	color = c;
}

void Rectangle::setDirection(Direction dir) {
	direction = dir;
}

void Rectangle::setFilled(bool filled) {
	isFilled = filled;
}

void Rectangle::setLR(Point p) {
    lr = p;
}

void Rectangle::setUL(Point p) {
    ul = p;
}

void Rectangle::setThickness(int n) {
    thickness = n;
}
