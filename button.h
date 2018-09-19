/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "color.h"
#include "font.h"
#include "point.h"
#include "rectangle.h"

class Button {
    private:
        Color color;
        bool selected;
        Rectangle rect;
        string text;
    public:
        Button();
        Button(Point, Point, Color);

        /*
         Description: Determines if the box should be selected on the menu
         Return: Boolian
         Precondition: None
         Postcondition: Selection is determined
         */
        bool getSelected() const;
        /*
         Description: Returns the color of the box
         Return: Color
         Precondition: None
         Postcondition: Color is returned
         */
        Color getColor() const;
        /*
         Description: Returns the upper left point of the box
         Return: Point
         Precondition: None
         Postcondition: Upper left point is returned
         */
        Point getUL() const;
        /*
         Description: Returns the lower right point of the box
         Return: Point
         Precondition: None
         Postcondition: Lower right point is returned
         */
        Point getLR() const;
        /*
         Description: Returns the text of the box
         Return: String
         Precondition: None
         Postcondition: Text is returned
         */
        string getText() const;
        /*
         Description: Sets the selected box on the menu
         Return: None
         Precondition: Boolian value exists
         Postcondition: Selected box is set
         */
        void setSelected(bool);
        /*
         Description: Sets the border color of the box
         Return: Nothing
         Precondition: A Color class exists
         Postcondition: Border color is set
         */
        void setBorderColor(Color);
        /*
         Description: Sets the color of the box and font
         Return: Nothing
         Precondition: A Color class exists
         Postcondition: Box and font color is set
         */
        void setColor(Color);
        /*
         Description: Sets the color of the text
         Return: Nothing
         Precondition: A Color class exists
         Postcondition: Font color is set
         */
        void setForegroundColor(Color);
        /*
         Description: Sets the upper left point of the box
         Return: Nothing
         Precondition: A Point class exists
         Postcondition: Upper left point is set
         */
        void setUL(Point);
        /*
         Description: Sets the lower right point of the box
         Return: Nothing
         Precondition: A Point class exists
         Postcondition: Lower right point is set
         */
        void setLR(Point);
        /*
         Description: Sets the text inside the box
         Return: Nothing
         Precondition: A string exists
         Postcondition: The text is set
         */
        void setText(string);
        /*
         Description: Draws the box and font to the screen
         Return: Nothing
         Precondition: SDL_Plotter is passed by reference
         Postcondition: Box and font is drawn to the screen
         */
        void draw(SDL_Plotter&);
};

#endif // BUTTON_H_INCLUDED
