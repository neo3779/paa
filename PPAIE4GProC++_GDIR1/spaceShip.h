#ifndef _SPACESHIT_H
#define _SPACESHIT_H

#include	"particleModel.h"			/* include file for particle module */
#include	"graphics.h"				/* include file for graphics module */

class SpaceShip
	{
	private:

		static const int numPoints = 6;

		Point2D		gameObject[numPoints];			// array to store a polygonal GameObject consisting of four vertices (e.g. a square) 
		Point2D		dispBuffObj[numPoints];		// array to store display coordinates of a polygonal object

		ParticleModel *par;

	public:
		SpaceShip();
		~SpaceShip();

		int spaceShipInit();						// Initialise the world

		int draw(GraphicsM * pGraphicsModule);			// Draw the world

		
		void spaceShipCleanUp();
		
		void setUpSpaceShip();

		int dispBufUpdate();

		ParticleModel *particle();

		
	private: 

	};

#endif /* _GameObject_H */
