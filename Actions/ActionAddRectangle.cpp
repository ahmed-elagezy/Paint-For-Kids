#include "ActionAddRectangle.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddRectangle::ActionAddRectangle(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddRectangle::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

	pGUI->PrintMessage("New Rectangle: Click at first point");
	//Step 1 - Read Rectangle data from the user
	pGUI->GetPointClicked(P1.x, P1.y);

	if (P1.y < UI.StatusBarHeight || P1.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = false; //false as long as the click is in wrong place
		pGUI->PrintMessage("Please, Choose a valid Point");
		while (!flag)
		{
			pGUI->GetPointClicked(P1.x, P1.y); //Get Pasting Point
			if (!(P1.y < UI.StatusBarHeight || P1.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}
	}
	pGUI->GetPointClicked(P1.x, P1.y);


	pGUI->PrintMessage("New Rectangle: Click at second point");

	//Read 1st point and store in point P1

	pGUI->GetPointClicked(P2.x, P2.y);

	if (P2.y < UI.StatusBarHeight || P2.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = false; //false as long as the click is in wrong place
		pGUI->PrintMessage("Please, Choose a valid Point");
		while (!flag)
		{
			pGUI->GetPointClicked(P2.x, P2.y); //Get Pasting Point
			if (!(P2.y < UI.StatusBarHeight || P2.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}
	}

	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();


	/*//Step 2 - prepare Rectangle data
	//User has entered two points P1&P2
	//2.1- Identify upperleft point(point1) of the Rectangle
	Point topLeft;
	topLeft.x = P1.x < P2.x ? P1.x : P2.x;
	topLeft.y = P1.y < P2.y ? P1.y : P2.y;*/

	/*//2.2- Calcuate square side legnth
	//The square side length would be the longer distance between the two points coordinates
	int SideLength = max(abs(P1.x - P2.x), abs(P1.y - P2.y));*/


	
	//Step 3 - Create a Square with the parameters read from the user
	/*if (P1.y <= UI.ToolBarHeight || P2.y <= UI.ToolBarHeight)
	{
		pGUI->PrintMessage("out drow area  ");
	}*/
	CRectangle* R1 = new CRectangle(P1, P2, SqrGfxInfo);

	//Step 4 - Add the Rectangle to the list of figures
	pManager->AddFigure(R1);
}
