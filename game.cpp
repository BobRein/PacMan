/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */
#include "game.h"
#include "map.h"
#include "pacman.h"
#include "SDL_Plotter.h"
#include "triangle.h"
#include "font.h"
#include <fstream>
#include <stdlib.h>
//#include "Characters.h"
Game::Game(SDL_Plotter& g) {
    backdrop = Rectangle(Point(), Point(W_WIDTH, W_HEIGHT), black);
    cover = Image(COVER);
    initFont();
    themeColor = red;
    titleButton = Button(Point(W_WIDTH / 2 - BUTTON_WIDTH / 2, TITLE_BUTTON_OFFSET),
                         Point(W_WIDTH / 2 + BUTTON_WIDTH / 2, TITLE_BUTTON_OFFSET + BUTTON_HEIGHT), white);


    //Wait for sounds to load
	backdrop.draw(g);
	cover.draw(g);
	g.update();
	g.Sleep(4000);
	mute = false;
	party = true;
    init(g);
}

void Game::play(SDL_Plotter& g) {
    int lastScore = 0;
    double lastGhost = clock();
    double powerUPInitTime= -1*AFRAID_DURATION;
	while(!g.getQuit()&&!gameOver) {
		switch(gameState) {
		    case MAIN_MENU: {
		        backdrop.draw(g);
                mainMenu[0].setText("PLAY");
                mainMenu[1].setText("SETTINGS");
                mainMenu[2].setText("CREDITS");
		        titleButton.setText("PAC MAN");
		        titleButton.draw(g);
                for(int i = 0; i < NUM_MAIN_MENU_BUTTONS; i++) {
                    mainMenu[i].draw(g);
                    if(i == selection) {
                        mainMenu[i].setSelected(true);
                    } else {
                        mainMenu[i].setSelected(false);
                    }
                }
                if(g.kbhit()) {
                    if(g.getKey() == UP_ARROW) {
                        if(selection == 0) {
                            selection = NUM_MAIN_MENU_BUTTONS - 1;
                        } else {
                            selection -= 1;
                        }
                    } else if(g.getKey() == DOWN_ARROW) {
                        if(selection == NUM_MAIN_MENU_BUTTONS - 1) {
                            selection = 0;
                        } else {
                            selection += 1;
                        }
                    } else if(g.getKey() == SDL_SCANCODE_RETURN) {
                        if(selection == PLAY) {
                            gameState = MAP_SELECT;
                            mainMenu[0].setText("ORIGINAL");
                            mainMenu[1].setText("CORNERS");
                            mainMenu[2].setText("REPLACE");
                            titleButton.setText("MAP SELECT");
                        } else if(selection == SETTINGS) {
                            gameState = CONFIG;
                            titleButton.setText("SETTINGS");
                            if(mute) {
                                mainMenu[0].setText("UNMUTE");
                            } else {
                                mainMenu[0].setText("MUTE");
                            }
                            mainMenu[1].setText("THEME COLOR");
                        } else if(selection == CREDITS) {
                            gameState = CREDIT;
                        }
                    }
                }

                break;
		    }
			case READY: {
                map.draw(g, party);
			    pac.draw(g);
                for(int i =0; i< numOfGhosts; i++)
                    {
                        ghost[i].draw(g);
                    }
			    /*
			    ghost1.draw(g);
			    ghost2.draw(g);
			    ghost3.draw(g);
			    ghost4.draw(g);
			    */
			    printString("READY", Point(W_WIDTH / 2 - 3 * 16 * 5 / 2, W_HEIGHT / 2 - 3 * 16), g, 3, themeColor);
                if(clock() - start > 4000) {
                    gameState = PLAYING;
                }
                if(!beginning) {
                    playAudio(BEGIN, g, mute);
                    beginning = true;
                }
				break;
			}
			case PLAYING: {
                if(clock() - delta > 1000) {
                    fps = frames;
                    frames = 0;
                    delta = clock();
                }
                for(int i =0; i< numOfGhosts; i++)
                    {
                         if(pac.getCircle().collides(ghost[i].getCircle()))
                         {
                             if ((clock()-powerUPInitTime<AFRAID_DURATION))//is afraid
                             {
                                 pac.setScore(pac.getScore()+100);
                                 playAudio(EATGHOST, g, mute);
                                 ghost[i].setLocation(Point(TILE_SIZE * 1.5, TILE_SIZE * 1.5));
                             }
                             else
                             {
                                    playAudio(DEATH, g, mute);
                                    gameState = LOSE;
                             }
                         }
                        if((clock()-powerUPInitTime<AFRAID_DURATION))
                        {
                            ghost[i].setColor(white);
                        }
                        else
                        {
                            ghost[i].setColor(themeColor);
                        }
                    }
                map.update(g, pac, powerUPInitTime, mute);
                map.draw(g, party);
                pac.move(g, map);
                pac.draw(g);
                if(clock() - lastGhost > 16) {
                    for(int i =0; i< numOfGhosts; i++)
                        {
                            ghost[i].move(g, map, pac,(clock()-powerUPInitTime<AFRAID_DURATION),ghost);//also pass afraid as a parameter.
                        }
                    lastGhost = clock();
                }
                for(int i = 0; i < numOfGhosts; i++) {
                    ghost[i].draw(g);
                }
                if(showFPS) {
                    printString(toStr(fps) + "FPS", Point(), g, 1, themeColor);
                }
                printString("SCORE " + toStr(pac.getScore()), Point(W_WIDTH - 200, 0), g, 1, themeColor);
                if(map.pickupCount() == 0) {
                    gameState = WIN;
                }
                if(pac.getScore() != lastScore) {
                    lastScore = pac.getScore();
                }
                if(!musicPlaying && (clock() - start > 1000)) {
                    musicPlaying = true;
                    curSong = playlist[rand()%NUM_SONGS];
                    //cout << "Current song from playlist: " << curSong << endl;
                    playAudio(curSong, g, mute);
                }
                break;
			}
			case CONFIG: {
			    backdrop.draw(g);
			    titleButton.draw(g);
                for(int i = 0; i < 2; i++) {
                    mainMenu[i].draw(g);
                    if(i == selection) {
                        mainMenu[i].setSelected(true);
                    } else {
                        mainMenu[i].setSelected(false);
                    }
                }
                if(g.kbhit()) {
                    if(g.getKey() == LEFT_ARROW) {
                        gameState = MAIN_MENU;
                    } else if(g.getKey() == UP_ARROW) {
                        if(selection == 0) {
                            selection = 1;
                        } else {
                            selection -= 1;
                        }
                    } else if(g.getKey() == DOWN_ARROW) {
                        if(selection == 1) {
                            selection = 0;
                        } else {
                            selection += 1;
                        }
                    } else if(g.getKey() == SDL_SCANCODE_RETURN) {
                        if(selection == 0) {
                            mute = !mute;
                            if(mute) {
                                mainMenu[0].setText("UNMUTE");
                            } else {
                                mainMenu[0].setText("MUTE");
                            }
                        } else if(selection == 1) {
                            if(themeColor.match(red)) {
                                themeColor = orange;
                            } else if(themeColor.match(orange)) {
                                themeColor = green;
                            } else if(themeColor.match(green)) {
                                themeColor = indigo;
                            } else if(themeColor.match(indigo)) {
                                themeColor = violet;
                            } else if(themeColor.match(violet)) {
                                themeColor = red;
                            }
                        }
                        for(int i = 0; i < NUM_MAIN_MENU_BUTTONS; i++) {
                            mainMenu[i].setForegroundColor(themeColor);
                            titleButton.setBorderColor(themeColor);
                        }
                        for(int i = 0; i < numOfGhosts; i++) {
                            ghost[i].setColor(themeColor);
                        }
                    }
                }
                break;
			}
			case WIN: {
			    g.quitSound(curSong);
			    backdrop.draw(g);
                printString("YOU WIN", Point(W_WIDTH / 2 - 3 * 16 * 7 / 2, W_HEIGHT / 2 - 3 * 16), g, 3, themeColor);
                g.update();
                g.Sleep(4000);
                gameState = SCORE;
                break;
			}
            case LOSE: {
                g.quitSound(curSong);
                backdrop.draw(g);
                printString("GAME OVER", Point(W_WIDTH / 2 -(4*16*2+16*2/2) , W_HEIGHT / 2 - 16*2), g, 2, themeColor);
                g.update();
                g.Sleep(4000);
                gameState = SCORE;
				break;
            }
            case SCORE: {
                backdrop.draw(g);
                scoreboard.update(pac.getScore());
                //Draw scoreboard to screen
                scoreboard.display(g, pac, themeColor);
                if(g.getKey() == SDL_SCANCODE_RETURN && !scoreboard.getTyping()) {
                    gameState = MAIN_MENU;
                    cover.destroy();
                    init(g);
                }
                break;
            }
            case CREDIT: {
                backdrop.draw(g);
                for(int i = 0; i < NUM_CREATORS; i++) {
                    printString(CREATORS[i], Point(W_WIDTH / 2 - CREATORS[i].size() * FONT_SIZE / 2, i * FONT_SIZE * 2 + 256), g, 1, white);
                }
                if(g.kbhit()) {
                    if(g.getKey() == LEFT_ARROW) {
                        gameState = MAIN_MENU;
                    }
                }
                break;
            }
            case MAP_SELECT: {
                backdrop.draw(g);
                titleButton.draw(g);
                for(int i = 0; i < NUM_MAPS; i++) {
                    preview[i].draw(g);
                }
                for(int i = 0; i < NUM_MAPS; i++) {
                    maps[i].draw(g);
                    if(i == selection) {
                        maps[i].setSelected(true);
                    } else {
                        maps[i].setSelected(false);
                    }
                }
                if(g.kbhit()) {
                    if(g.getKey() == LEFT_ARROW) {
                        gameState = MAIN_MENU;
                    } else if(g.getKey() == UP_ARROW) {
                        if(selection == 0) {
                            selection = NUM_MAIN_MENU_BUTTONS - 1;
                        } else {
                            selection -= 1;
                        }
                    } else if(g.getKey() == DOWN_ARROW) {
                        if(selection == NUM_MAIN_MENU_BUTTONS - 1) {
                            selection = 0;
                        } else {
                            selection += 1;
                        }
                    } else if(g.getKey() == SDL_SCANCODE_RETURN) {
                        map = Map(MAP_ROTATION[selection], ghost, numOfGhosts);
                        for(int i = 0; i < numOfGhosts; i++) {
                            ghost[i].setColor(themeColor);
                        }
                        //map.setTileColor(themeColor);
                        gameState = READY;
                        start = clock();
                    }
                    //cout << selection << endl;
                }
                break;
            }

        }
        if(g.kbhit()) {
            pac.update(g);
            switch(g.getKey()) {
                case 'F':
                    showFPS = !showFPS;
                    break;
                case 'Q':
                    party = !party;
                    if(party) {
                        g.quitSound(curSong);
                        g.initSound(PARTY);
                        g.Sleep(500);
                        playAudio(PARTY, g, mute);
                    } else {
                        g.quitSound(PARTY);
                        g.initSound(curSong);
                        g.Sleep(500);
                        playAudio(curSong, g, mute);
                    }
                    break;
            }
        }
		frames++;
		g.update();
	}
	//Main game loop

}

void Game::init(SDL_Plotter& g) {

	audioPlaying = false;
	gameState = MAIN_MENU;
	for(int i = 0; i < NUM_MAPS; i++) {
        preview[i] = Image(PREVIEW_ROTATION[i], Point(W_WIDTH / 2 - 75, i * MAP_PREVIEW_HEIGHT + i * 32 + 100));
	}

	pac = PacMan();
	selection = 0;
	titleButton.setBorderColor(themeColor);
	titleButton.setSelected(true);
	for(int i = 0; i < NUM_MAIN_BUTTONS; i++) {
        mainMenu[i] = Button(Point(W_WIDTH / 2 - BUTTON_WIDTH / 2, i * BUTTON_HEIGHT + i * BUTTON_PADDING + MAIN_MENU_OFFSET),
                             Point(W_WIDTH / 2 + BUTTON_WIDTH / 2, i * BUTTON_HEIGHT + i * BUTTON_PADDING + MAIN_MENU_OFFSET + BUTTON_HEIGHT), white);
        mainMenu[i].setForegroundColor(themeColor);
	}
    for(int i = 0; i < NUM_MAPS; i++) {
        maps[i] = Button(Point(W_WIDTH / 2 - MAP_BUTTON_WIDTH / 2, i * MAP_BUTTON_HEIGHT + i * MAP_PADDING + MAP_BUTTON_OFFSET),
                         Point(W_WIDTH / 2 + MAP_BUTTON_WIDTH / 2, i * MAP_BUTTON_HEIGHT + i * MAP_PADDING + MAP_BUTTON_OFFSET + MAP_BUTTON_HEIGHT), white);
        maps[i].setForegroundColor(themeColor);
	}
	mainMenu[0].setText("PLAY");
	mainMenu[1].setText("SETTINGS");
	mainMenu[2].setText("CREDITS");
	mainMenu[0].setSelected(true);
	/*
	ghost1= Ghost();
	ghost2= Ghost(Point(1.5 * TILE_SIZE, TILE_SIZE * 20.5));
	ghost3= Ghost(Point(17.5 * TILE_SIZE, TILE_SIZE * 20.5));
	ghost4= Ghost();
	*/
	showFPS = false;
	party = partyPlaying = false;
	musicPlaying = false;
	beginning = false;
	gameOver = false;

	//Background music init
	for(int i = 0; i < NUM_SONGS; i++) {
        g.initSound(playlist[i]);
	}

	//Misc sounds init
	g.initSound(CHOMP);
	g.initSound(BEGIN);
	g.initSound(PARTY);
	g.initSound(DEATH);
	g.initSound(EATGHOST);



	delta = clock();

	//Number of frames since last check
	frames = 0;

	//High scores
	scoreboard = Scoreboard("scores.txt");

	//For the initial ready wait
	start = clock();
	srand(start);
}
