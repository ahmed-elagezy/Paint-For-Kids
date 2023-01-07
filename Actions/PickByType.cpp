
#include "PickByType.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"
#include<iostream>
PickByType::PickByType(ApplicationManager* pApp) :Action(pApp)
{	
	
	rightAns = 0;
	wrongAns = 0;
}

void PickByType::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	int Count = 0; 
	figureName = pManager->getRandomFigure(Count);
	if (figureName != "empty")
	{
		pGUI->PrintMessage("SELECT ALL " + figureName);
		while (Count > 0)
		{ 
			pGUI->GetPointClicked(p.x, p.y);
			CFigure* r = pManager->GetFigure(p.x, p.y);
			if (r != NULL)
			{
				if (r->getFigureName() == figureName)
				{
					rightAns++;
					Count--;
					r->show(false);
				}
				else
				{
					wrongAns++;
				}
				
				pGUI->PrintMessage("Correct Ans = " + to_string(rightAns) + " " + "Wrong Ans = " + to_string(wrongAns) + " ..CONTINUE!");
				pManager->UpdateInterface();
			}
			else
			{
				pGUI->PrintMessage("Correct Ans = " + to_string(rightAns) + " "+ "Wrong Ans = " + to_string(wrongAns) + " Select a Figure Please");
			}
		}

		pGUI->PrintMessage("your grade is " + to_string(rightAns) + "/" + to_string((rightAns + wrongAns)));
		pGUI->ClearDrawArea();
		pGUI->GetPointClicked(p.x, p.y);
		pManager->showAllFigure();

	}
	else
	{
		pGUI->PrintMessage("Empty Drawing Area , Back to draw mode and try again");
		return;
	}

}