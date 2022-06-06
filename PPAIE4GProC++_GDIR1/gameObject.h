#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include	"particleModel.h"			/* include file for particle module */
#include	"graphics.h"				/* include file for graphics module */
#include	"friction.h"				/* include file for friction module */

class GameObject
	{
	private:

		Point2D		gameObject[4];			// array to store a polygonal GameObject consisting of four vertices (e.g. a square) 
		Point2D		dispBuffObj[4];			// array to store display coordinates of a polygonal object
		bool		drawPart;
		float		slopeSides[4];

		ParticleModel *par;
		Friction *fric;

		float slopeBetweenPoints(int i , int k);

	public:
		GameObject();
		~GameObject();

		ParticleModel *particle();
		Friction *friction();
		
		void gameObjectCleanUp();
		void setGameObject2Point();
		void setGameObject2Square();	
		void setGameObjectUp(float p1x, float p1y, float p2x, float p2y, float p3x, float p3y, float p4x, float p4y);
		void setDrawPart (bool draw);				// Set draw

		bool getDrawPart();							// Get draw
		int dispBufUpdate();
		int GameObjectInit();						// Initialise the world
        int draw(GraphicsM * pGraphicsModule);		// Draw the world
		void slopes();
		float slop(int i);
		Point2D pointOnLine(int index);
		Point2D  GameObjectPoint(int index);
};
#endif /* _GameObject_H */
