
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "ActionResize.h"
#include <iostream>

ActionResize::ActionResize(ApplicationManager* pApp) :Action(pApp)
{}

void ActionResize::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("");

	if (pManager->AnySelected())
	{

		ActionType pAct;
		do {

			pGUI->CreateSizeBar();

			pAct = pGUI->MapInputToActionType();
			pGUI->PrintMessage("");

			switch (pAct) {
			case HALF:
				/*cout << pAct;*/
				pManager->Resize_figure(pGUI, 0.5);
				pManager->UpdateInterface();
				break;
			case QUARTER:
				pManager->Resize_figure(pGUI, 0.25);
				pManager->UpdateInterface();
				break;
			case DOUBLE1:
				pManager->Resize_figure(pGUI, 2);
				pManager->UpdateInterface();
				break;
			case QUADRUPLE:
				pManager->Resize_figure(pGUI, 4);
				pManager->UpdateInterface();
				break;
			case BACK:
				UI.InterfaceMode = MODE_DRAW;
				pGUI->CreateDrawToolBar();
				pGUI->PrintMessage("");
				break;
			}
		} while (pAct != BACK);


	}//pGUI->CreateDrawToolBar();

	else
	{
		pGUI->PrintMessage("there isn't a selected figure..");
		//Sleep(1000);
	}
}



