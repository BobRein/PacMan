/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef GAME_H_
#define GAME_H_

#include "constants.h"
#include "button.h"
#include "point.h"
#include <time.h>
#include <string>
#include <sstream>
#include "ghost.h"
#include "image.h"
#include "map.h"
#include "scoreboard.h"
#include "sound.h"


class PacMan;
class SDL_Plotter;

using namespace std;

class Game {
	private:
		bool audioPlaying;
		bool mute;
		bool firstMapDraw;
		SDL_Event e;
		int gameState;
		int numOfGhosts;
		Ghost ghost [MAX_GHOSTS];
		Map map;
		PacMan pac;
		Point mouseLoc;
		Ghost ghost1;
		Ghost ghost2;
		Ghost ghost3;
		Ghost ghost4;
		int score;
		int selection;
		bool showFPS;
		bool party, partyPlaying;
		double delta;
		double start;
        bool musicPlaying = false;
        bool beginning = false;
        bool gameOver = false;
		int frames, fps;
		ostringstream tostr;
		Scoreboard scoreboard;
		int numGhosts;
		string curSong;
		Image cover;
		Rectangle backdrop;
		Button titleButton;
		Button playButton;
		Button settingsButton;
		Button creditsButton;
		Button mainMenu[NUM_MAIN_MENU_BUTTONS];
		Image preview[NUM_MAPS];
		Map rotation[NUM_MAPS];
		Color themeColor;
		Button maps[NUM_MAPS];
	public:
		Game(SDL_Plotter&);

        /*
         Description: Initializes the user interface and audio of the game
         Return: Nothing
         Precondition: SDL_Plotter is passed by reference
         Postcondition: User interface and audio is initialized
         */
		void init(SDL_Plotter&);
        /*
         Description: Used for navigating the menu, and playing the game. Draws, moves, and keeps
         count of score.
         Return: Nothing
         Precondition: SDL_Plotter is passed by reference
         Postcondition: Game is played
         */
		void play(SDL_Plotter&);
};

#endif /* GAME_H_ */
