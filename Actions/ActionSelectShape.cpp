#include "ActionSelectShape.h"
#include "..\ApplicationManager.h"
#include <Windows.h>
#include "..\GUI\GUI.h"
#include <string>
#include <string.h>
#include <iostream>

ActionSelectShape::ActionSelectShape(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionSelectShape::Execute()
{
	Point P;
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	//Point drawAreaPoint = pGUI->getLastPointClicked();
	//getting a pointer to a selected figure
	pGUI->PrintMessage("Select a shape");
	pGUI->GetPointClicked(P.x, P.y);



	CFigure* selectedFig = pManager->GetFigure(P.x, P.y);

	if (selectedFig)//check if the pointer is not null
	{
		if (selectedFig->IsSelected())//case if the shape is already selected
		{
			selectedFig->SetSelected(false);
			pGUI->ClearStatusBar();
		}
		else
		{
			selectedFig->SetSelected(true);
			selectedFig->PrintInfo(pGUI, pManager->GetIndex(selectedFig));
			//Sleep(1000);

		}
	}
}