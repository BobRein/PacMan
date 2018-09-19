/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */
#include "circle.h"
#include "constants.h"
#include "rectangle.h"
#include "SDL_Plotter.h"

Circle::Circle() {
	color = white;
	direction = STATIC;
	isVisible = false;
	location = Point();
	radius = 0;
}

Circle::Circle(const Point& p, double r, const Color& c, Direction dir) {
	color = c;
	direction = dir;
	isVisible = true;
	location = p;
	radius = r;
}

bool Circle::getVisible() const {
	return isVisible;
}

Color Circle::getColor() const {
	return color;
}

Direction Circle::getDirection() const {
	return direction;
}

double Circle::getDiameter() const {
	return radius * 2;
}

double Circle::getRadius() const {
	return radius;
}

Point Circle::getLocation() const {
	return location;
}


void Circle::draw(SDL_Plotter& g) {
	if(isVisible) {
		for(int x = -radius; x <= radius; x++) {
			for(int y = -radius; y <= radius; y++) {
				if(sqrt(pow(x, 2.0) + pow(y, 2.0)) <= radius) {
					plot(g, Point(location.x + x, location.y + y), color);
				}
			}
		}
	}
}

void Circle::move() {
	switch(getDirection()) {
		case UP:
			setLocation(Point(getLocation().x, getLocation().y - PLAYER_SPEED));
			break;
		case DOWN:
			setLocation(Point(getLocation().x, getLocation().y + PLAYER_SPEED));
			break;
		case LEFT:
			setLocation(Point(getLocation().x - PLAYER_SPEED, getLocation().y));
			break;
		case RIGHT:
			setLocation(Point(getLocation().x + PLAYER_SPEED, getLocation().y));
			break;
		case STATIC:
			break;
	}
}

void Circle::setColor(const Color& c) {
	color = c;
}

void Circle::setDirection(Direction dir) {
	direction = dir;
}

void Circle::setRadius(double r) {
	radius = r;
}

void Circle::setLocation(const Point& p) {
	location = p;
}

void Circle::setVisible(bool visible) {
	isVisible = visible;
}

void Circle::update(char c) {
	switch(c) {
		case 'W':
			setDirection(UP);
			cout << "UP" << endl;
			break;
		case 'S':
			setDirection(DOWN);
			cout << "DOWN" << endl;
			break;
		case 'A':
			setDirection(LEFT);
			cout << "LEFT" << endl;
			break;
		case 'D':
			setDirection(RIGHT);
			cout << "RIGHT" << endl;
			break;
		case UP_ARROW:
			setDirection(UP);
			cout << "UP" << endl;
			break;
		case DOWN_ARROW:
			setDirection(DOWN);
			cout << "DOWN" << endl;
			break;
		case LEFT_ARROW:
			setDirection(LEFT);
			cout << "LEFT" << endl;
			break;
		case RIGHT_ARROW:
			setDirection(RIGHT);
			cout << "RIGHT" << endl;
			break;
		case ' ':
			setDirection(STATIC);
			cout << "STOP" << endl;
			break;
	}
}

void drawCircle(SDL_Plotter& g, const Point& p, int r, const Color& c) {
    int dx, dy;
    for(int w = 0; w < r * 2; w++) {
        for(int h = 0; h < r * 2; h++) {
            dx = r - w;
            dy = r - h;
            if((dx * dx + dy * dy) <= (r * r)) {
                plot(g, Point(p.x + dx, p.y + dy), c);
            }
        }
    }
}

bool Circle::collides(const Circle& c) {
	bool flag = false;
	if(c.getLocation().distTo(getLocation()) <= radius + c.getRadius()) {
		flag = true;
	}
	return flag;
}
