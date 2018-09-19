/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */
#include "tile.h"
#include "pacman.h"
#include "rectangle.h"
#include "SDL_Plotter.h"

Tile::Tile() {
	setLocation(Point());
	top = bottom = right = left = false;
}

Tile::Tile(Rectangle _rect, TileType t) {
    rect = _rect;
    setType(t);
    top = bottom = right = left = false;
}

bool Tile::collides(Circle c) {
	bool flag = false;
	if(type != AIR) {
		flag = rect.collides(c);
	}
	return flag;
}
Point Tile::getLocation() const {
	return rect.getUL();
}
TileType Tile::getType() const {
	return type;
}
bool Tile::getTop() const {
	return top;
}
bool Tile::getBottom() const {
	return bottom;
}
bool Tile::getRight() const {
	return right;
}
bool Tile::getLeft() const {
	return left;
}

void Tile::draw(SDL_Plotter& g) {
	rect.draw(g);
}
void Tile::setColor(Color c) {
    rect.setColor(c);
}
void Tile::setLocation(const Point& p) {
	rect.setUL(p);
	rect.setLR(Point(p.x + TILE_SIZE, p.y + TILE_SIZE));
}
void Tile::setType(TileType t) {
	type = t;
	if(t == AIR) {
        rect.setColor(bkg);
	} else if(t == WALL) {
        rect.setColor(blue);
	}
}
