/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */

#ifndef SCOREBOARD_H_INCLUDED
#define SCOREBOARD_H_INCLUDED

#include "constants.h"
#include "font.h"
#include "pacman.h"
#include "rectangle.h"
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Score {
    string name;
    int score;
    Score();
    Score(string, int);
};

class Scoreboard {
    private:
        Score players[MAX_PLAYER_SCORES];
        int count;
        bool typing;
        string curName;
        int curScore;
    public:
        Scoreboard();
        Scoreboard(string);

        /*
         Description: Displays the scoreboard to the screen
         Return: Nothing
         Precondition: SDL_Plotter is passed by reference, a Color Class exists,
         A PacMan class is a constant and passed by reference
         Postcondition: Scoreboard is displayed to the screen
         */
        void display(SDL_Plotter& g, const PacMan& pac, Color c);
        /*
         Description: Sorts the scores
         Return: Nothing
         Precondition: None
         Postcondition: Scores are sorted
         */
        void sortScores();
        /*
         Description: Sets whether or not user can still enter name
         Return: Nothing
         Precondition: Boolian value exists
         Postcondition: It is determined if user can still enter name
         */
        void setTyping(bool flag);
        /*
         Description: Transfers PacMan's score to the scoreboard
         Return: Nothing
         Precondition: Integer value exists
         Postcondition: PacMan's score is transferred
         */
        void update(int);
        /*
         Description: Save's score to the scoreboard
         Return: Nothing
         Precondition: None
         Postcondition: Score is saved to the scoreboard
         */
        void save();
        /*
         Description: Returns whether or not user can still type
         Return: Boolian
         Precondition: None
         Postcondition: User being able to type or not is returned
         */
        bool getTyping();
        /*
         Description: Returns the high score
         Return: Integer
         Precondition: None
         Postcondition: High score is returned
         */
        int getHighScore();
};

#endif // SCOREBOARD_H_INCLUDED
