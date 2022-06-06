#ifndef _PARTICLEMODEL_H
#define _PARTICLEMODEL_H

#include	<windows.h>
#include	<math.h>
#include	"dataTypes.h"		/* include file for graphics module */

class ParticleModel
	{
		private:

		static const float gravity;

		// Dynamics parameters (for physics simulation) 
		Point2D 	pos;				// position of particle used as physics model of game object
		Point2D		vel;				// velocity
		Point2D		acc;				// acceleration 
		Point2D		foc;				// force
		Point2D		initVel;			// intial velocity
		float		angle;
		float		mas;				// mass
		bool		apg;				// apply gravity
		

		public:

		// Constructors and destructor
		ParticleModel();
		~ParticleModel();

		int particleModelInit();						// Initialise the world
		void particleModelCleanUp();					// Release objects, if applicable

		void setPosition(float xCoord, float yCoord);   // Set world position of game object
		void setVelocity(float xVel, float yVel);		// Set the velocity for the object
		void setInitVelocity(float xVel, float yVel);	// Set the intial velocity for the object
		void setAcceleration(float xAcc, float yAcc);	// Set the accelreation of the object
		void setForce(float xAcc, float yAcc);			// Set the force applied to the object
		void setAngle(float a);
		void setMass(float m);							// Set the mass of the objects
		void setApg(bool vApg);							// Set apply gravity
	
		Point2D getPosition();							// Get position of game object
		Point2D getVelocity();							// Get the velocity of the game object
		Point2D getInitVelocity();						// Get the intial velocity of the game object
		Point2D getAcceleration();						// Get acceleration of the object
		Point2D getForce();								// Get the force applied to the object
		float	getAngle();
		bool	getApg();								// Get apply gravity
		float	getMass();								// Get the mass of the object
		int projectileMotion();
		int move(float timeStep);						// Move the object
	};

#endif /* _PARTICLEMODEL_H */