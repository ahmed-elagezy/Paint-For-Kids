#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_COLOR, //v2 Color Selector mode
	MODE_SIZE
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_SQUR,		//Square item in menu
	ITM_TRIG,		//Triangle item in menu
	ITM_HEXA,       //Hexagon item in menu
	ITM_CIRC,		//Circle item in menu
	ITM_RCTA,		//Rect item in menu
	ITM_SELEC,      //Select item in menu
	ITM_DELE,       //Delet item in menu
	ITM_CHNG_DRAW_CLR,
	ITM_CHNG_FILL_CLR,
	ITM_CHNG_BKGRND_CLR,
	ITM_RESIZE,
	//TODO: Add more items names here
	ITM_SEND_BACK, //Send a figure to the back of all figures
	ITM_SEND_FRONT, //Send a figure to the front of all figures
	ITM_SAVE,       //Save item in menu
	ITM_LOAD,
	ITM_TO_PLAY,
	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	ITM_BY_TYPE,	//Play and hide by type item in menu
	ITM_BY_COLOR,	//Play and hide by color item in menu
	ITM_BY_BOTH,	//Play and hide by both color and type item in menu
	ITM_TO_DRAW,	// RETURN To draw mode item in menu

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum ColorMenuItem //The items of the Color menu (you should add more items)
{
	ITM_RED,		//Red color item in menu
	ITM_GREEN,		//Green color item in menu
	ITM_BLUE,		//Blue color item in menu
	ITM_PINK,		//Pink color item in menu
	ITM_MAROON,		//Maroon color item in menu
	ITM_PURPLE,		//Purple color item in menu

	COLOR_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum SizeMenuItem // The items of size
{
	ITM_BACK,
	ITM_QUARTER,
	ITM_HALF,
	ITM_DOUBLE,
	ITM_QUADRUPLE,
	SIZE_ITM_COUNT
};




__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	//Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	bool isFilled;
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif