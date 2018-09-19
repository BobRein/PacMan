/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <cmath>
#include "color.h"
#include "point.h"

//Forward declarations
class Rectangle;
class SDL_Plotter;

using namespace std;

class Circle {
	private:
		bool isVisible;
		Color color;
		Direction direction;
		double radius;
		Point location;
	public:
		Circle();

		Circle(const Point&, double, const Color&, Direction = STATIC);

        /*
         Description: Determines if a circle is colliding with another object
         Return: Boolian
         Precondition: A Circle class that is a constant and passed by reference exists
         Postcondition: Circle collision is returned as true or false
         */
		bool collides(const Circle&);

        /*
         Description: Determines if the circle is still visible to the screen
         Return: Boolian
         Precondition: None
         Postcondition: Visibility of circle is determined
         */
		bool getVisible() const;

        /*
         Description: Returns the color for the circle
         Return: Color
         Precondition: None
         Postcondition: Circle color is returned
         */
		Color getColor() const;

        /*
         Description: Returns the direction of the circle
         Return: Direction
         Precondition: None
         Postcondition: Circle direction is returned
         */
		Direction getDirection() const;

        /*
         Description: Returns the diameter of the circle
         Return: Double
         Precondition: None
         Postcondition: Circle diameter is returned
         */
		double getDiameter() const;

        /*
         Description: Returns the radius of the circle
         Return: Double
         Precondition: None
         Postcondition: Circle radius is returned
         */
		double getRadius() const;

        /*
         Description: Returns the location of the circle
         Return: Point
         Precondition: None
         Postcondition: Circle location is returned
         */
		Point getLocation() const;

        /*
         Description: Draws the circle to the screen
         Return: Nothing
         Precondition: SDL_PLotter is passed by reference
         Postcondition: Circle is drawn to screen
         */
		void draw(SDL_Plotter&);

        /*
         Description: Moves the circle
         Return: Nothing
         Precondition: None
         Postcondition: Circle is moved
         */
		void move();

        /*
         Description: Sets the color for the circle
         Return: Nothing
         Precondition: A Color class exists that is a constant and passed by reference
         Postcondition: Circle color is set
         */
		void setColor(const Color&);

        /*
         Description: Sets the direction of the circle
         Return: Nothing
         Precondition: Direction exists
         Postcondition: Circle direction is set
         */
		void setDirection(Direction);

        /*
         Description: Sets the radius of the circle
         Return: Nothing
         Precondition: A double value exists
         Postcondition: Circle radius is set
         */
		void setRadius(double);

        /*
         Description: Sets the location of the circle
         Return: Nothing
         Precondition: A Point class exists that is a constant and passed by reference
         Postcondition: Circle location is set
         */
		void setLocation(const Point&);

        /*
         Description: Sets the visibility of the circle
         Return: Nothing
         Precondition: A boolian value exists
         Postcondition: Circle visibility is set
         */
		void setVisible(bool);

        /*
         Description: Updates the direction of the circle
         Return: Nothing
         Precondition: A character exists
         Postcondition: Circle direction is updated
         */
		void update(char);
};

void drawCircle(SDL_Plotter& g, const Point& p, int r, const Color& c);

#endif /* CIRCLE_H_ */
