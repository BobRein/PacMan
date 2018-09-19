/*
 Authors: Bob Rein, Daniel Brubacher, Griffin Bohanson, Hunter Long, Noah Olsen
 Assignment Title: PacMan Group Project
 ASSIGNMENT DESCRIPTION: Create a PacMan game using SDL Plotter and C++
 Due Date: 12/4/17
 Date Created: 10/8/17
 Date Last Modified: 12/3/17
 */
#include "ghost.h"
#include "map.h"
#include "circle.h"
//Ghost
Ghost::Ghost() {
	speed = ENEMY_SPEED;
}
Ghost::Ghost(Point p) {
	circle = Circle(Point(p), PLAYER_RADIUS, ghostColor, STATIC);
	rectangle = Rectangle(Point(p.x - PLAYER_RADIUS,p.y-2), Point(p.x+PLAYER_RADIUS,p.y + PLAYER_RADIUS), ghostColor);
	//last = clock();
	speed = ENEMY_SPEED;
}
void Ghost::setColor(Color c)
{
    circle.setColor(c);
    rectangle.setColor(c);
}
Direction Ghost::getDirection() const {
	return circle.getDirection();
}
double Ghost::getRadius() const {
	return circle.getRadius();
}
Point Ghost::getLocation() const {
	return circle.getLocation();
}
Circle Ghost::getCircle() const {
    return circle;
}
void Ghost::draw(SDL_Plotter& g) {
    circle.draw(g);
    rectangle.draw(g);
    tri1.draw(g,true);
    tri2.draw(g,true);
    tri3.draw(g,true);

}
void Ghost::setDirection(Direction d) {
    circle.setDirection(d);
}
void Ghost::setLocation(const Point& p) {
    Point p2 = p;
    //Teleport on the left and right edges of map
    if(p.x > MAP_WIDTH * TILE_SIZE) {
        p2.x = 0;
    } else if(p.x < 0) {
        p2.x = MAP_WIDTH * TILE_SIZE;
    }
	circle.setLocation(p2);
	rectangle.setUL(Point(p2.x-getRadius(),p2.y-2));//minus two just helps with the aesthetic
    rectangle.setLR(Point(p2.x+getRadius(),p2.y+getRadius()));
    //  5 6 7
    // 1 2 3 4
    Point point1= Point(p2.x-getRadius(),p2.y+getRadius());
    Point point2= Point(p2.x-getRadius()*1/3,p2.y+getRadius());
    Point point3= Point(p2.x+getRadius()*1/3,p2.y+getRadius());
    Point point4= Point(p2.x+getRadius(),p2.y+getRadius());
    Point point5= Point(p2.x-getRadius()*2/3,p2.y+getRadius()-TRIANGLE_HEIGHT_GHOST);
    Point point6= Point(p2.x,p2.y+getRadius()-TRIANGLE_HEIGHT_GHOST);
    Point point7= Point(p2.x+getRadius()*2/3,p2.y+getRadius()-TRIANGLE_HEIGHT_GHOST);
    tri1=Triangle(point5,point1,point2,black);
    tri2=Triangle(point6,point2,point3,black);
    tri3=Triangle(point7,point3,point4,black);
}

void Ghost::move(SDL_Plotter& g, Map& m,PacMan& pac, bool afraid,Ghost listOfGhosts[]) {

    //Check if in center of a rectangle
        if(circle.getLocation().x % TILE_SIZE == TILE_SIZE / 2 ){
                if(circle.getLocation().y % TILE_SIZE==TILE_SIZE / 2) {
                //generate nextDir
                if(afraid)
                {
                    getRetreatDirection(m,pac,nextDirection, listOfGhosts);
                }
                else
                {
                    getAttackDirection(m,pac,nextDirection, listOfGhosts);
                }
                setDirection(nextDirection);
            }
        }

    //ghost moves
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
    //ghost moves back if wrong
	if(m.collides(circle)) {
		switch(getDirection()) {
			case UP:
				setLocation(Point(getLocation().x, getLocation().y + speed+1));
				break;
			case DOWN:
				setLocation(Point(getLocation().x, getLocation().y - speed-1));
				break;
			case LEFT:
				setLocation(Point(getLocation().x + speed+1, getLocation().y));
				break;
			case RIGHT:
				setLocation(Point(getLocation().x - speed-1, getLocation().y));
				break;
			case STATIC:
				break;
		}
		setDirection(STATIC);
	}
}

void Ghost::getAttackDirection (Map& m1,PacMan& pac1, Direction& nextDir,Ghost list[])
{
    double testdist=0, minDist;
    int myX,myY;
    myX=circle.getLocation().x;
    myY=circle.getLocation().y;
    minDist= 2*(pow(pac1.getLocation().x-myX,2)+pow(pac1.getLocation().y-myY,2));// this is doubled so that at least one direction is always shorter
    nextDir = STATIC;
    Circle c;

    c= Circle(Point(myX,myY-5),circle.getRadius(),red, nextDir);
    testdist = pow(pac1.getLocation().x-myX,2)+pow(pac1.getLocation().y-(myY-5),2);
    if (testdist<minDist && !collidesWithOtherGhost(list,c)&& !(m1.collides(c)) )
    {
        minDist= testdist;
        nextDir=UP;
    }

    c=Circle(Point(myX,myY+5),circle.getRadius(),red, nextDir);
    testdist = pow(pac1.getLocation().x-myX,2)+pow(pac1.getLocation().y-(myY+5),2);
    if (testdist<minDist && !collidesWithOtherGhost(list, c)&& !(m1.collides(c)) )
    {
        minDist= testdist;
        nextDir=DOWN;
    }

    c= Circle(Point(myX-5,myY),circle.getRadius(),red, nextDir);
    testdist = pow(pac1.getLocation().x-(myX-5),2)+pow(pac1.getLocation().y-myY,2);
    if (testdist<minDist && !collidesWithOtherGhost(list, c)&& !(m1.collides(c)) )
    {
        minDist= testdist;
        nextDir=LEFT;
    }

    c= Circle(Point(myX+5,myY),circle.getRadius(),red, nextDir);
    testdist = pow(pac1.getLocation().x-(myX+5),2)+pow(pac1.getLocation().y-myY,2);
    if (testdist<minDist && !collidesWithOtherGhost(list, c)&& !(m1.collides(c)) )
    {
        minDist= testdist;
        nextDir=RIGHT;
    }

}

void Ghost::getRetreatDirection(Map& m1,PacMan& pac1, Direction& nextDir,Ghost list [])
{
    double testdist=0, maxDist;
    Circle c;
    int myX,myY;
    myX=circle.getLocation().x;
    myY=circle.getLocation().y;
    maxDist=0;// 2*(pow(pac1.getLocation().x-myX,2)+pow(pac1.getLocation().y-myY,2));// this is doubled so that at least one direction is always shorter
    nextDir = STATIC;

    c = Circle(Point(myX,myY-5),circle.getRadius(),red, nextDir);
    testdist = pow(pac1.getLocation().x-myX,2)+pow(pac1.getLocation().y-(myY-5),2);
    if (testdist>maxDist && !collidesWithOtherGhost(list,c) && !(m1.collides(c)) )
    {
        maxDist= testdist;
        nextDir=UP;
    }

    c=Circle(Point(myX,myY+5),circle.getRadius(),red, nextDir);
    testdist = pow(pac1.getLocation().x-myX,2)+pow(pac1.getLocation().y-(myY+5),2);
    if (testdist>maxDist && !collidesWithOtherGhost(list,c) && !(m1.collides(c)) )
    {
        maxDist= testdist;
        nextDir=DOWN;
    }

    c= Circle(Point(myX-5,myY),circle.getRadius(),red, nextDir);
    testdist = pow(pac1.getLocation().x-(myX-5),2)+pow(pac1.getLocation().y-myY,2);
    if (testdist>maxDist && !collidesWithOtherGhost(list,c) && !(m1.collides(c)) )
    {
        maxDist= testdist;
        nextDir=LEFT;
    }

    c= Circle(Point(myX+5,myY),circle.getRadius(),red, nextDir);
    testdist = pow(pac1.getLocation().x-(myX+5),2)+pow(pac1.getLocation().y-myY,2);
    if (testdist>maxDist && !collidesWithOtherGhost(list,c) && !(m1.collides(c)) )
    {
        maxDist= testdist;
        nextDir=RIGHT;
    }
}
bool Ghost::collidesWithOtherGhost (Ghost list1 [], Circle c)
{
    for(int i =0; i< 3; i++)//should be numOfGhosts instead of 3, but I didin't want to pass it all the way
    {
         if(c.getLocation().distTo(list1[i].getCircle().getLocation())<30 && circle.getLocation().distTo(list1[i].getCircle().getLocation())!=0)
         {
           return true;
         }
    }
    return false;
}

