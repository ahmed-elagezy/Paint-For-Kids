#include "ActionDeleteShape.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"


ActionDeleteShape::ActionDeleteShape(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionDeleteShape::Execute()
{
	GUI* pGUI = pManager->GetGUI();

	pManager->DeleteShape();
	pGUI->ClearDrawArea();
	pGUI->ClearStatusBar();


}