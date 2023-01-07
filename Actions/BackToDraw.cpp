#include "BackToDraw.h"
#include"../ApplicationManager.h"
#include "../GUI/GUI.h"
BackToDraw::BackToDraw(ApplicationManager* pApp) :Action(pApp) {}

void BackToDraw::Execute() {
	GUI* pGUI = pManager->GetGUI();
	pGUI->CreateDrawToolBar();
	pGUI->PrintMessage("Welcome back");
}