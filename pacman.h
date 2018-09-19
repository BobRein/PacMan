/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef PACMAN_H_
#define PACMAN_H_

#include <ctime>
#include "circle.h"
#include "triangle.h"

//Forward declarations
class Map;
class Rectangle;
class SDL_Plotter;
struct Point;

using namespace std;

class PacMan {
	private:
		Circle circle;
		Direction nextDir;
		double lastSound;
		Triangle mouth;
		double last;
		double lastMove;
		double lastAudio = clock();
		bool mouthOpen;
		int score;
		int speed;
	public:
		PacMan();

        /*
         Description:
         Return:
         Precondition:
         Postcondition:
         */
		//bool collides(const Rectangle&);

        /*
         Description: Returns the circle for PacMan
         Return: Circle
         Precondition: None
         Postcondition: PacMan's shape is returned
         */
		Circle getCircle() const;

        /*
         Description: Returns the direction of PacMan
         Return: Direction
         Precondition: None
         Postcondition: PacMan's direction is returned
         */
		Direction getDirection() const;

        /*
         Description: Returns the radius of PacMan
         Return: Double
         Precondition: None
         Postcondition: PacMan's radius is set
         */
		double getRadius() const;

        /*
         Description: Returns the location of PacMan
         Return: Point
         Precondition: None
         Postcondition: PacMan's location is returned
         */
		Point getLocation() const;

        /*
         Description: Returns the mouth of PacMan
         Return: Triangle
         Precondition: None
         Postcondition: PacMan's mouth is returned
         */
		Triangle getMouth() const;

        /*
         Description: Returns the players score
         Return: Integer
         Precondition: None
         Postcondition: Players score is returned
         */
		int getScore() const;

        /*
         Description: Returns PacMan's speed
         Return: Integer
         Precondition: None
         Postcondition: PacMan's speed is returned
         */
		int getSpeed() const;

        /*
         Description: Draws PacMan to the screen
         Return: Nothing
         Precondition: SDL_Plotter is passed by reference
         Postcondition: PacMan is drawn to the screen
         */
		void draw(SDL_Plotter&);

        /*
         Description: Moves PacMan on the screen
         Return: Nothing
         Precondition: SDL_Plotter and Map are passed by reference
         Postcondition: PacMan is moved on the screen
         */
		void move(SDL_Plotter&, Map&);

        /*
         Description: Updates PacMan's direction
         Return: Nothing
         Precondition: SDL_Plotter is passed by reference
         Postcondition: PacMan's direction is updated
         */
		void update(SDL_Plotter&);

        /*
         Description: Sets the direction of PacMan
         Return: Nothing
         Precondition: Direction exists
         Postcondition: PacMan's direction is set
         */
		void setDirection(Direction);

        /*
         Description: Sets the location of PacMan
         Return: Nothing
         Precondition: A Point class is a constant and passed by reference
         Postcondition: PacMan's location is set
         */
		void setLocation(const Point&);

        /*
         Description: Sets the radius of PacMan
         Return: Nothing
         Precondition: An integer exists
         Postcondition: PacMan's radius is set
         */
		void setRadius(int);

        /*
         Description: Sets the score of the player
         Return: Nothing
         Precondition: An integer exists
         Postcondition: Player's score is set
         */
		void setScore(int);

        /*
         Description: Sets the speed of PacMan
         Return: Nothing
         Precondition: An integer exists
         Postcondition: PacMan's speed is set
         */
		void setSpeed(int);
};

#endif /* PACMAN_H_ */
