/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef LINE_H_
#define LINE_H_

#include "color.h"
#include "point.h"

class SDL_Plotter;

class Line {
private:
    Color color;
    Point p1, p2;
public:
    Line(const Point& a, const Point& b, const Color& c);
    
    Color getColor() const;
    
    /*
     Description: Returns the first point of the line
     Return: Point
     Precondition: None
     Postcondition: Lines first point is returned
     */
    Point getP1() const;
    
    /*
     Description: Returns the second point of the line
     Return: Point
     Precondition: None
     Postcondition: Lines second point is returned
     */
    Point getP2() const;
    
    /*
     Description: Draws the line to the screen
     Return: Nothing
     Precondition: SDL_Plotter is passed by reference
     Postcondition: Line is drawn to the screen
     */
    void draw(SDL_Plotter& g);
    
    /*
     Description: Sets the color of the line
     Return: Nothing
     Precondition: A Color class is a constant and passed by reference
     Postcondition: Line color is set
     */
    void setColor(const Color& c);
    
    /*
     Description: Sets the first point of the line
     Return: Nothing
     Precondition: A Point class is a constant and passed by reference
     Postcondition: Lines first point is set
     */
    void setP1(const Point& p);
    
    /*
     Description: Sets the second point of the line
     Return: Nothing
     Precondition: A Point class is a constant and passed by reference
     Postcondition: Lines second point is set
     */
    void setP2(const Point& p);
    
    /*
     Description: Determines if the line has a slope
     Return: Boolian
     Precondition: A double value is passed by reference, two Point classes exists,
     are constants, and passed by reference
     Postcondition: Boolian returns as true or false
     */
    bool slope(double& m, const Point& p1, const Point& p2);
    
    /*
     Description: Determines the y-intercept of the line
     Return: Double
     Precondition: A Point class is a constant and passed by reference, a double value exists
     Postcondition: Lines y-intercept is determined
     */
    double yInt(const Point& p, double m);
};

bool slope(double& m, const Point& p1, const Point& p2);

double yInt(const Point& p, double m);

//Uses Bresenham's line drawing algorithm
void drawLine(SDL_Plotter& g, const Point& p1, const Point& p2, const Color& c);

#endif /* LINE_H_ */


