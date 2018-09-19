/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef POINT_H_
#define POINT_H_

#include <cmath>
#include "constants.h"

class SDL_Plotter;
struct Color;

struct Point {
	int x, y;
	Point()
	{x = y = 0;}

	Point(int, int);

    /*
     Description: Determines the distance between two points
     Return: Double
     Precondition: A Point class is a constant and passed by reference
     Postcondition: Distance between two points is determined
     */
	double distTo(const Point&);
};

void plot(SDL_Plotter& g, const Point&, const Color&);

#endif /* POINT_H_ */
