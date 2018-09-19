/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include "color.h"
#include "sound.h"
#include <string>

using namespace std;

const int SLEEP = 5;

//Enumerated data
enum TileType {AIR, WALL};
enum Direction {STATIC, UP, DOWN, LEFT, RIGHT};

const int FONT_SIZE = 16;

//Colors
const Color red(255, 0, 0);
const Color orange(210, 100, 0);
const Color yellow(255, 238, 0);
const Color green(0, 255, 0);
const Color blue(0, 0, 200);
const Color black(0, 0, 0);
const Color white(240, 240, 240);
const Color indigo(75,0,130);
const Color violet(238,130,238);

const Color ghostColor(red);

const Color bkg = black;

//UI and score stuff
const int SCORE_OFFSET = 64;
const int ENTER_NAME_OFFSET = SCORE_OFFSET + 64;
const int UNDERLINE_OFFSET = ENTER_NAME_OFFSET + 36;
const int UNDERLINE_THICKNESS = 3;
const int UNDERLINE_WIDTH = 300;
const int SCORES_OFFSET = UNDERLINE_OFFSET + UNDERLINE_THICKNESS + 2;
const int SCORE_LENGTH_MAX = 8;
const int TITLE_BUTTON_OFFSET = 10;
const int TITLE_BORDER_THICKNESS = 2;
const int BUTTON_WIDTH = 350;
const int BUTTON_HEIGHT = 48;
const int BUTTON_ONE_OFFSET = TITLE_BUTTON_OFFSET + BUTTON_HEIGHT + 16;
const int BUTTON_BORDER_THICKNESS = 2;
const int NUM_MAIN_MENU_BUTTONS = 3;
const int BUTTON_TWO_OFFSET = BUTTON_ONE_OFFSET + BUTTON_HEIGHT + 16;
const int BUTTON_THREE_OFFSET = BUTTON_TWO_OFFSET + BUTTON_HEIGHT + 16;
const int MAP_PRE_HEIGHT = 174;
const int MAP_PRE_WIDTH = 150;
const int MAP_PRE_ONE_OFFSET = TITLE_BUTTON_OFFSET + BUTTON_HEIGHT + 16;
const int MAP_PRE_TWO_OFFSET = MAP_PRE_ONE_OFFSET + MAP_PRE_HEIGHT + BUTTON_HEIGHT + 16;
const int MAP_PRE_THREE_OFFSET = MAP_PRE_TWO_OFFSET + MAP_PRE_HEIGHT + 16;
const int NUM_MAIN_BUTTONS = 3;
const int MAP_PADDING = 20;
const int BUTTON_PADDING = 32;
const int MAP_BUTTON_HEIGHT = MAP_PRE_HEIGHT + 10;
const int MAP_BUTTON_WIDTH = MAP_PRE_WIDTH + 10;
const int MAP_BUTTON_OFFSET = TITLE_BUTTON_OFFSET + 86;
const int MAIN_MENU_OFFSET = TITLE_BUTTON_OFFSET + BUTTON_HEIGHT + 16;

const Color FONT_COLOR = red;

const string TITLE = "PAC MAN";
const int NUM_CREATORS = 5;
const string CREATORS[NUM_CREATORS] = {
            "HUNTER       LEAD PROGRAMMER",
            "BOB          MATHZ AND STUFF",
            "DANIEL  PROMOTIONAL MATERIAL",
            "NOAH            CARTOGRAPHER",
            "GRIFFIN          LEAD HACKER"};
enum ButtonTask {PLAY, SETTINGS, CREDITS};

//Dimensions
const int MAP_WIDTH = 19;
const int MAP_HEIGHT = 22;

const int TILE_SIZE = 32;

const int W_WIDTH  = MAP_WIDTH * TILE_SIZE;
const int W_HEIGHT = MAP_HEIGHT * TILE_SIZE;


const double PRECISION = 0.0000001;

const int PLAYER_RADIUS = 14;

const int PICKUP_RADIUS = 3;

const int TRIANGLE_HEIGHT_GHOST =5;

const int BIG_PICKUP_RADIUS = 8;

const int NUM_CHARS = 500;

const int NICK_MAX = 10;

//Movement speeds
const int PLAYER_SPEED = 2;
const int PARTY_SPEED = 3;
const int ENEMY_SPEED = 2;//for some reason it only works at 1 and 2

//Game states
enum GameState {READY, MAIN_MENU, PLAYING, CONFIG, WIN, LOSE, SCORE, CREDIT, MAP_SELECT};

const string SOUND_FOLDER = "res/sound/";
const string FONT_FOLDER = "res/char/";
const string IMG_FOLDER = "res/img/";
const string MAP_FOLDER = "res/map/";

//Map files
const int NUM_MAPS = 3;
const string MAP_1 = MAP_FOLDER + "map1.dat";
const string MAP_2 = MAP_FOLDER + "map2.dat";
const string MAP_3 = MAP_FOLDER + "map3.dat";
const string MAP_ROTATION[NUM_MAPS] = {
            MAP_1,
            MAP_2,
            MAP_3};
const int MAP_PREVIEW_HEIGHT = 174;
const string PREVIEW_ROTATION[NUM_MAPS] = {
            IMG_FOLDER + "map1.txt",
            IMG_FOLDER + "map2.txt",
            IMG_FOLDER + "map3.txt"};

//Music files
const string PAC = SOUND_FOLDER + "pac.wav";
const string PRAYER = SOUND_FOLDER + "prayer.wav";
const string BLITZ = SOUND_FOLDER + "ballroomblitz.wav";
const string BEGIN = SOUND_FOLDER + "pacman_beginning.wav";
const string CHOMP = SOUND_FOLDER + "pacman_chomp.wav";
const string SAFETY = SOUND_FOLDER + "safetydance.wav";
const string CENTURIES = SOUND_FOLDER + "centuries.wav";
const string PARTY = SOUND_FOLDER + "party.wav";
const string DEATH = SOUND_FOLDER + "pacman_death.wav";
const string TOGETHER = SOUND_FOLDER + "cometogether.wav";
const string EATGHOST = SOUND_FOLDER + "pacman_eatghost.wav";
const string playlist[] = {PAC, PRAYER, BLITZ, SAFETY, CENTURIES, TOGETHER};
const int NUM_SONGS = 6;

//Images
const string COVER = IMG_FOLDER + "cover.txt";

//UI Strings
const string YOU_WIN = "YOU WIN";
const string YOU_LOSE = "GAME OVER";
const string YOUR_SCORE = "SCORE";
const string ENTER_NAME = "ENTER YOUR NAME";
const string HIGH_SCORE = "HIGH SCORE";

const int MAX_PLAYER_SCORES = 100;

const int MAX_GHOSTS = 50;

const int AFRAID_DURATION = 10000;

const int PICKUP_SPAWN_RATE = 30;//one of every n dots is big

const int NICK_LENGTH = 7;

//Font stuff
const int LETTER_WIDTH = 32;
const int LETTER_HEIGHT = 32;



#endif /* CONSTANTS_H_ */
