/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED
#include "circle.h"
#include <cmath>
#include "pacman.h"
#include "rectangle.h"
//Forward declarations
class Map;
class Rectangle;
class SDL_Plotter;
struct Point;

using namespace std;

class Ghost {
	private:
		Circle circle;
		Rectangle rectangle;
		Triangle tri1;
		Triangle tri2;
		Triangle tri3;
		Direction nextDirection;
        double last;
        int speed;
        //Color color;
	public:
		Ghost();

		Ghost(Point);

        /*
         Description: Determines if the ghost is colliding
         Return: Boolian
         Precondition: A Rectangle class is a constant and passed by reference
         Postcondition: Ghost collision is determined
         */
		bool collides(const Rectangle&);
        /*
         Description: Returns the circle of the ghost
         Return: Circle
         Precondition: None
         Postcondition: Circle of ghost is returned
         */
		Circle getCircle() const;
        /*
         Description: Returns the direction of the ghost
         Return: Direction
         Precondition: None
         Postcondition: Direction of ghost is returned
         */
		Direction getDirection() const;
        /*
         Description: Returns the radius of the ghost
         Return: Double
         Precondition: None
         Postcondition: Ghost radius is returned
         */
		double getRadius() const;
        /*
         Description: Returns the location of the ghost
         Return: Point
         Precondition: None
         Postcondition: Location of ghost is returned
         */
		Point getLocation() const;
        /*
         Description: Returns the speed of the ghost
         Return: Integer
         Precondition: None
         Postcondition: Speed of ghost is returned
         */
		int getSpeed();
        /*
         Description: Draws the ghost to the screen
         Return: Nothing
         Precondition: SDL_Plotter is passed by reference
         Postcondition: Ghost is drawn to the screen
         */
		void draw(SDL_Plotter&);
        /*
         Description: Moves the ghost on the screen
         Return: Nothing
         Precondition: SDL_Plotter is passed by reference, Map and PacMan
         classes are passed by reference, Boolian value exists, and an array of
         Ghost exists
         Postcondition: Ghost is moved on the screen
         */
		void move(SDL_Plotter& g, Map& m,PacMan& pac, bool afraid,Ghost listOfGhosts[]);
        /*
         Description: Updates the screen
         Return: Nothing
         Precondition: SDL_Plotter is passed by reference
         Postcondition: Screen is updated
         */
		void update(SDL_Plotter&);
        /*
         Description: Sets the direction of the ghost
         Return: Nothing
         Precondition: Direction exists
         Postcondition: Direction of ghost is set
         */
		void setDirection(Direction);
        /*
         Description: Sets the location of the ghost
         Return: Nothing
         Precondition: A Point class exists is a constant and passed by reference
         Postcondition: Location of ghost is set
         */
		void setLocation(const Point&);
        /*
         Description: Sets the radius of the ghost
         Return: Nothing
         Precondition: Integer value exists
         Postcondition: Radius of ghost is set
         */
		void setRadius(int);
        /*
         Description: Sets the speed of the ghost
         Return: Nothing
         Precondition: Integer value exists
         Postcondition: Speed of ghost is set
         */
		void setSpeed(int);
        /*
         Description: Sets the color of the ghost
         Return: Nothing
         Precondition: A Color class exists
         Postcondition: Color of ghost is set
         */
		void setColor(Color c);
        /*
         Description: Determines the attack path of the ghost
         Return: Nothing
         Precondition: Map, PacMan, and Direction are passed by reference, an array
         of ghost exists
         Postcondition: Attack path of ghost is determined
         */
        void getAttackDirection (Map& m1,PacMan& pac1, Direction& newDir,Ghost list []);
        /*
         Description: Determines the retreat path of the ghost
         Return: Nothing
         Precondition: Map, PacMan, and Direction are passed by reference, an array
         of ghost exists
         Postcondition: Retreat path of ghost is determined
         */
        void getRetreatDirection(Map& m1,PacMan& pac1, Direction& nextDir,Ghost list []);
        /*
         Description: Determines if a ghost is colliding with another
         Return: Boolian
         Precondition: A ghost array exists, a circle class exists
         Postcondition: Ghost on ghost collision is determined
         */
        bool collidesWithOtherGhost (Ghost list1 [], Circle c);
};


#endif // GHOST_H_INCLUDED
