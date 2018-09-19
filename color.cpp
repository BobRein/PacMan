/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */
#include "color.h"

Color::Color(int x, int y, int z) {
	r = x;
	g = y;
	b = z;
}

bool Color::match(Color c) {
    return r == c.r && g == c.g && b == c.b;
}
