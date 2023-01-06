#include "ActionAddCircle.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionAddCircle::ActionAddCircle(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddCircle::Execute()
{
	Point Center;
	Point Edge;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo CirGfxInfo;
	CirGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CirGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	CirGfxInfo.FillClr = pGUI->getCrntFillColor();
	CirGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Square data from the user

	pGUI->PrintMessage("New Circle: Click at Center Point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(Center.x, Center.y);

	if (Center.y < UI.StatusBarHeight || Center.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = false; //false as long as the click is in wrong place
		pGUI->PrintMessage("Please, Choose a valid Point");
		while (!flag)
		{
			pGUI->GetPointClicked(Center.x, Center.y); //Get Pasting Point
			if (!(Center.y < UI.StatusBarHeight || Center.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}
	}



	pGUI->PrintMessage("New Circle: Click at second point to set radius");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(Edge.x, Edge.y);

	if (Edge.y < UI.StatusBarHeight || Edge.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = false; //false as long as the click is in wrong place
		pGUI->PrintMessage("Please, Choose a valid Point");
		while (!flag)
		{
			pGUI->GetPointClicked(Edge.x, Edge.y); //Get Pasting Point
			if (!(Edge.y < UI.StatusBarHeight || Edge.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}
	}

	pGUI->ClearStatusBar();

	/*
	//Step 2 - prepare square data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the square
	Point topLeft;
	topLeft.x = P1.x < P2.x ? P1.x : P2.x;
	topLeft.y = P1.y < P2.y ? P1.y : P2.y;

	//2.2- Calcuate square side legnth
	//The square side length would be the longer distance between the two points coordinates
	int SideLength = max(abs(P1.x - P2.x), abs(P1.y - P2.y));
	*/



	//Step 3 - Create a Square with the parameters read from the user
	CCircle* R = new CCircle(Center, Edge, CirGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(R);
}
