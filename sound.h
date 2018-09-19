/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef SOUND_H_
#define SOUND_H_

#include "SDL_Plotter.h"
#include <string>

using namespace std;

struct Sound {
	bool playing;
	int length;
	string name;
	Sound() {
		playing = false;
		length = 0;
		name = "";
	}
	Sound(string str, int len, bool play) {
		name = str;
		length = len;
		playing = play;
	}
	/*
         Description: Plays the sound
         Return: Nothing
         Precondition: SDL_Plotter is passed by reference
         Postcondition: Sound is played
         */
	void play(SDL_Plotter&);
};
/*
         Description: Plays an audio file
         Return: Nothing
         Precondition: A string exists, a Boolian value exists,
         SDL_Plotter is passed by reference
         Postcondition: Audio file is played
         */
void playAudio(string name, SDL_Plotter& g, bool mute);

#endif /* SOUND_H_ */
