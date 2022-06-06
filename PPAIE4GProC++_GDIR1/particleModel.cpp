#include	"particleModel.h"

const float ParticleModel::gravity = 9.81F;

ParticleModel::ParticleModel()
{
	particleModelInit();
}

ParticleModel::~ParticleModel()
{
	/* TO DO: add relevant code */

	particleModelCleanUp();

	return;			
}

int ParticleModel::particleModelInit()
{
	pos.x = 0.0F; pos.y = 0.0F;
	vel.x = 0.0F; vel.y = 0.0F;
	acc.x = 0.0F; acc.y = 0.0F + gravity;
	foc.x = 0.0F; foc.y = 0.0F;
	initVel.x = 0.0F; initVel.y = 0.0F;
	angle = 0.0F;
	mas = 0.0F;
	apg = true;
	return 1;
}

void ParticleModel::particleModelCleanUp()
{
	/* TO DO: add relevant code */

	return;			
}

void ParticleModel::setPosition(float xPos, float yPos)
{
     // position of particle
    pos.x = xPos; pos.y = yPos;
}

void ParticleModel::setInitVelocity(float xVel, float yVel)
{
     // position of particle
    vel.x = xVel; vel.y = yVel;
}

void ParticleModel::setVelocity(float xVel, float yVel)
{
     // position of particle
    vel.x = xVel; vel.y = yVel;
}

void ParticleModel::setAcceleration(float xAcc, float yAcc)
{
     // position of particle
    acc.x = xAcc; acc.y = yAcc + gravity;
}

void ParticleModel::setForce(float xFoc, float yFoc)
{
     // position of particle
    foc.x = xFoc; foc.y = yFoc;
}

void ParticleModel::setMass(float m)
{
     // position of particle
	mas = m;
}

void ParticleModel::setApg(bool vApg)
{
	// apply gravity
	apg = vApg;
}

void ParticleModel::setAngle(float a)
{
	// apply gravity
	angle = a;
}

float ParticleModel::getAngle()
{
	return angle;
}

bool ParticleModel::getApg()
{
	return apg;
}

Point2D ParticleModel::getPosition()
{
	return pos;
}

Point2D ParticleModel::getVelocity()
{
	return vel;
}

Point2D ParticleModel::getInitVelocity()
{
	return initVel;
}

Point2D ParticleModel::getAcceleration()
{
	return acc;
}

Point2D ParticleModel::getForce()
{
	return foc;
}

float ParticleModel::getMass()
{
	return mas;
}

int ParticleModel::move(float timeStep)
{
	float halfTsquard = 0;
	
	halfTsquard = timeStep * timeStep / 2;

	//X

	acc.x = foc.x/mas;

	pos.x += vel.x * timeStep + acc.x * halfTsquard;
	
	vel.x += acc.x * timeStep;


	//Y
	
	acc.y = foc.y/mas;
	
	if(apg)
	{
		acc.y = acc.y + gravity;
	}

	pos.y += vel.y * timeStep + acc.y * halfTsquard;
	
	vel.y += acc.y * timeStep;
	
	
	return 1;
}

int ParticleModel::projectileMotion()
{

	vel.x += initVel.x * (cos(angle));

	vel.y += initVel.y * (sin(angle));

	return 1;
}

