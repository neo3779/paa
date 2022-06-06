/*
 * File name:		winApp.h
 * Description:		Header file for winApp.cpp
 *					Function prototypes for main-window initialisation, display, and window procedure
 *
 * Author: 			Claude C. Chibelushi
 * Date:			04/10/04
 *					Modified 19/01/09 by CCC: porting to C++
 *					Modified 06/02/09, by CCC: addition of set-up code for GDI+.
 *
 */
 



#ifndef _WINAPP_H
#define _WINAPP_H

#include		<windows.h>   	/* master include file for Windows applications */

/* Set-up code for GDI+ */
#include		<gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "gdiplus.lib")

char szWinName[] = "PPAIEGwindow";		/* name of window class */

LRESULT CALLBACK fnWindowProcedure(HWND, UINT, WPARAM, LPARAM);
void fnDefineWindowClass(WNDCLASSEX * windowClass, HINSTANCE hThisAppInstance);
HWND fnCreateWindow(HINSTANCE hThisAppInstance);
void fnDisplayWindow(HWND hWindowHandle, int nWindowMode);

#endif /* _WINAPP_H */


