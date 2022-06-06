#include "random.h"

Random::Random()
{
	/* TO DO: add relevant code */
}


int Random::randomInit()
{
	return 1;
}

Random::~Random()
{
	/* TO DO: add relevant code */

	randomCleanUp();
	
}

void Random::randomCleanUp()
{
	return;
}

float Random::getFloat()
{
	return rand()/(float(RAND_MAX)+1); 
}

int Random::getInt(float max)
{
    return float(max*rand()/(RAND_MAX+1.0));
} 
int Random::getIntBetween(int min, int max)
{
    if (min>max)
    {
        return max+int((min-max+1)*rand()/(RAND_MAX+1.0));
    }
    else
    {
        return min+int((max-min+1)*rand()/(RAND_MAX+1.0));
    }
} 