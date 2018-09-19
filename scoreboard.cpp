/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */
#include "scoreboard.h"

Score::Score() {
    name = "DONOTDISPLAYME";
    score = 0;
}
Score::Score(string s, int n) {
    name = s;
    score = n;
}

Scoreboard::Scoreboard() {

}
Scoreboard::Scoreboard(string fileName) {
    typing = false;
    ifstream input;
    string name;
    int score;
    count = 0;
    input.open(fileName.c_str());
    while((input >> name >> score) && count < 10) {
        players[count] = Score(name, score);
        count++;
    }
}
bool Scoreboard::getTyping() {
    return typing;
}
int Scoreboard::getHighScore() {
    sortScores();
    return players[0].score;
}
void Scoreboard::display(SDL_Plotter& g, const PacMan& pac, Color c) {
    stringstream out;
    if(!typing) {
        typing = true;
    }
    for(int i = 0; i < count; i++) {
        out.str(string());
        out << left << setw(NICK_MAX) << players[i].name
            << right << setw(SCORE_LENGTH_MAX) << players[i].score;
        printString(out.str(), Point(W_WIDTH / 2 - (NICK_MAX + SCORE_LENGTH_MAX * FONT_SIZE * 2) / 2, i * TILE_SIZE + SCORES_OFFSET), g, 1, c);
    }
    //Check for high score
    if(pac.getScore() >= getHighScore()) {
        printString(HIGH_SCORE, Point(W_WIDTH / 2 - HIGH_SCORE.size() * FONT_SIZE, 0), g, 2, c);
    } else {
        printString(YOUR_SCORE, Point(W_WIDTH / 2 - YOUR_SCORE.size() * FONT_SIZE, 0), g, 2, c);
    }
    //Score output
    printString(toStr(pac.getScore()), Point(W_WIDTH / 2 - toStr(pac.getScore()).size() * TILE_SIZE / 2, SCORE_OFFSET), g, 2, c);
    Rectangle(Point(W_WIDTH / 2 - UNDERLINE_WIDTH / 2, UNDERLINE_OFFSET), Point(W_WIDTH / 2 + UNDERLINE_WIDTH / 2, UNDERLINE_OFFSET + UNDERLINE_THICKNESS), c).draw(g);
    //Preview typed name
    printString(curName, Point(W_WIDTH / 2 - curName.size() * FONT_SIZE, ENTER_NAME_OFFSET), g, 2, c);

    if(g.kbhit()) {
        if(g.getKey() == LEFT_ARROW) {
            curName = curName.substr(0, curName.size() - 1);
        } else if(g.getKey() == SDL_SCANCODE_RETURN) { //Confirm name and save score
            save();
        } else if(curName.size() < NICK_MAX && g.getKey() != ' ') { //Only append if the length is less than NICK_MAX
            curName += g.getKey();
        }
    }
}
void Scoreboard::save() {
    ofstream out;
    out.open("scores.txt");
    players[count] = Score(curName, curScore);
    count++;
    sortScores();
    for(int i = 0; i < count; i++) {
        out << players[i].name << " " << players[i].score << endl;
    }
    out.close();
    typing = false;
}
void Scoreboard::setTyping(bool flag) {
    typing = flag;
}
void Scoreboard::sortScores() {
    bool stop = false;
    for(int pass = 0; pass < count - 1 && !stop; pass++) {
        for(int i = 0; i < count - 1; i++) {
            if(players[i].name < players[i + 1].name) {
                swap(players[i], players[i + 1]);
                stop = false;
            }
        }
    }
    stop = false;
    for(int pass = 0; pass < count - 1 && !stop; pass++) {
        for(int i = 0; i < count - 1; i++) {
            if(players[i].score < players[i + 1].score) {
                swap(players[i], players[i + 1]);
                stop = false;
            }
        }
    }
}
void Scoreboard::update(int s) {
    curScore = s;
}
