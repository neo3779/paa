/*
 * File name:	worldData.cpp
 * Description:	World data module.
 *
 * Author: 			Claude C. Chibelushi
 * Date:			04/10/04
 *					Modified 27/09/06, by CCC: addition of function for setting object game object
 *					Modified 19/01/09 by CCC: porting to C++
 *							 06/02/09 by CCC: additional functionality required  
 *                           for illustrative examples of GDI drawing functionality.
 *
 */

#include "worldData.h"

/*----------------------------------------------------------------------------\
 *                                                                            |
 *                       INITIALISATION AND CLEAN UP                   		  |
 *                                                                            |
 *----------------------------------------------------------------------------*/

/*
	Constructs and initialises a world data management module

	Parameter list
		none
 */

WorldData::WorldData()
{

}

/*
	Destructs world data management module

	Parameter list
		none
 */
WorldData::~WorldData()
{
	/* TO DO: add relevant code */

	worldCleanUp();

	return;			
}

/*
 Releases objects

 Parameter list
 	none
 */

void WorldData::worldCleanUp()
{
/* TO DO: add relevant code */

	return;			
}

/**
    Initialises the world

	Parameter list
         none.
  */
int WorldData::worldDataModuleInit(GraphicsM * pGraphicsModule)
{
	rnd.randomInit();

	player.GameObjectInit();
	player.setGameObjectUp(0.0F,0.0F,
						   100.0F,0.0F,
						   100.0F,5.0F,
						   0.0F,5.0F);
	player.friction()->setFriction(1.0F);
	player.particle()->setPosition(492.0F,387.0F);
	player.particle()->setPosition(11.0F,387.0F);
	player.particle()->setMass(1.0F);
	player.particle()->setForce(0.1F, 0.0F);
	player.particle()->setApg(false);

	hill.GameObjectInit();
	hill.setGameObjectUp(0.0F,0.0F,
						100.0F,0.0F,
						300.0F,75.0F,
						-200.0F,75.0F);
	hill.friction()->setFriction(1.0F);
	hill.particle()->setPosition(624,663);
	hill.slopes();

	cover.GameObjectInit();
	cover.setGameObjectUp(0.0F,0.0F,
						0.0F,10.0F,
						200.0F,10.0F,
						200.0F,0.0F);
	cover.friction()->setFriction(1.0F);
	cover.particle()->setPosition(10,563);

	flys.particleSystemInit();
	flys.viewAllPart();

	spaceShip.spaceShipInit();
	spaceShip.particle()->setPosition(11.0F,100.0F);
	spaceShip.particle()->setForce(0.1F, 0.0F);
	spaceShip.particle()->setMass(1.0F);
	spaceShip.particle()->setApg(false);

	for (int i = 0; i < astNums; i++)
	{
		asteroids[i].GameObjectInit();
		asteroids[i].setGameObjectUp(0.0F,0.0F,
									5.0F,-5.0F,
									0.0F,-10.0F,
									-5.0F,-5.0F);
		asteroids[i].slopes();
		explosions[i].particleSystemInit();
		restAsteroid(i);

	}

	for (int i = 0; i < dinoNums; i++)
	{
		dinos[i].GameObjectInit();
		dinos[i].particle()->setMass((float)rnd.getInt(100));
		dinos[i].particle()->setForce(1.0f,1.0f);
		dinos[i].particle()->setInitVelocity((float)rnd.getIntBetween(15,50)*-1,(float)rnd.getIntBetween(15,50)*-1);
		dinos[i].particle()->setPosition(100.0F,100.0F);
		dinos[i].particle()->setAngle((float)rnd.getIntBetween(20,70)*-1);
		dinos[i].particle()->projectileMotion();
		dinos[i].particle()->setPosition(1024.0F,728.0F);
	}

	return 1;
}

void WorldData::restAsteroid(int i)
{	
	asteroids[i].particle()->setMass((float)rnd.getInt(100));
	asteroids[i].particle()->setVelocity(0.0F,0.0F);
	asteroids[i].particle()->setAcceleration(0.0F,0.0F);
	if(rnd.getInt(2) == 1)
	{
		asteroids[i].particle()->setForce((float)rnd.getInt(100) *-1,(float)rnd.getInt(100));
	}
	else
	{
		asteroids[i].particle()->setForce((float)rnd.getInt(100)  ,(float)rnd.getInt(100));
	}
	asteroids[i].particle()->setPosition(spaceShip.particle()->getPosition().x + 60 ,spaceShip.particle()->getPosition().y + 35);

}

void WorldData::switchXDirSpaceShip()
{
	spaceShip.particle()->setVelocity(spaceShip.particle()->getVelocity().x * -1,spaceShip.particle()->getVelocity().y);
	spaceShip.particle()->setAcceleration(spaceShip.particle()->getAcceleration().x * -1,spaceShip.particle()->getAcceleration().y);
	spaceShip.particle()->setForce(spaceShip.particle()->getForce().x * -1,spaceShip.particle()->getForce().y);
	spaceShip.particle()->setVelocity(0.0F,0.0F);
}

void WorldData::switchYDirAsteroids(int i)
{
	asteroids[i].particle()->setVelocity(asteroids[i].particle()->getVelocity().x,asteroids[i].particle()->getVelocity().y * -1);
	asteroids[i].particle()->setAcceleration(asteroids[i].particle()->getAcceleration().x,asteroids[i].particle()->getAcceleration().y * -1);
	asteroids[i].particle()->setForce(asteroids[i].particle()->getForce().x,asteroids[i].particle()->getForce().y * -1);
}


/* TODO: Add functions to get other particle model parameters, e.g. velocity, acceleration, ... */

		/*----------------------------------------------------------------------------\
		 *                                                                            |
		 *                                  STATE UPDATE                              |
		 *                                                                            |
		 *----------------------------------------------------------------------------*/
 
/*
 * Updates world state.

	Parameter list
         kEvent       input event ID.
 */

int WorldData::update(keyEvent kEvent,GraphicsM * pGraphicsModule,float timeStep)
{
	/* TO DO: add relevant code */
	// For example:
	// update world position of square as determined by user input.
	switch(kEvent)
		{
		// Update parameters of virtual world
		case LEFT:
			// TO DO: service up-key as approriate
			if(player.particle()->getVelocity().x > 0 &&
				player.particle()->getAcceleration().x > 0 &&
				player.particle()->getForce().x > 0)
			{
				player.particle()->setVelocity(player.particle()->getVelocity().x * -1,player.particle()->getVelocity().y);
				player.particle()->setAcceleration(player.particle()->getAcceleration().x * -1,player.particle()->getAcceleration().y);
				player.particle()->setForce(player.particle()->getForce().x * -1,player.particle()->getForce().y);
				player.particle()->setVelocity(0.0F,0.0F);
			}
			break;
		case RIGHT:
			// TO DO: service down-key as approriate

			if(player.particle()->getVelocity().x < 0 &&
				player.particle()->getAcceleration().x < 0 &&
				player.particle()->getForce().x < 0)
			{
				player.particle()->setVelocity(player.particle()->getVelocity().x * -1,player.particle()->getVelocity().y);
				player.particle()->setAcceleration(player.particle()->getAcceleration().x * -1,player.particle()->getAcceleration().y);
				player.particle()->setForce(player.particle()->getForce().x * -1,player.particle()->getForce().y);
				player.particle()->setVelocity(0.0F,0.0F);
			}
			break;
		default:
			// TO DO: service "all-other-keys" as approriate

			break;
		}

	spaceShip.particle()->move(timeStep);
	flys.swarmMove(timeStep);
	player.particle()->move(timeStep);

	Point2D point,point2;
	
	point.x = 0;
	point.y = 0;

	float temp,y,x;

	for (int i = 0; i < astNums; i++)
	{
		asteroids[i].particle()->move(timeStep);
		explosions[i].explosionMove(timeStep, pGraphicsModule);

		if(hill.slop(3) != asteroids[i].particle()->getVelocity().y/asteroids[i].particle()->getVelocity().x)
		{
			y = asteroids[i].particle()->getVelocity().y;
			x = asteroids[i].particle()->getVelocity().x;
			if (y == 0 || x == 0)
				temp = 0;
			else
				temp = y/x;

			point = lineIntersect(hill.particle()->getPosition(),hill.slop(3),asteroids[i].particle()->getPosition(),temp);

			if (point.x < 0)
				point.x = point.x * -1;
			if(point.y < 0)
				point.y = point.y * -1;

			if (asteroids[i].particle()->getPosition().x > point.x &&
				asteroids[i].particle()->getPosition().y > point.y)
			{
				if(asteroids[i].particle()->getPosition().x < hill.particle()->getPosition().x &&
					asteroids[i].particle()->getPosition().y > pGraphicsModule->viewport.bottom - 40)
				{

					explosions[i].setPosition(point.x,point.y);
					explosions[i].setExplod(true);
					restAsteroid(i);
				}
			}
		}

		if(hill.slop(1) != asteroids[i].particle()->getVelocity().y/asteroids[i].particle()->getVelocity().x)
		{
			y = asteroids[i].particle()->getVelocity().y;
			x = asteroids[i].particle()->getVelocity().x;
			if (y == 0 || x == 0)
				temp = 0;
			else
				temp = y/x;
			
			point.x = hill.particle()->getPosition().x + hill.GameObjectPoint(1).x;
			point.y = hill.particle()->getPosition().y;

			point = lineIntersect(point,hill.slop(1),asteroids[i].particle()->getPosition(),temp);
			
			if (point.x < 0)
				point.x = point.x * -1;
			if(point.y < 0)
				point.y = point.y * -1;

			if (asteroids[i].particle()->getPosition().x < point.x  &&
				asteroids[i].particle()->getPosition().y > point.y)
			{
				if(asteroids[i].particle()->getPosition().x > hill.particle()->getPosition().x &&
					asteroids[i].particle()->getPosition().y > pGraphicsModule->viewport.bottom - 40)
				{

					explosions[i].setPosition(point.x,point.y);
					explosions[i].setExplod(true);
					restAsteroid(i);
				}
			}
		}		
	}
	
	for (int i = 0; i < dinoNums; i++)
	{
		dinos[i].particle()->projectileMotion();
		dinos[i].particle()->move(timeStep);
	}

	for (int i = 0; i < dinoNums; i++)
	{
		if(dinos[i].particle()->getPosition().y > pGraphicsModule->viewport.bottom - 40 && dinos[i].particle()->getVelocity().y > 0)
		{
			dinos[i].particle()->setVelocity(dinos[i].particle()->getVelocity().x,dinos[i].particle()->getVelocity().y * -1);
			dinos[i].particle()->setAcceleration(dinos[i].particle()->getAcceleration().x,dinos[i].particle()->getAcceleration().y * -1);
			dinos[i].particle()->setForce(dinos[i].particle()->getForce().x ,dinos[i].particle()->getForce().y * -1);
			//dinos[i].particle()->setInitVelocity(dinos[i].particle()->getInitVelocity().x, dinos[i].particle()->getInitVelocity().y * -1);
		
			if(dinos[i].particle()->getPosition().x < cover.particle()->getPosition().x + 100)
			{
				dinos[i].particle()->setVelocity(dinos[i].particle()->getVelocity().x * -1,dinos[i].particle()->getVelocity().y );
				dinos[i].particle()->setAcceleration(dinos[i].particle()->getAcceleration().x * -1,dinos[i].particle()->getAcceleration().y );
				dinos[i].particle()->setForce(dinos[i].particle()->getForce().x * -1,dinos[i].particle()->getForce().y);
			}
		}
		if(dinos[i].particle()->getPosition().x + 10 > pGraphicsModule->viewport.right)
		{
			dinos[i].particle()->setVelocity(dinos[i].particle()->getVelocity().x* -1,dinos[i].particle()->getVelocity().y );
			dinos[i].particle()->setAcceleration(dinos[i].particle()->getAcceleration().x* -1,dinos[i].particle()->getAcceleration().y );
			dinos[i].particle()->setForce(dinos[i].particle()->getForce().x * -1,dinos[i].particle()->getForce().y );
		}

		if(dinos[i].particle()->getPosition().y > hill.particle()->getPosition().y &&
			dinos[i].particle()->getPosition().x > hill.particle()->getPosition().x &&
			dinos[i].particle()->getPosition().x < hill.particle()->getPosition().x + 100 &&
			dinos[i].particle()->getVelocity().y > 0)
		{
			dinos[i].particle()->setVelocity(dinos[i].particle()->getVelocity().x,dinos[i].particle()->getVelocity().y * -1);
			dinos[i].particle()->setAcceleration(dinos[i].particle()->getAcceleration().x,dinos[i].particle()->getAcceleration().y* -1 );
			dinos[i].particle()->setForce(dinos[i].particle()->getForce().x,dinos[i].particle()->getForce().y* -1 );
		}

		if(hill.slop(1) != dinos[i].particle()->getVelocity().y/dinos[i].particle()->getVelocity().x)
		{
			y = dinos[i].particle()->getVelocity().y;
			x = dinos[i].particle()->getVelocity().x;
			if (y == 0 || x == 0)
				temp = 0;
			else
				temp = y/x;
			
			point.x = hill.particle()->getPosition().x + hill.GameObjectPoint(1).x;
			point.y = hill.particle()->getPosition().y;

			point = lineIntersect(point,hill.slop(1),dinos[i].particle()->getPosition(),temp);
			
			if (point.x < 0)
				point.x = point.x * -1;
			if(point.y < 0)
				point.y = point.y * -1;

			if (dinos[i].particle()->getPosition().x + 10 < point.x  &&
				dinos[i].particle()->getPosition().y + 10 > point.y)
			{
				if(dinos[i].particle()->getPosition().x > hill.particle()->getPosition().x &&
					dinos[i].particle()->getPosition().y > pGraphicsModule->viewport.bottom - 40)
				{
					dinos[i].particle()->setPosition(point.x - 10,point.y - 10);
				}
			}

			if (dinos[i].particle()->getPosition().x < point.x &&
				dinos[i].particle()->getPosition().y + 10 > point.y)
			{
				if(dinos[i].particle()->getPosition().x < hill.particle()->getPosition().x &&
					dinos[i].particle()->getPosition().y > pGraphicsModule->viewport.bottom - 40)
				{
					dinos[i].particle()->setPosition(point.x,point.y - 10);
				}
			}
		}		

		if(hill.slop(3) != dinos[i].particle()->getVelocity().y/dinos[i].particle()->getVelocity().x)
		{
			y = dinos[i].particle()->getVelocity().y;
			x = dinos[i].particle()->getVelocity().x;
			if (y == 0 || x == 0)
				temp = 0;
			else
				temp = y/x;

			point2.x = dinos[i].particle()->getPosition().x + 10;
			point2.y = dinos[i].particle()->getPosition().y + 10;
			
			point = lineIntersect(hill.particle()->getPosition(),hill.slop(3),point2 ,temp);
			
			if (point.x < 0)
				point.x = point.x * -1;
			if(point.y < 0)
				point.y = point.y * -1;

			if(dinos[i].particle()->getPosition().x + 10 > point.x &&
				dinos[i].particle()->getPosition().y + 10 > point.y)
			{
				if(dinos[i].particle()->getPosition().x < hill.particle()->getPosition().x &&
					dinos[i].particle()->getPosition().y > pGraphicsModule->viewport.bottom - 40)
				{
					dinos[i].particle()->setPosition(point.x - 10,point.y - 10);
				}
			}


			if (dinos[i].particle()->getPosition().x > point.x &&
				dinos[i].particle()->getPosition().y + 10 > point.y)
			{
				if(dinos[i].particle()->getPosition().x < hill.particle()->getPosition().x &&
					dinos[i].particle()->getPosition().y > pGraphicsModule->viewport.bottom - 40)
				{
					dinos[i].particle()->setPosition(point.x,point.y - 10);
				}
			}
		}

	}
	
	for (int i = 0; i < astNums; i++)
	{
		if(asteroids[i].particle()->getPosition().y > pGraphicsModule->viewport.bottom - 40 && 
			((asteroids[i].particle()->getPosition().x > 10 
			&&  asteroids[i].particle()->getPosition().x < hill.particle()->getPosition().x + hill.GameObjectPoint(3).x)||
			((asteroids[i].particle()->getPosition().x < 1034 
			&&  asteroids[i].particle()->getPosition().x > hill.particle()->getPosition().x + hill.GameObjectPoint(2).x))))
		{
			explosions[i].setPosition(asteroids[i].particle()->getPosition().x,(float)pGraphicsModule->viewport.bottom - 40);
			explosions[i].setExplod(true);
			restAsteroid(i);
		}
		if(asteroids[i].particle()->getPosition().y > hill.particle()->getPosition().y &&
			asteroids[i].particle()->getPosition().x > hill.particle()->getPosition().x &&
			asteroids[i].particle()->getPosition().x < hill.particle()->getPosition().x + 100)
		{
			explosions[i].setPosition(asteroids[i].particle()->getPosition().x,hill.particle()->getPosition().y);
			explosions[i].setExplod(true);
			restAsteroid(i);
		}
		if(asteroids[i].particle()->getPosition().y < pGraphicsModule->viewport.bottom *-2 ||
			asteroids[i].particle()->getPosition().x > pGraphicsModule->viewport.right * 2 ||
			asteroids[i].particle()->getPosition().x < pGraphicsModule->viewport.right * -2 )
		{
			restAsteroid(i);
		}

		if((asteroids[i].particle()->getPosition().x  + 10 < pGraphicsModule->viewport.left) ||
    		(asteroids[i].particle()->getPosition().x + 10 > pGraphicsModule->viewport.right))
		{
			asteroids[i].particle()->setVelocity(asteroids[i].particle()->getVelocity().x * -1,asteroids[i].particle()->getVelocity().y);
			asteroids[i].particle()->setAcceleration(asteroids[i].particle()->getAcceleration().x * -1,asteroids[i].particle()->getAcceleration().y);
			asteroids[i].particle()->setForce(asteroids[i].particle()->getForce().x * -1,asteroids[i].particle()->getForce().y);
		}		
		
		if(asteroids[i].particle()->getPosition().y + 5 > player.particle()->getPosition().y + 10)
		{
			if(asteroids[i].particle()->getPosition().x > player.particle()->getPosition().x &&
				asteroids[i].particle()->getPosition().x < player.particle()->getPosition().x + 100.0F &&
				asteroids[i].particle()->getVelocity().y > 0)
			{
				if(asteroids[i].particle()->getPosition().y >=player.particle()->getPosition().y )
				{
					switchYDirAsteroids(i);
				}
			}

			if(asteroids[i].particle()->getPosition().x > cover.particle()->getPosition().x &&
				asteroids[i].particle()->getPosition().x < cover.particle()->getPosition().x + 200 &&
				asteroids[i].particle()->getVelocity().y > 0)
			{
				if(asteroids[i].particle()->getPosition().y >= cover.particle()->getPosition().y )
				{
					switchYDirAsteroids(i);
				}
			}
		}
	}

	if(spaceShip.particle()->getPosition().x + 130 >= pGraphicsModule->viewport.right &&
		spaceShip.particle()->getAcceleration().x > 0 &&
		spaceShip.particle()->getForce().x > 0 &&
		spaceShip.particle()->getVelocity().x > 0)
	{
		switchXDirSpaceShip();
	}

	if(spaceShip.particle()->getPosition().x  <= pGraphicsModule->viewport.left &&
		spaceShip.particle()->getAcceleration().x < 0 &&
		spaceShip.particle()->getForce().x < 0 &&
		spaceShip.particle()->getVelocity().x < 0)
	{
		switchXDirSpaceShip();
	}
	if((player.particle()->getPosition().x + 100 > pGraphicsModule->viewport.right && player.particle()->getVelocity().x > 0) ||
		(player.particle()->getPosition().x  < pGraphicsModule->viewport.left && player.particle()->getVelocity().x < 0))
	{
		player.particle()->setVelocity(player.particle()->getVelocity().x * -1,player.particle()->getVelocity().y);
		player.particle()->setAcceleration(player.particle()->getAcceleration().x * -1,player.particle()->getAcceleration().y);
		player.particle()->setForce(player.particle()->getForce().x * -1,player.particle()->getForce().y);
		player.particle()->setVelocity(0.0F,0.0F);
	}

	return 1;
	
}

/*
	Updates particle position: move particle towards right.

	Parameter list
		none
 */

int WorldData::draw(GraphicsM * pGraphicsModule)
{
	/* TO DO: add relevant code */

    /* Display world */

	for (int i = 0; i < astNums; i++)
	{
		asteroids[i].draw(pGraphicsModule);
		explosions[i].draw(pGraphicsModule);
	}
	for (int i = 0; i < dinoNums; i++)
	{
		dinos[i].draw(pGraphicsModule);
	}

	spaceShip.draw(pGraphicsModule);
	hill.draw(pGraphicsModule);
	cover.draw(pGraphicsModule);
	flys.draw(pGraphicsModule);
	player.draw(pGraphicsModule);


	return 1;
}

float WorldData::magnitude(float x,float y)
{
	return sqrtf(x * x + y * y);
}

Point2D WorldData :: nonAxisAlignedCollision(Point2D a, Point2D b)
{
	Point2D temp0,temp1,temp2, length, reflection;
	float projection;

	temp0 = normalizeVector(a);

	temp1 = scalarMultiply(-1,b);

	projection = dotProduct(temp1,temp0);

	length =  scalarMultiply(projection,temp0);

	reflection = scalarMultiply(2, length);

	temp2 = sumVectors(scalarMultiply(-1,reflection),temp1);

	return temp2;
}

Point2D WorldData :: normalizeVector(Point2D a)
{
	Point2D temp;
	float mag;
	mag = magnitude(a.x,a.y);
	temp.x = a.x / mag;
	temp.y = a.y / mag;
	return temp;
}
Point2D WorldData :: scalarMultiply(float scale, Point2D a)
{
	Point2D temp;
	temp.x = a.x * scale;
	temp.y = a.y * scale;
	return temp;
}
float WorldData :: dotProduct(Point2D a, Point2D b)
{
	return a.x * b.x + a.y * b.y; 
}
Point2D WorldData :: sumVectors(Point2D a , Point2D b)
{
	Point2D temp;
	temp.x = a.x + b.x;
	temp.y = a.y + b.y;
	return temp;
}

float WorldData::slopeBetweenPoints(Point2D p1, Point2D p2)
{
	return (p2.x - p1.x)/(p2.y - p1.y);
}

float WorldData::perpSlope(float slope)
{
	return -1/slope;
}

bool WorldData::arePerp (float slope1 ,float slope2)
{
	if(slope1 * slope2 == -1)
	{
		return true;
	}
	return false;
}

Point2D WorldData::lineIntersect (Point2D L1Point,float L1Slope, Point2D L2Point,float L2Slope)
{
	Point2D temp; 
	
	temp.x = (L1Slope * L1Point.x - L2Slope * L2Point.x + L2Point.y  - L1Point.y)/(L1Slope - L2Slope);

	temp.y = L1Slope * (temp.x - L1Point.x) + L1Point.y;

	return temp;
}
