#ifndef _FRICTION_H
#define _FRICTION_H

class Friction
	{
		private:
			float fric;

		public:

			// Constructors and destructor
			Friction();
			~Friction();

			int frictionInit();						// Initialise the world
			void frictionCleanUp();					// Release objects, if applicable

			void setFriction(float f);				// Set the friction of the objects

			float getFriction();					// Get friction of game object

	};

#endif /* _FRICTION_H */