/*
 * File name:	graphics.h
 * Description:	This is a header file for graphics.cpp
 *
 *
 * Author: 		Claude C. Chibelushi
 * Date:		04/10/04
 *				Modified 02/10/05, by CCC: all display related functions put in <graphics.c>
 *				Modified 19/01/09 by CCC: porting to C++
 *				Modified 06/02/09 by CCC: implementation of double buffering and additional 
 *                           functionality required for illustrative examples of GDI drawing functionality.
 *				Modified 22/01/10 by CCC: implementation of drawPolygon()
 * 				
 *_________________________________________________________________________*/


#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include	<windows.h>
#include	"dataTypes.h"		/* include file for custom data types */

/* For GDI+ */
#include <gdiplus.h>
using namespace Gdiplus;
//#pragma comment(lib, "gdiplus.lib")


class GraphicsM
	{

	//public static Point2D ViewportOrigin; 
	//public static Point2D ViewportSize; 
	
	private:

		HDC hMdc;					/* handle for device context of back buffer */
		int	backBufWidth;			/* width of back buffer */
		int	backBufHeight;			/* height of back buffer */
		

	public:
	
		RECT viewport;				/* display viewport */

		// Constructor and destructor
		GraphicsM();
		~GraphicsM();
		
		void initMemDC(HWND hWnd);				// Initialise the memory device context (for double buffering)
		int graphicsModuleInit(HWND hWnd);		// Initialise the graphics module
		void graphicsCleanUp();					// Release graphics objects

		int setViewport();						// Set the viewport

		int drawHUD();							// Draw a basic HUD
   		int drawPolygon(Point2D polygon[], int vertexCount, bool closed);	// Draw a polygon
		int displayBackBuffer(HWND hWnd);		// display backBuffer

	};


#endif /* _GRAPHICS_H */

