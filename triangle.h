/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "color.h"
#include "point.h"

class Line;
class SDL_Plotter;

class Triangle {
	private:
		Color color;
		Point p1, p2, p3;

	public:
		Triangle();

		Triangle(const Point& x, const Point& y, const Point& z, const Color& c);

        /*
         Description: Returns the color for the triangle
         Return: Color
         Precondition: None
         Postcondition: Triangle color is returned
         */
		Color getColor() const;

        /*
         Description: Returns the first point of the triangle
         Return: Point
         Precondition: None
         Postcondition: First point is returned
         */
        Point getP1() const;

        /*
         Description: Returns the second point of the triangle
         Return: Point
         Precondition: None
         Postcondition: Second point is returned
         */
		Point getP2() const;

        /*
         Description: Returns the third point of the triangle
         Return: Point
         Precondition: None
         Postcondition: Third point is returned
         */
		Point getP3() const;

        /*
         Description: Draws the triangle to the screen
         Return: Nothing
         Precondition: SDL_Plotter is passed by reference and boolian is true
         Postcondition: Triangle is drawn to screen
         */
		void draw(SDL_Plotter& g,bool filled);

        /*
         Description: Sets the color for the triangle
         Return: Nothing
         Precondition: A Color class exists that is a constant and passed by reference
         Postcondition: Color of triangle is set
         */
		void setColor(const Color& c);

        /*
         Description: Sets the first point of the triangle
         Return: Nothing
         Precondition: A Point class exists that is a constant and passed by reference
         Postcondition: First point is set
         */
		void setP1(const Point& p);

        /*
         Description: Sets the second point of the triangle
         Return: Nothing
         Precondition: A Point class exists that is a constant and passed by reference
         Postcondition: Second point is set
         */
		void setP2(const Point& p);

        /*
         Description: Sets the second point of the triangle
         Return: Nothing
         Precondition: A Point class exists that is a constant and passed by reference
         Postcondition: Second point is set
         */
		void setP3(const Point& p);
};

#endif /* TRIANGLE_H_ */
