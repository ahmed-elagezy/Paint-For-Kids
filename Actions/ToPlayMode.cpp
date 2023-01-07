#include "ToPlayMode.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
ToPlayMode::ToPlayMode(ApplicationManager* pApp) :Action(pApp)
{}

void ToPlayMode::Execute() {
	//Get a Pointer to the Output Interface
	GUI* pGUI = pManager->GetGUI();

	pManager->unselectAll();
	pGUI->CreatePlayToolBar();
	pGUI->PrintMessage("You switched to Play Mode! Let's Play!");
}
