#include		"friction.h"

Friction::Friction()
{
	frictionInit();
}

Friction::~Friction()
{
	/* TO DO: add relevant code */

	frictionCleanUp();

	return;			
}

int Friction::frictionInit()
{
	fric = 0.0F;
	return 1;
}

void Friction::frictionCleanUp()
{
	/* TO DO: add relevant code */

	return;			
}

void Friction::setFriction(float f)
{
	fric = f;
}

float Friction::getFriction()
{
	return fric;
}