#include "BringFront.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include <iostream>

BringFront::BringFront(ApplicationManager* pApp) :Action(pApp) {}

void BringFront::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	int selectedIndex = pManager->getSelectedFigure();
	if (selectedIndex != -1) {
		pManager->BringToFront(selectedIndex);
		pGUI->ClearDrawArea();
	}
	else {
		pGUI->PrintMessage("Select a Figure First!");
	}
}