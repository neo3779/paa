#include "gameObject.h"

GameObject::GameObject()
{

}

int GameObject::GameObjectInit()
{
	/* TO DO: add relevant code */

	// Initialise dynamics parameters (for physics simulation) of world objects
	par = new ParticleModel();
	fric = new Friction();

	/* TO DO: Call functions to set other particle model parameters, e.g. velocity, acceleration, ... */

    // Initialise appearance parameters of game object
	setGameObject2Square();         /* Set game object of object to square */
    
	for(int i = 0; i < 4; i++)
	{
		slopeSides[i] =0.0F; 
	}

	return 1;
}

GameObject::~GameObject()
{
	/* TO DO: add relevant code */

	gameObjectCleanUp();

	return;			
}

void GameObject::gameObjectCleanUp()
{
	/* TO DO: add relevant code */

	return;			
}

void GameObject::setGameObject2Square()
{
    /* Load polygon (game object) data into vertex array */
    gameObject[0].x = 0.0F;		gameObject[0].y = 0.0F;
    gameObject[1].x = 10.0F;	gameObject[1].y = 0.0F;
    gameObject[2].x = 10.0F;	gameObject[2].y = 10.0F;
    gameObject[3].x = 0.0F;		gameObject[3].y = 10.0F;
	slopes();
}

void GameObject::setGameObjectUp(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y, float p4x, float p4y)
{
	gameObject[0].x = p1x;	gameObject[0].y = p1y;
    gameObject[1].x = p2x;	gameObject[1].y = p2y;
    gameObject[2].x = p3x;	gameObject[2].y = p3y;
    gameObject[3].x = p4x;	gameObject[3].y = p4y;
	slopes();
}

void GameObject::setGameObject2Point()
{
    /* Load polygon (game object) data into vertex array */
    gameObject[0].x = 0.0F;	gameObject[0].y = 0.0F;
    gameObject[1].x = 1.0F;	gameObject[1].y = 0.0F;
    gameObject[2].x = 1.0F;	gameObject[2].y = 1.0F;
    gameObject[3].x = 0.0F;	gameObject[3].y = 1.0F;
	slopes();
}

ParticleModel* GameObject::particle()
{
	return par;
}

Friction* GameObject::friction()
{
	return fric;
}
int GameObject::draw(GraphicsM * pGraphicsModule)
{
	if(drawPart)
	{
		dispBufUpdate();	// update content of display buffer (with outline of square at its current position)
		pGraphicsModule->drawPolygon(dispBuffObj, 4, true); // display content of buffer
		return 1;
	}
	return 0;
}

/*
 * Updates content of display buffer.
 *
 * Parameter list
 *        none.
 */
int GameObject::dispBufUpdate()
{
	/* TO DO: add relevant code */

	// update display object (content of display buffer (with calculated vertex coordinates of square at its current position))
	for (int vert = 0; vert < 4; ++vert)
	  {
		  dispBuffObj[vert].x = gameObject[vert].x + par->getPosition().x;
		  dispBuffObj[vert].y = gameObject[vert].y + par->getPosition().y;
	  }

	return 1;
}

void GameObject::setDrawPart(bool draw) 
{
	drawPart = draw;
}
bool GameObject::getDrawPart()
{
	return drawPart;
}

float GameObject::slop(int i)
{
	return slopeSides[i];
}

void GameObject::slopes()
{
	slopeSides[0] = slopeBetweenPoints(0,1);
	slopeSides[1] = slopeBetweenPoints(1,2);
	slopeSides[2] = slopeBetweenPoints(2,3);
	slopeSides[3] = slopeBetweenPoints(0,3);
}

float GameObject::slopeBetweenPoints(int i , int k)
{
	if((gameObject[k].x - gameObject[i].x == 0)||
		(gameObject[k].y - gameObject[i].y == 0))
	{
		return 0.0F;
	}
	else 
	{
		return (gameObject[i].y - gameObject[k].y)/(gameObject[i].x - gameObject[k].x);
	}

}

Point2D GameObject :: pointOnLine(int index)
{
	Point2D point; 
	point.x = gameObject[index].x + par->getPosition().x;
	point.y = gameObject[index].y + par->getPosition().y;
	return point;
}

Point2D  GameObject ::GameObjectPoint(int index)
{
	Point2D  temp;
		temp.x = gameObject[index].x;
		temp.y = gameObject[index].y;
	return temp;
}