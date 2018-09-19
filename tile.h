/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef TILE_H_
#define TILE_H_

#include "circle.h"
#include "constants.h"
#include "point.h"
#include "rectangle.h"

//Forward declarations
class PacMan;

class Tile {
	private:
		Rectangle rect;
		TileType type;
		bool top, bottom, right, left;
	public:
		Tile();

		Tile(Rectangle, TileType);

        /*
         Description: States whether or not an object is colliding with a tile.
         Return: Boolian
         Precondition: A Circle class exists
         Postcondition: Boolian is returned
         */
		bool collides(Circle);

        /*
         Description: Returns the location of the tile
         Return: Point
         Precondition: None
         Postcondition: Location is returned
         */
		Point getLocation() const;

        /*
         Description: Returns the tile type
         Return: TileType
         Precondition: None
         Postcondition: TileType is returned
         */
		TileType getType() const;

		bool getTop() const;

		bool getBottom() const;

		bool getRight() const;

		bool getLeft() const;

        /*
         Description: Draws the tile to the screen
         Return: Nothing
         Precondition: SDL_PLotter is passed by reference
         Postcondition: Tile is drawn to screen
         */
		void draw(SDL_Plotter&);

        /*
         Description: Sets the color of the tile
         Return: Nothing
         Precondition: A Color class exists
         Postcondition: Tile color is set
         */
		void setColor(Color);

        /*
         Description: Sets the location of the tile
         Return: Nothing
         Precondition: A Point class exists that is a constant and passed by reference
         Postcondition: Tile location is set
         */
		void setLocation(const Point&);

        /*
         Description: Sets the type of the tile
         Return: Nothing
         Precondition: A TileType exists
         Postcondition: Tile type is set
         */
		void setType(TileType);

};

#endif /* TILE_H_ */
