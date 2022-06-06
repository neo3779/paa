#ifndef _PARTICLESYSTEM_H
#define _PARTICLESYSTEM_H

#include	<windows.h>
#include	<math.h>
#include	"gameObject.h"
#include	"random.h"

class ParticleSystem
	{
	private:

		static const int np = 50;
		
		GameObject particles[np];
		Random rnd;
		bool drawPart;
		bool explod;
		int swarmBound;
		int swarmSight;

	
	public:
		GameObject mainParticle;
		
		// Constructors and destructor
		ParticleSystem();
		~ParticleSystem();
		void	setPosition(float x,float y);
		void	swarmMove(float timeStep);
		void	explosionMove(float timeStep,GraphicsM * pGraphicsModule);
		void	particleSystemCleanUp();					// Release objects, if applicable
		int		particleSystemInit();						// Initialise the world
		int		draw(GraphicsM * pGraphicsModule);			// Draw the world
		void	setExplod(bool ex);
		bool	getExplod();
		void	viewAllPart();

	private:

		float	randomFloat();
		float	getFloatForXorY();
		void	switchDirtection(int index);
		void	patrolBoss();

	};

#endif /* _PARTICLESYSTEM_H */
