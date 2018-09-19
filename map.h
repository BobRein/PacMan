/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef MAP_H_
#define MAP_H_

//Constants file
#include "constants.h"

//Standard libraries
#include <fstream>
#include <string>
#include <time.h>
#include <vector>

#include "circle.h"
#include "point.h"
#include "ghost.h"
#include "tile.h"
#include "font.h"

//Forward declarations
class PacMan;
class SDL_Plotter;

using namespace std;

class Map {
private:
    Tile tiles[MAP_WIDTH * MAP_HEIGHT];
    Circle pickups[MAP_WIDTH * MAP_HEIGHT];
    long last;
public:
    //Initialize map, does not load a file
    Map();
    //Initialize map with file name
    Map(string, Ghost[], int&);

    /*
     Description: Determines if PacMan is in contact with any tiles
     Return: Boolian
     Precondition: A Circle class exists
     Postcondition: PacMan is in contact or not in contact with a tile
     */
    bool collides(Circle);

    /*
     Description: Returns how many dots PacMan has eaten
     Return: Integer
     Precondition: None
     Postcondition: The amount of dots PacMan has eaten is returned
     */
    int pickupCount() const;

    /*
     Description: Determines whether or not to switch map mode
     Return: Nothing
     Precondition: SDL_Plotter is passed by reference and a boolian value exists
     Postcondition: Map mode is switched if boolian is true
     */
    void draw(SDL_Plotter&, bool);

    /*
     Description: Loads the map layout
     Return: Nothing
     Precondition: A string exists
     Postcondition: Map layout is loaded
     */
    void loadMap(string str, Ghost[], int&);

    /*
     Description: Sets the the tile color of the tile
     Return: Nothing
     Precondition: A Color class exists
     Postcondition: Tile color is set
     */
    void setTileColor(Color);

    /*
     Description: Determines where to put every tile
     Return: Nothing
     Precondition: A Point and Tile class both exists, they are both constants and
     passed by reference.
     Postcondition: The tiles are put in their correct place
     */
    void setTile(const Point&, const Tile&);

    /*
     Description: Updates the score on the map
     Return: Nothing
     Precondition: SDL_Plotter and PacMan are passed by reference
     Postcondition: Map score is updated
     */
    void update(SDL_Plotter&, PacMan&, double&, bool);
};

#endif /* MAP_H_ */


