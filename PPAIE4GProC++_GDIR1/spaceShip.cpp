#include "spaceShip.h"

SpaceShip::SpaceShip()
{

}

int SpaceShip::spaceShipInit()
{
	/* TO DO: add relevant code */

	// Initialise dynamics parameters (for physics simulation) of world objects
	par = new ParticleModel();

	/* TO DO: Call functions to set other particle model parameters, e.g. velocity, acceleration, ... */

    // Initialise appearance parameters of game object
	setUpSpaceShip();         /* Set game object of object to square */
        
	return 1;
}

SpaceShip::~SpaceShip()
{
	/* TO DO: add relevant code */

	spaceShipCleanUp();

	return;			
}

void SpaceShip::spaceShipCleanUp()
{
	/* TO DO: add relevant code */

	return;			
}

void SpaceShip::setUpSpaceShip()
{
    /* Load polygon (game object) data into vertex array */
    gameObject[0].x = 0.0F;		gameObject[0].y = 0.0F;
    gameObject[1].x = 25.0F;	gameObject[1].y = -25.0F;
    gameObject[2].x = 100.0F;	gameObject[2].y = -25.0F;
    gameObject[3].x = 125.0F;	gameObject[3].y = 0.0F;
	gameObject[4].x = 100.0F;	gameObject[4].y = 25.0F;
	gameObject[5].x = 25.0F;	gameObject[5].y = 25.0F;
}

ParticleModel* SpaceShip::particle()
{
	return par;
}

int SpaceShip::draw(GraphicsM * pGraphicsModule)
	{
    /* TO DO: add relevant code */

    /* Display world */

	//   Draw the square.
    dispBufUpdate();	// update content of display buffer (with outline of square at its current position)
	pGraphicsModule->drawPolygon(dispBuffObj, numPoints, true); // display content of buffer

	return 1;
    }

/*
 * Updates content of display buffer.
 *
 * Parameter list
 *        none.
 */
int SpaceShip::dispBufUpdate()
	{
    /* TO DO: add relevant code */

    // update display object (content of display buffer (with calculated vertex coordinates of square at its current position))
    for (int vert = 0; vert < numPoints; ++vert)
      {
		  dispBuffObj[vert].x = gameObject[vert].x + par->getPosition().x;
		  dispBuffObj[vert].y = gameObject[vert].y + par->getPosition().y;
      }

    return 1;
	}