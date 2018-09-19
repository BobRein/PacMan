/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

//#include "Characters.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "constants.h"
#include "point.h"

using namespace std;

void initFont();
void loadFont(string, char[FONT_SIZE][FONT_SIZE]);
void printLetter(char letter[FONT_SIZE][FONT_SIZE],
                  int r, int c, Point p, SDL_Plotter &g,
                  Color color, int scale);
void printString(string, Point, SDL_Plotter&, int, Color);

class Letter {
    private:
        char character;
        char data[FONT_SIZE][FONT_SIZE];
        Color color;
        int scale;
        Point location;
    public:
        Letter();
        Letter(char);

        /*
         Description: Returns the character value
         Return: Character
         Precondition: None
         Postcondition: Character value is returned
         */
        char getChar() const;
         /*
         Description: Returns the color of the character
         Return: Color
         Precondition: None
         Postcondition: Character color is returned
         */
        Color getColor() const;
         /*
         Description: Returns the scale of the character
         Return: Integer
         Precondition: None
         Postcondition: Character scale is returned
         */
        int getScale() const;
         /*
         Description: Returns the location of the character
         Return: Point
         Precondition: None
         Postcondition: Character location is returned
         */
        Point getLocation() const;
         /*
         Description: Sets the value of the character
         Return: Nothing
         Precondition: A character exists
         Postcondition: Character value is set
         */
        void setChar(char);
         /*
         Description: Sets the color of the character
         Return: Nothing
         Precondition: A Color class exists
         Postcondition: Character color is set
         */
        void setColor(Color);
         /*
         Description: Sets the location of the character
         Return:  Nothing
         Precondition: A Point class exists
         Postcondition: Character location is set
         */
        void setLocation(Point);
         /*
         Description: Sets the scale of the character
         Return: Nothing
         Precondition: An integer value exists
         Postcondition: Character scale is set
         */
        void setScale(int);
         /*
         Description:Prints the character to the screen
         Return: Nothing
         Precondition: SDL_Plotter is passed by reference
         Postcondition: Character is printed to the screen
         */
        void print(SDL_Plotter&);
};

/*
 Description: Converts an integer to a string
 Return: String
 Precondition: Integer value exists
 Postcondition: Integer is converted to a string
 */
string toStr(int);

#endif // FONT_H_INCLUDED
