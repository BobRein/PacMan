/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */
#include "map.h"
#include "SDL_Plotter.h"
#include "pacman.h"
#include <stdlib.h>

Map::Map() {

}

Map::Map(string str, Ghost g[], int& n) {
	loadMap(str, g, n);
	last = clock();
}

bool Map::collides(Circle c) {
	bool collision = false;
	//Check collision for all tiles
	for(int i = 0; i < MAP_HEIGHT * MAP_WIDTH && !collision; i++) {
		if(tiles[i].getType() == WALL) {
            collision = tiles[i].collides(c);
		}
	}
	return collision;
}

int Map::pickupCount() const {
	int count = 0;
	for(int i = 0; i < MAP_HEIGHT * MAP_WIDTH; i++) {
		if(pickups[i].getVisible()) {
			count++;
		}
	}
	return count;
}

void Map::draw(SDL_Plotter& g, bool party) {
    //Background
    //Rectangle(Point(), Point(MAP_WIDTH, MAP_HEIGHT), bkg, true).draw(g);

    //Map
    if(party) {
        printString("PARTY TIME", Point(rand()%W_WIDTH, rand()%(W_HEIGHT - FONT_SIZE * 3 + 1)), g, 3, Color(rand()%255, rand()%255, rand()%255));
    }
    if(clock() - last > 250) {
        for(int i = 0; i < MAP_HEIGHT * MAP_WIDTH; i++) {
            if(party && tiles[i].getType() == WALL) {
                tiles[i].setColor(Color(0, 32, rand()%128+128));
                last = clock();
            }
            tiles[i].draw(g);
            pickups[i].draw(g);
        }
    }

}

void Map::loadMap(string str, Ghost g[], int& n) {
	int i = 0, value;
	ifstream mapFile;
	mapFile.open(str.c_str());
	Tile t;
	int ghostCount = 0;

	srand(time(0));

	for(int row = 0; row < MAP_HEIGHT; row++) {
		for(int col = 0; col < MAP_WIDTH; col++) {

			mapFile >> value;
			t.setLocation(Point(col * TILE_SIZE, row * TILE_SIZE));
			if(value == 2) {
                g[ghostCount] = Ghost(Point((col+0.5) * TILE_SIZE, (row+0.5) * TILE_SIZE));
                ghostCount++;
                t.setType(AIR);
                pickups[i] = Circle(Point(col * TILE_SIZE + TILE_SIZE / 2, row * TILE_SIZE + TILE_SIZE / 2), PICKUP_RADIUS, white);
                if(rand()%PICKUP_SPAWN_RATE == 1) {
                    pickups[i].setRadius(PICKUP_RADIUS + 5);
                }
			} else {
                t.setType(static_cast<TileType>(value));
                if(t.getType() == AIR) {
                    pickups[i] = Circle(Point(col * TILE_SIZE + TILE_SIZE / 2, row * TILE_SIZE + TILE_SIZE / 2), PICKUP_RADIUS, white);
                    if(rand()%PICKUP_SPAWN_RATE == 1) {
                        pickups[i].setRadius(PICKUP_RADIUS + 5);
                    }
                }
			}
			tiles[i] = t;
			i++;
        }
	}
	n = ghostCount;

	/*for(int z = 0; z < i - 1; z++) {
		for(int b = 0; b < i - 1; b++) {
			if(tiles[b].getLocation().x == tiles[b + 1].getLocation().x) {
				if((tiles[b].getLocation().y - tiles[b + 1].getLocation().y) == 1) {
					tiles[b].setBottom(true);
					cerr << "Bottom neighbor" << endl;
				} else if((tiles[b].getLocation().y - tiles[b + 1].getLocation().y) == -1) {
					tiles[b].setTop(true);
					cerr << "Top neighbor" << endl;
				}
			}
			if(tiles[b].getLocation().y == tiles[b + 1].getLocation().y) {
				if((tiles[b].getLocation().x - tiles[b + 1].getLocation().x) == 1) {
					tiles[b].setRight(true);
					cerr << "Right neighbor" << endl;
				} else if((tiles[b].getLocation().x - tiles[b + 1].getLocation().x) == -1) {
					tiles[b].setLeft(true);
					cerr << "Left neighbor" << endl;
				}
			}
			cerr << "b:" << b << " z:" << z << endl;
		}
	}*/
}

void Map::setTileColor(Color c) {
    for(int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
        if(tiles[i].getType() == WALL) {
            tiles[i].setColor(c);
        }
    }
}

void Map::update(SDL_Plotter& g, PacMan& pac,double& time, bool mute) {
	for(int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
		if(pickups[i].getVisible()) {
			if(pickups[i].collides(pac.getCircle())) {
				pickups[i].setVisible(false);
				if(pickups[i].getRadius() == PICKUP_RADIUS) {
                    pac.setScore(pac.getScore() + 10);
				} else if(pickups[i].getRadius() == BIG_PICKUP_RADIUS) {
                    pac.setScore(pac.getScore() + 50);
                    time = clock();
				}
				playAudio(CHOMP, g, mute);
			}
		}
	}
	for(int x = 0; x < MAP_WIDTH; x++) {
		for(int y = 0; y < MAP_HEIGHT; y++) {
			//if(rect.collides(Rectangle(Point(tiles[x][y].getLocation().x, tiles[x][y].getLocation().y), TILE_SIZE, TILE_SIZE, blue)));
		}
	}
}
