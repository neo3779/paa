#include	"particleSystem.h"
#include	<GDIPLUS.H>


ParticleSystem::ParticleSystem()
{
	/* TO DO: add relevant code */
}

bool ParticleSystem:: getExplod ()
{
	return explod;
}

void ParticleSystem:: setExplod (bool ex)
{
	explod = ex;
}

int ParticleSystem::particleSystemInit()
{
	swarmBound = 25;
	explod = false;

	mainParticle.GameObjectInit();
	mainParticle.setGameObject2Point();
	mainParticle.particle()->setPosition(10.0F,10.0F);
	mainParticle.particle()->setForce(0.0F,0.0F);
	mainParticle.particle()->setMass(1.0F);
	mainParticle.particle()->setApg(false);
	mainParticle.setDrawPart(false);

	for (int i = 0; i < np; i++)
	{
		particles[i].GameObjectInit();
		particles[i].setGameObject2Point();
		particles[i].particle()->setPosition(mainParticle.particle()->getPosition().x,mainParticle.particle()->getPosition().y);
		particles[i].particle()->setForce(getFloatForXorY(),getFloatForXorY());
		particles[i].particle()->setMass(1.0F);
		particles[i].particle()->setApg(false);
		particles[i].setDrawPart(false);
	}

	return 1;
}

ParticleSystem::~ParticleSystem()
{
	/* TO DO: add relevant code */
	particleSystemCleanUp();
}

void ParticleSystem::particleSystemCleanUp()
{
	/* TO DO: add relevant code */
	return;			
}

float ParticleSystem::getFloatForXorY()
{
	float num;
	
	if(rnd.getInt(2) == 1)
		num = rnd.getFloat()* -1; 
	else
		num = rnd.getFloat();

	return num;
}

int ParticleSystem::draw(GraphicsM * pGraphicsModule)
{
	mainParticle.draw(pGraphicsModule);

	for (int i = 0; i < np; i++)
	{
		particles[i].draw(pGraphicsModule);
	}
	return 1;
}

void ParticleSystem::swarmMove(float timeStep)
{
	patrolBoss();

	for (int i = 0; i < np; i++)
	{

		if((particles[i].particle()->getPosition().x < mainParticle.particle()->getPosition().x - swarmBound) && (particles[i].particle()->getVelocity().x < 0))
		{
			switchDirtection(i);		
		}

		if((particles[i].particle()->getPosition().x > mainParticle.particle()->getPosition().x + swarmBound)&& (particles[i].particle()->getVelocity().x > 0))
		{
			switchDirtection(i);
		}

		if((particles[i].particle()->getPosition().y < mainParticle.particle()->getPosition().y - swarmBound) && (particles[i].particle()->getVelocity().y < 0))
		{
			switchDirtection(i);		
		}

		if((particles[i].particle()->getPosition().y > mainParticle.particle()->getPosition().y + swarmBound)&& (particles[i].particle()->getVelocity().y > 0))
		{
			switchDirtection(i);
		}

		mainParticle.particle()->move(timeStep);
		particles[i].particle()->move(timeStep);
	}
}

void ParticleSystem::switchDirtection(int index)
{
	particles[index].particle()->setVelocity(particles[index].particle()->getVelocity().x * -1,particles[index].particle()->getVelocity().y * -1 );
	particles[index].particle()->setAcceleration(particles[index].particle()->getAcceleration().x * -1,particles[index].particle()->getAcceleration().y * -1);
	particles[index].particle()->setForce(particles[index].particle()->getForce().x * -1,particles[index].particle()->getForce().y * -1);
	particles[index].particle()->setPosition(mainParticle.particle()->getPosition().x,mainParticle.particle()->getPosition().y);
	particles[index].particle()->setVelocity(0.0F,0.0F);
	particles[index].particle()->setAcceleration(0.0F,0.0F);			
}

void ParticleSystem::patrolBoss()
{
	if(mainParticle.particle()->getPosition().x > 984.0F && mainParticle.particle()->getPosition().y >= 50.0F)
	{
		mainParticle.particle()->setPosition(983.0F,50.0F);
		mainParticle.particle()->setVelocity(0.0F,0.0F);
		mainParticle.particle()->setAcceleration(0.0F,0.0F);
		mainParticle.particle()->setForce(0.0F,0.001F);
	}

	if(mainParticle.particle()->getPosition().x >= 983.0F && mainParticle.particle()->getPosition().y > 400.0F)
	{
		mainParticle.particle()->setPosition(983.0F,400.0F);
		mainParticle.particle()->setVelocity(0.0F,0.0F);
		mainParticle.particle()->setAcceleration(0.0F,0.0F);
		mainParticle.particle()->setForce(-0.0001F,0.0F);
	}

	if(mainParticle.particle()->getPosition().x < 50.0F && mainParticle.particle()->getPosition().y >= 400.0F)
	{
		mainParticle.particle()->setPosition(50.0F,400.0F);
		mainParticle.particle()->setVelocity(0.0F,0.0F);
		mainParticle.particle()->setAcceleration(0.0F,0.0F);
		mainParticle.particle()->setForce(0.0F,-0.0001F);
	}

	if(mainParticle.particle()->getPosition().x <= 50.0F && mainParticle.particle()->getPosition().y < 50.0F)
	{
		mainParticle.particle()->setPosition(50.0F,50.0F);
		mainParticle.particle()->setVelocity(0.0F,0.0F);
		mainParticle.particle()->setAcceleration(0.0F,0.0F);
		mainParticle.particle()->setForce(0.0001F,0.0F);
	}
}

void ParticleSystem::explosionMove(float timeStep,GraphicsM * pGraphicsModule)
{	
	if(explod)
	{
		for (int i = 0; i < np; i++)
		{
			float x = 0, y = 0,res = 0;
			x = mainParticle.particle()->getPosition().x - particles[i].particle()->getPosition().x;
			y = mainParticle.particle()->getPosition().y - particles[i].particle()->getPosition().y;

			x = x * x;
			y = y * y;
			res = sqrt (x+y);

			if (res > 100)
			{
				particles[i].setDrawPart(false);
				particles[i].particle()->setAcceleration(0.0F,0.0F);
				particles[i].particle()->setPosition(0.0F,0.0F);
				particles[i].particle()->setVelocity(0.0F,0.0F);
			}
			else
			{
				particles[i].setDrawPart(true);
			}	
			
			mainParticle.particle()->move(timeStep);
			particles[i].particle()->move(timeStep);

		}
	}
}

void ParticleSystem::setPosition(float x,float y)
{
	mainParticle.particle()->setPosition(x,y);

	for (int i = 0; i < np; i++)
	{
		particles[i].particle()->setPosition(x,y);
	}
}

void ParticleSystem::viewAllPart()
{
	mainParticle.setDrawPart(true);

	for (int i = 0; i < np; i++)
	{
		particles[i].setDrawPart(true);
	}
}