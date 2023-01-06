#include "GUI.h"

//constructor make necessary initializations
GUI::GUI()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("HAMBOLA");
	
	CreateDrawToolBar();
	CreateStatusBar();
	
}


//======================================================================================//
//								Input Functions										    //
//======================================================================================//


void GUI::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if(Key == 8 )	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label+= Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType GUI::MapInputToActionType() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SQUR: return DRAW_SQUARE;
			case ITM_TRIG: return DRAW_TRIANGLE;
			case ITM_HEXA: return DRAW_HEXAGON;
			case ITM_CIRC: return DRAW_CIRCLE;
			case ITM_RCTA: return DRAW_RECTANGLE;
			case ITM_SELEC: return SELEC_SHAPE; 
			case ITM_DELE: return DELETE_SHAPE;
			case ITM_RESIZE: return RESIZE;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD:return LOAD;
			case ITM_CHNG_DRAW_CLR:return CHNG_DRAW_CLR;
			case ITM_CHNG_FILL_CLR:return CHNG_FILL_CLR;
			case ITM_CHNG_BKGRND_CLR:return CHNG_BK_CLR;

			case ITM_EXIT: return EXIT;	
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		

		//[2] User clicks on the drawing area
		if ( x >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_COLOR) {

		if (y >= 0 && y < UI.ToolBarHeight)
		{

			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RED: return SET_RED;
			case ITM_GREEN: return SET_GREEN;
			case ITM_BLUE: return SET_BLUE;
			case ITM_PINK: return SET_PINK;
			case ITM_MAROON: return SET_MAROON;
			case ITM_PURPLE:  return SET_PURPLE;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

	}
	else if (UI.InterfaceMode == MODE_SIZE)
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItemOrder)
			{
			case ITM_BACK:  return BACK;
			case ITM_QUARTER: return QUARTER;
			case ITM_HALF: return HALF;
			case ITM_DOUBLE:   return DOUBLE1;
			case ITM_QUADRUPLE: return QUADRUPLE;
			default: return EMPTY;
			}
		}
	}
	else 	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return TO_PLAY;	//just for now. This should be updated
	}	

}
//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white Square
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SQUR] = "images\\MenuItems\\Menu_Sqr.jpg";
	MenuItemImages[ITM_TRIG] = "images\\MenuItems\\Menu_Trig.jpg";
	MenuItemImages[ITM_HEXA] = "images\\MenuItems\\Menu_Hexa.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Elps.jpg";
	MenuItemImages[ITM_RCTA] = "images\\MenuItems\\Menu_Rectangle.jpg";
	MenuItemImages[ITM_SELEC] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_DELE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Resize.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpeg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_CHNG_DRAW_CLR] = "images\\MenuItems\\iucon.jpg";
	MenuItemImages[ITM_CHNG_FILL_CLR] = "images\\MenuItems\\fillc.jpg";
	MenuItemImages[ITM_CHNG_BKGRND_CLR] = "images\\MenuItems\\download (1).jpg";	
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateToolBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

void GUI::CreateColorToolBar() const 
{
	CreateToolBar();
	UI.InterfaceMode = MODE_COLOR;

	string ColorMenuItems[COLOR_ITM_COUNT];

	ColorMenuItems[ITM_RED] = "images\\MenuItems\\Menu_Red.jpg";
	ColorMenuItems[ITM_GREEN] = "images\\MenuItems\\Menu_Green.jpg";
	ColorMenuItems[ITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";
	ColorMenuItems[ITM_PINK] = "images\\MenuItems\\Menu_Pink.jpg";
	ColorMenuItems[ITM_MAROON] = "images\\MenuItems\\Menu_Maroon.jpg";
	ColorMenuItems[ITM_PURPLE] = "images\\MenuItems\\Menu_Purple.jpg";


	//Draw menu item one image at a time
	for (int i = 0; i < COLOR_ITM_COUNT; i++)
		pWind->DrawImage(ColorMenuItems[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}


void GUI::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);	
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}
//v2***********************************************
bool GUI::getIsFilled() const {
	return UI.isFilled;
}

void GUI::setCrntDrawColor(color c) {
	UI.DrawColor = c;
}

void GUI::setCrntFillColor(color c) {
	UI.FillColor = c;
}

void GUI::setIsFilled(bool isF) {
	UI.isFilled = isF;
}
//****v3.1*** maslooh
void GUI::setLastPointClicked(int x, int y)
{
	lastPointClicked.x = x;
	lastPointClicked.y = y;
}
//****v3.1*** maslooh
Point GUI::getLastPointClicked()
{
	return lastPointClicked;
}

void GUI::setCrntBKGrandColor(color c) {
	UI.BkGrndColor = c;
}
//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void GUI::DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width
	
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P1.x +length, P1.y+length, style);
	//pWind->DrawLine(P1.x, P1.y, P1.x + length, P1.y + length, style);
}
void GUI::DrawTriangle(Point P1, Point P2,Point P3,GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	//pWind->DrawLine(P1.x, P1.y, P1.x + length, P1.y + length, style);
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

void GUI::DrawHexagon(Point P1, int length, int Height, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	int x[] = { P1.x, P1.x + length, P1.x + 1.5 * length, P1.x + length, P1.x, P1.x - 0.5 * length };
	int y[] = { P1.y, P1.y, P1.y + 0.5 * Height, P1.y + Height, P1.y + Height, P1.y + 0.5 * Height };

	pWind->DrawPolygon(x, y, 6, style);
	//pWind->DrawLine(P1.x, P1.y, P1.x + length, P1.y + length, style);
}

void GUI::DrawCircle(Point P1, int  Radius, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y,Radius, style);
	//pWind->DrawLine(P1.x, P1.y, P1.x + length, P1.y + length, style);
}

void GUI::DrawRectangle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void GUI::CreateSizeBar() const
{
	CreateToolBar();
	UI.InterfaceMode = MODE_SIZE;

	string MenuItemImages[SIZE_ITM_COUNT];

	MenuItemImages[ITM_BACK] = "images\\MenuItems\\Menu_Back_2.jpg";
	MenuItemImages[ITM_QUARTER] = "images\\MenuItems\\2.jpg";
	MenuItemImages[ITM_HALF] = "images\\MenuItems\\1.jpg";
	MenuItemImages[ITM_DOUBLE] = "images\\MenuItems\\3.jpg";
	MenuItemImages[ITM_QUADRUPLE] = "images\\MenuItems\\4.jpg";


	///TODO: write code to create Size mode menu
	for (int i = 0; i < SIZE_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

