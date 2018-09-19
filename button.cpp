/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */
#include "button.h"

Button::Button() {
    color = white;
    selected = false;
    rect.setFilled(false);
    rect.setColor(color);
    rect.setThickness(BUTTON_BORDER_THICKNESS);
}
Button::Button(Point ul, Point lr, Color c) {
    setUL(ul);
    setLR(lr);
    color = c;
    selected = false;
    rect.setFilled(false);
    rect.setColor(color);
    rect.setThickness(BUTTON_BORDER_THICKNESS);
}

bool Button::getSelected() const {
    return selected;
}
Color Button::getColor() const {
    return color;
}
Point Button::getUL() const {
    return rect.getUL();
}
Point Button::getLR() const {
    return rect.getLR();
}

void Button::setSelected(bool flag) {
    selected = flag;
}
void Button::setBorderColor(Color c) {
    rect.setColor(c);
}
void Button::setColor(Color c) {
    color = c;
    rect.setColor(color);
}
void Button::setForegroundColor(Color c) {
    color = c;
}
void Button::setUL(Point p) {
    rect.setUL(p);
}
void Button::setLR(Point p) {
    rect.setLR(p);
}
void Button::setText(string str) {
    text = str;
}
void Button::draw(SDL_Plotter& g) {
    printString(text, Point(W_WIDTH / 2 - text.size() * FONT_SIZE, rect.getUL().y + 8), g, 2, color);
    if(selected) {
        rect.draw(g);
    }
}
