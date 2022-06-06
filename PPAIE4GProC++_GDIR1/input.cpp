/*
 * File name:		input.cpp
 * Description:		Input-event module
 *
 * Author: 			Claude C. Chibelushi
 * Date:			04/10/04
 *					Modified 19/01/09 by CCC: porting to C++
 *
 */



#include		"input.h"		/* include file for user input module */

		/*----------------------------------------------------------------------------\
		 *                                                                            |
		 *                       INITIALISATION AND CLEAN UP           				  |
		 *                                                                            |
		 *----------------------------------------------------------------------------*/

/*
	Construct and initialise an input module.

	Parameter list
		none

 */
Input::Input()
	{
    /* TO DO: add relevant code */

	}


/*
	Destruct input module

	Parameter list
		none
 */
Input::~Input()
	{
	/* TO DO: add relevant code */

	return;			
	}

		/*----------------------------------------------------------------------------\
		 *                                                                            |
		 *                       KEYBOARD INPUT POLLING		           				  |
		 *                                                                            |
		 *----------------------------------------------------------------------------*/


/*
	Check for keyboard event.

	Parameter list
		hWnd:			handle of window

	Returns		
		event:			code for keyboard event
 */


keyEvent Input::checkUserInput(HWND hWnd)
	{
	keyEvent		event;
   

   /* Terminate if user has pressed the Esc key */

	if ( IS_KEY_DOWN(VK_ESCAPE) )
		{
		event = QUIT;

		// Request window destruction if user has pressed the Esc key 
		PostMessage(hWnd, WM_DESTROY, 0, 0);
		}
	else if ( IS_KEY_DOWN(VK_UP) )
		event = UP;
	else if ( IS_KEY_DOWN(VK_DOWN) )
		event = DOWN;
	else if ( IS_KEY_DOWN(VK_LEFT) )
		event = LEFT;
	else if ( IS_KEY_DOWN(VK_RIGHT) )
		event = RIGHT;
	else 
		event = QUIET;

	return event;
	}

