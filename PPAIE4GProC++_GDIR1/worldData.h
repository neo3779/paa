/*
 * File name:		worldData.h
 * Description:		Header file for worldData.cpp
 *
 * Author: 			Claude C. Chibelushi
 * Date:			04/10/04
 *					Modified 27/09/06, by CCC: addition of setShape2Square() function prototype.
 *					Modified 19/01/09 by CCC: porting to C++
 *							 06/02/09 by CCC: additional functionality required  
 *                           for illustrative examples of GDI drawing functionality.
 *
 */
 

#ifndef _WORLDDATA_H
#define _WORLDDATA_H

#include	<math.h>
#include	<windows.h>
#include	"dataTypes.h"		/* include file for custom data types */
#include	"graphics.h"		/* include file for graphics module */
#include	"input.h"			/* include file for user input module */
#include	"gameObject.h"		/* include file for GameObject module */
#include	"particleSystem.h"			/* include file for swarm module */
#include	"spaceShip.h"

class WorldData
	{
	private:

	/*
	 * Attributes of objects that make up the game world
	 */
	
	static const int astNums = 5;
	static const int dinoNums = 2;

	GameObject hill;
	GameObject cover;
	GameObject player;
	GameObject dinos [dinoNums];
	GameObject asteroids [astNums];
	SpaceShip  spaceShip;
	ParticleSystem explosions [astNums];
	ParticleSystem flys;	
	Random rnd;

	public:

		// Constructors and destructor
		WorldData();
		~WorldData();

		int		worldDataModuleInit(GraphicsM * pGraphicsModule);					// Initialise the world
		void	worldCleanUp();														// Release objects, if applicable
		int		update(keyEvent kEvent,GraphicsM * pGraphicsModule,float timeStep);	// Update the world's dynamics state
		int		draw(GraphicsM * pGraphicsModule);									// Draw the world

	private: 
	
		void	restAsteroid(int i);
		void	directionParticle(int i);
		void	switchXDirSpaceShip();
		void	switchYDirAsteroids(int i);
		float	randomInt(int max);
		float	randomFloat();
		
		float	magnitude(float x,float y);
		Point2D	nonAxisAlignedCollision(Point2D a, Point2D b);
		Point2D	normalizeVector(Point2D a);
		Point2D	scalarMultiply(float scale, Point2D a);
		float	dotProduct(Point2D a, Point2D b);
		Point2D	sumVectors(Point2D a , Point2D b);
		float	slopeBetweenPoints(Point2D p1, Point2D p2);
		float	perpSlope(float slope);
		bool	arePerp (float slope1 ,float slope2);
		Point2D lineIntersect (Point2D L1Point,float L1Slope, Point2D L2Point,float L2Slope);
};
#endif /* _WORLDDATA_H */
