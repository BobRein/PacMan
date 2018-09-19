/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */
#include <iostream>

#include "game.h"

using namespace std;

int main(int argc, char ** argv) {
    SDL_Plotter g(W_HEIGHT, W_WIDTH);
    Game pacman(g);
    pacman.play(g);
	return 0;
}
