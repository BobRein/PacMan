/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include <fstream>
#include "color.h"
#include "point.h"
#include "SDL_Plotter.h"

using namespace std;

struct Pixel {
    Color color;
    Point loc;
    Pixel() {
        loc = Point();
        color = white;
    }
    Pixel(Point p, Color c) {
        loc = p;
        color = c;
    }
};

class Image {
    private:
        Pixel* data = new Pixel[2073600];
        Point location;
        int numPixels;
    public:
        Image();
        Image(string fileName);
        Image(string fileName, Point);

        /*
         Description: Returns the location of the image
         Return: Point
         Precondition: None
         Postcondition: Image location is returned
         */
        Point getLocation() const;

        /*
         Description: Draws the image to the screen
         Return: Nothing
         Precondition: SDL_Plotter is passed by reference
         Postcondition: Image is drawn to the screen
         */
        void draw(SDL_Plotter&);
        /*
         Description: Sets the location of the image
         Return: Nothing
         Precondition: A Point class exists
         Postcondition: Location of image is set
         */
        void setLocation(Point);
        /*
         Description: Deletes the image
         Return: Nothing
         Precondition: None
         Postcondition: Image is deleted
         */
        void destroy();
        /*
         Description: Determines the size of the image
         Return: Nothing
         Precondition: A string exists
         Postcondition: Size image is determined
         */
        void load(string);
};

#endif // IMAGE_H_INCLUDED
