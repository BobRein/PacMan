/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */
#include "pacman.h"
#include "map.h"
#include "rectangle.h"

PacMan::PacMan() {
	circle = Circle(Point(TILE_SIZE * 1.5, TILE_SIZE * 1.5), PLAYER_RADIUS, yellow, STATIC);
	lastSound = SDL_GetTicks();
	nextDir = STATIC;
	mouthOpen = true;
	score = 0;
	speed = PLAYER_SPEED;
	last = lastMove = clock();
}

Circle PacMan::getCircle() const {
	return circle;
}

Direction PacMan::getDirection() const {
	return circle.getDirection();
}

double PacMan::getRadius() const {
	return circle.getRadius();
}

Point PacMan::getLocation() const {
	return circle.getLocation();
}

Triangle PacMan::getMouth() const {
	return mouth;
}

int PacMan::getScore() const {
    return score;
}

int PacMan::getSpeed() const {
    return speed;
}


void PacMan::draw(SDL_Plotter& g) {
    circle.draw(g);
    double now = clock();
    if(now - last > 100) {
        mouthOpen = !mouthOpen;
        last = now;
    }
    if(mouthOpen && (circle.getDirection() != STATIC)) {
        mouth.draw(g,true);
    }
}

void PacMan::move(SDL_Plotter& g, Map& m) {
    //Check if in center of a rectangle
    if((abs(circle.getLocation().x % TILE_SIZE - (TILE_SIZE / 2)) < PRECISION)){
        if((abs(circle.getLocation().y % TILE_SIZE - (TILE_SIZE / 2)) < PRECISION)) {
            //Pac-Man moves for collision detection
            switch(nextDir) {
                case UP:
                    setLocation(Point(getLocation().x, getLocation().y - speed));
                    break;
                case DOWN:
                    setLocation(Point(getLocation().x, getLocation().y + speed));
                    break;
                case LEFT:
                    setLocation(Point(getLocation().x - speed, getLocation().y));
                    break;
                case RIGHT:
                    setLocation(Point(getLocation().x + speed, getLocation().y));
                    break;
                case STATIC:
                    break;
            }

            if(m.collides(circle)) {
                switch(nextDir) {
                    case UP:
                        setLocation(Point(getLocation().x, getLocation().y + speed));
                        break;
                    case DOWN:
                        setLocation(Point(getLocation().x, getLocation().y - speed));
                        break;
                    case LEFT:
                        setLocation(Point(getLocation().x + speed, getLocation().y));
                        break;
                    case RIGHT:
                        setLocation(Point(getLocation().x - speed, getLocation().y));
                        break;
                    case STATIC:
                        break;
                }
            } else {
                setDirection(nextDir);
            }

        }
    }

    //Pac-Man moves for collision detection
	switch(getDirection()) {
		case UP:
			setLocation(Point(getLocation().x, getLocation().y - speed));
			break;
		case DOWN:
			setLocation(Point(getLocation().x, getLocation().y + speed));
			break;
		case LEFT:
			setLocation(Point(getLocation().x - speed, getLocation().y));
			break;
		case RIGHT:
			setLocation(Point(getLocation().x + speed, getLocation().y));
			break;
		case STATIC:
			break;
	}

	if(m.collides(circle)) {
		switch(getDirection()) {
			case UP:
				setLocation(Point(getLocation().x, getLocation().y + speed));
				break;
			case DOWN:
				setLocation(Point(getLocation().x, getLocation().y - speed));
				break;
			case LEFT:
				setLocation(Point(getLocation().x + speed, getLocation().y));
				break;
			case RIGHT:
				setLocation(Point(getLocation().x - speed, getLocation().y));
				break;
			case STATIC:
				break;
		}
		setDirection(STATIC);
	}
}

void PacMan::update(SDL_Plotter& g) {
    switch(g.getKey()) {
		case 'W':
			nextDir = UP;
			//cout << "UP" << endl;
			break;
		case 'S':
			nextDir = DOWN;
			//cout << "DOWN" << endl;
			break;
		case 'A':
			nextDir = LEFT;
			//cout << "LEFT" << endl;
			break;
		case 'D':
			nextDir = RIGHT;
			//cout << "RIGHT" << endl;
			break;
		case UP_ARROW:
			nextDir = UP;
			//cout << "UP" << endl;
			break;
		case DOWN_ARROW:
			nextDir = DOWN;
			//cout << "DOWN" << endl;
			break;
		case LEFT_ARROW:
			nextDir = LEFT;
			//cout << "LEFT" << endl;
			break;
		case RIGHT_ARROW:
			nextDir = RIGHT;
			//cout << "RIGHT" << endl;
			break;
		case ' ':
			nextDir = STATIC;
			//cout << "STOP" << endl;
			break;
    }
}

void PacMan::setDirection(Direction d) {
    circle.setDirection(d);

}

void PacMan::setLocation(const Point& p) {
    Point p2 = p;

    //Teleport on the left and right edges of map
    if(p.x > MAP_WIDTH * TILE_SIZE) {
        p2.x = 0;
    } else if(p.x < 0) {
        p2.x = MAP_WIDTH * TILE_SIZE;
    }

	circle.setLocation(p2);

	//Pac-Man mouth location update
	mouth.setP1(p2);
    switch(getDirection()) {
    case UP:
        mouth.setP2(Point(p2.x-getRadius()/2,p2.y -getRadius()));
        mouth.setP3(Point(p2.x+getRadius()/2,p2.y -getRadius()));
        break;
    case DOWN:
        mouth.setP2(Point(p2.x-getRadius()/2,p2.y +getRadius()));
        mouth.setP3(Point(p2.x+getRadius()/2,p2.y +getRadius()));
        break;
    case LEFT:
        mouth.setP2(Point(p2.x-getRadius(),p2.y -getRadius()/2));
        mouth.setP3(Point(p2.x-getRadius(),p2.y +getRadius()/2));
        break;
    case RIGHT:
        mouth.setP2(Point(p2.x+getRadius(),p2.y -getRadius()/2));
        mouth.setP3(Point(p2.x+getRadius(),p2.y +getRadius()/2));
        break;
    case STATIC:
        break;
    }
}

void PacMan::setScore(int s) {
    score = s;
}

void PacMan::setSpeed(int s) {
    speed = s;
}

/*PacMan::PacMan(const Point& p) : Circle(p, PLAYER_DIAMETER / 2.0, yellow) {
	direction = STATIC;
	audioLast = SDL_GetTicks();
	mouth.setP1(p);
}


Rectangle PacMan::getBounds() const {
	return Rectangle(Point(getLocation().x - getDiameter(), getLocation().y - getDiameter()), getDiameter(), getDiameter(), getColor());
}

void PacMan::draw(SDL_Plotter& g) {
	Circle::draw(g);
	switch(getDirection()) {
		case LEFT:
			mouth.setP2(Point(getLocation().x - getRadius(), getLocation().y - getRadius()));
			break;
		case RIGHT:
			mouth.setP3(Point(getLocation().x - getRadius(), getLocation().y + getRadius()));
			break;
	}
	mouth.setP1(getLocation());
	//mouth.draw(g, true);
}

void PacMan::setAudio(bool a) {
	audio = a;
}

void PacMan::setAudioLast(long last) {
	audioLast = last;
}

void PacMan::move(SDL_Plotter& g, Map& map) {
	if(map.collides(*this)) {
		setDirection(STATIC);
	}
	switch(getDirection()) {
		case STATIC:
			break;
		case UP:
			setLocation(Point(getLocation().x, getLocation().y - PLAYER_SPEED));
			break;
		case DOWN:
			setLocation(Point(getLocation().x, getLocation().y + PLAYER_SPEED));
			break;
		case LEFT:
			setLocation(Point(getLocation().x - PLAYER_SPEED, getLocation().y));
			break;
		case RIGHT:
			setLocation(Point(getLocation().x + PLAYER_SPEED, getLocation().y));
			break;
	}
}*/
