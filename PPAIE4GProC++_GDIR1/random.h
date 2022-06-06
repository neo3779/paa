#ifndef _RANDOM_H
#define _RANDOM_H

#include	<windows.h>

class Random
	{

		public:

		// Constructors and destructor
		Random();
		~Random();

		int randomInit();				// Initialise the world
		void randomCleanUp();			// Release objects, if applicable

		int getInt(float max);			// Get int
		float getFloat();				// Get float
		int getIntBetween(int min, int max);

	};

#endif /* _RANDOM_H */