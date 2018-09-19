/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */
#include "image.h"

Image::Image() {

}
Image::Image(string fileName) {
    load(fileName);
}
Image::Image(string fileName, Point p) {
    load(fileName);
    location = p;
}

Point Image::getLocation() const {
    return location;
}

void Image::draw(SDL_Plotter& g) {
    for(int i = 0; i < numPixels; i++) {
        plot(g, Point(data[i].loc.x + location.x, data[i].loc.y + location.y), data[i].color);
    }
}
void Image::setLocation(Point p) {
    location = p;
}
void Image::destroy() {
    delete data;
}
void Image::load(string fileName) {
    ifstream input;
    int rowMax, colMax;
    int r, g, b;
    int count = 0;
    input.open(fileName.c_str());
    input >> rowMax >> colMax;
    //cout << "rows:" << rowMax << " cols:" << colMax << endl;
    for(int row = 0; row < rowMax; row++) {
        for(int col = 0; col < colMax; col++) {
            input >> r >> g >> b;
            data[count] = Pixel(Point(col, row), Color(r, g, b));
            count++;
        }
    }
    numPixels = count;
    //cout << "Num pixels " << numPixels << endl;
}
