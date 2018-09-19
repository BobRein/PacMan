/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */
#include "font.h"

Letter FONT[NUM_CHARS];

Letter::Letter() {
    location = Point();
}
Letter::Letter(char c) {
    setChar(c);
}

char Letter::getChar() const {
    return character;
}
Color Letter::getColor() const {
    return color;
}
int Letter::getScale() const {
    return scale;
}
Point Letter::getLocation() const {
    return location;
}

void Letter::setChar(char c) {
    character = c;
    string fileName = string(1, c) + ".txt";
    loadFont(fileName, data);
}
void Letter::setColor(Color c) {
    color = c;
}
void Letter::setLocation(Point p) {
    location = p;
}
void Letter::setScale(int s) {
    scale = s;
}
void Letter::print(SDL_Plotter& g) {
    for(int x = 0; x < FONT_SIZE; x++) {
        for(int y = 0; y < FONT_SIZE; y++) {
            if(data[y][x] == '1') {
                for(int _x = 0; _x < scale; _x++) {
                    for(int _y = 0; _y < scale; _y++) {
                        plot(g, Point(location.x + _x + x * scale, location.y + _y + y * scale), color);
                    }
                }
            }
        }
    }
}

void loadFont(string fileName, char arr[FONT_SIZE][FONT_SIZE]) {
	ifstream input;
	input.clear();
	string newFile = FONT_FOLDER + fileName;
	input.open(newFile.c_str());
	if(!input.is_open()) {
		//cerr << newFile << " was not opened!" << endl;
	} else {
		for(int r = 0; r < FONT_SIZE; r++) {
			for(int c = 0; c < FONT_SIZE; c++) {
				input >> arr[r][c];
				//cout << arr[r][c];
			}
			//cout << endl;
		}
	}
	input.close();
}

void printString (string s, Point p, SDL_Plotter& g, int scale, Color c) {
	Letter curLetter;
	for(unsigned i = 0; i < s.size(); i++) {
        curLetter = FONT[static_cast<int>(s.at(i))];
        curLetter.setLocation(Point(p.x + i * FONT_SIZE * scale, p.y));
        curLetter.setColor(c);
        curLetter.setScale(scale);
        curLetter.print(g);
	}
}

void initFont() {
    //48-57 numbers
    //65-90 capital letters
    //97-122 lowercase letters
    int z = 48;

    //numbers
    for(int i = 0; i < 10; i++) {
        FONT[z] = Letter(i + 48);
        //cout << "Z:" << z << endl;
        //cout << static_cast<char>(i + 48) << endl;
        z++;
    }

    z = 65;

    //capital letters
    for(int i = 0; i < 26; i++) {
        FONT[z] = Letter(i + 65);
        //cout << "Z:" << z << endl;
        //cout << static_cast<char>(i + 65) << endl;
        z++;
    }

    z = 97;

    //lowercase letters
    for(int i = 0; i < 26; i++) {
        FONT[z] = Letter(i + 97);
        //cout << "Z:" << z << endl;
        //cout << static_cast<char>(i + 97) << endl;
        z++;
    }
}

string toStr(int n) {
    ostringstream s;
    s << n;
    return s.str();
}
