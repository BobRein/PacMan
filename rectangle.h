/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "constants.h"
#include "color.h"
#include "point.h"

//Forward declarations
class Circle;
class Line;
class PacMan;
class SDL_Plotter;

class Rectangle {
private:
    bool isFilled, isVisible;
    Color color;
    Direction direction;
    Point ul, lr;
    int thickness;
public:
    Rectangle();

    Rectangle(const Point& p, const Point&, const Color& c);

    Rectangle(const Point& p, const Point&, const Color& c, bool filled);

    /*
     Description: Determines if the rectangle is colliding with a circle
     Return: Boolian
     Precondition: A Circle class exists
     Postcondition: It is determined if there is a collision
     */
    bool collides(Circle);

    /*
     Description: Determine if the rectangle has been filled with color
     Return: Boolian
     Precondition: None
     Postcondition: It is determined if the rectangle is filled with color
     */
    bool getFilled() const;

    /*
     Description:
     Return:
     Precondition:
     Postcondition:
     */
    //bool getVisible() const;

    /*
     Description: Returns the color of the rectangle
     Return: Color
     Precondition: None
     Postcondition: Rectangle color is returned
     */
    Color getColor() const;

    /*
     Description: Returns the direction of the rectangle
     Return: Direction
     Precondition: None
     Postcondition: Rectangle direction is returned
     */
    Direction getDirection() const;

    /*
     Description: Returns thickness of rectangle
     Return: Integer
     Precondition: None
     Postcondition: Rectangle thickness is returned
     */

    int getThickness() const;

    /*
     Description: Returns the upper left point of the rectangle
     Return: Point
     Precondition: None
     Postcondition: Rectangles upper left point is returned
     */
    Point getUL() const;

    /*
     Description: Returns the lower right point of the rectangle
     Return: Point
     Precondition: None
     Postcondition: Rectangles lower right point is returned
     */
    Point getLR() const;

    /*
     Description: Draws the rectangle to the screen
     Return: Nothing
     Precondition: SDL_Plotter is passed by reference
     Postcondition: Rectangle is drawn to the screen
     */
    void draw(SDL_Plotter& g);

    /*
     Description: Sets the color of the rectangle
     Return: Nothing
     Precondition: A Color class is a constant and passed by reference
     Postcondition: The rectangles color is set
     */
    void setColor(const Color& c);

    /*
     Description: Sets the direction of the rectangle
     Return: Nothing
     Precondition: Direction exists
     Postcondition: The rectangle direction is set
     */
    void setDirection(Direction);

    /*
     Description: Sets the filled boolian function
     Return: Nothing
     Precondition: A boolian value exists
     Postcondition: It is set whether or not the rectangle is filled
     */
    void setFilled(bool);

    /*
     Description: Sets the location of the rectangle
     Return: Nothing
     Precondition: A Point class is a constant and passed by reference
     Postcondition: The rectangle location is set
     */
    void setLocation(const Point& p);

    /*
     Description: Sets the lower right point of the rectangle
     Return: Nothing
     Precondition: A Point class exists
     Postcondition: The rectangles lower right point is set
     */
    void setLR(Point);

    /*
     Description: Sets the thickness of each rectangle
     Return: Nothing
     Precondition: Integer value exists
     Postcondition: Rectangle thickness is set
     */
    void setThickness(int);

    /*
     Description: Sets the upper left point of the rectangle
     Return: Nothing
     Precondition: A Point class exists
     Postcondition: The rectangles upper left point is set
     */
    void setUL(Point);
};

void drawRectangle(SDL_Plotter& g, const Rectangle&);

#endif /* RECTANGLE_H_ */

