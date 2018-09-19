/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef COLOR_H_
#define COLOR_H_

struct Color {
	int r, g, b;

	Color()
	{r = g = b = 0;}

	Color(int, int, int);
    /*
     Description: Check if the color matches another color
     Return: Boolian
     Precondition: A Color class exists
     Postcondition: Color match is determined
     */
	bool match(Color);
};

#endif /* COLOR_H_ */
