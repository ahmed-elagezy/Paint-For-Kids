﻿#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "Actions\ActionAddTriangle.h"
#include "Actions\ActionAddHexagon.h"
#include "Actions\ActionAddCircle.h"
#include "Actions/ActionAddRectangle.h"
#include "Actions/ActionSelectShape.h"
#include "Actions/ActionDeleteShape.h"
#include "Actions/ActionChngDrawClr.h" 
#include "Actions/ActionChngFillClr.h" 
#include "Actions/ActionChngBkGrndClr.h"
#include "Actions/ActionResize.h"
#include "Actions/SendBack.h"
#include "Actions/BringFront.h"
#include "Actions/ActionSave.h"
#include "Actions/ActionLoad.h"
#include "Actions/ToPlayMode.h"
#include "Actions/PickByType.h"
#include "Actions/pickByBoth.h"
#include "Actions/BackToDraw.h"
#include"Actions/PickByColor.h"
#include <vector>
#include "iostream"
#include "fstream"
#include <string>


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;	
	
	flag = 0;
	//Create an array of figure pointers and set them to NULL		
	//for(int i=0; i<MaxFigCount; i++)
		//FigList[i] = NULL;	
}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{		
		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType);
		
		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();

	}while(ActType != EXIT);
	
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;
		case DRAW_TRIANGLE:
			newAct = new ActionAddTriangle(this);
			break;

		case DRAW_HEXAGON:
			newAct = new ActionAddHexagon(this);
			break;

		case DRAW_CIRCLE:
			newAct = new ActionAddCircle(this);
			break;

		case DRAW_RECTANGLE:
			newAct = new ActionAddRectangle(this);
			break;

		case SELEC_SHAPE:
			newAct = new ActionSelectShape(this);
			break;

		case DELETE_SHAPE:
			newAct = new ActionDeleteShape(this);
			break;

		case CHNG_DRAW_CLR:
			newAct = new ActionChngDrawClr(this);
			break;

		case CHNG_FILL_CLR:
			newAct = new ActionChngFillClr(this);
			break;

		case CHNG_BK_CLR:
			newAct = new ActionChngBkGrndClr(this);
			break; //حسبي الله فين البريك!

		case RESIZE:
			newAct = new ActionResize(this);
			break;

		case SEND_BACK:
			newAct = new SendBack(this);
			break;

		case BRNG_FRONT:
			newAct = new BringFront(this);
			break;

		case SAVE:
			newAct = new ActionSave(this);
			break;

		case LOAD:
			newAct = new ActionLoad(this);
			break;

		case TO_PLAY:
			newAct = new ToPlayMode(this);
			break;
		
		case P_BY_TYPE:
			newAct = new PickByType(this);
			break;

		case P_BY_COLOR:  
			newAct = new PickByColor(this);
			break;

		case P_BY_BOTH:
			newAct = new PickByBoth(this);
			break;

		case TO_DRAW:
			newAct = new BackToDraw(this);
			break;

		case EXIT:
			///create ExitAction here
			break;

		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;
	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigList.size() < MaxFigCount )
		FigList.push_back(pFig);	
}
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::GetIndex(CFigure* c) 
{
	for (int i = 0; i < FigList.size(); i++) {
		if (FigList[i] == c) {
			return i;
		}
	}
	return -1;
}



CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = FigList.size() - 1; i >= 0; i--)
	{
		if (FigList[i]->BelongTo(x, y))
		{
			return FigList[i];
		}
	}
	return NULL;
}

void ApplicationManager::DeleteShape() {
	for (int i = FigList.size() - 1; i >= 0; i--) {
		if (FigList[i]->IsSelected()) {
			FigList.erase(FigList.begin() + i);
				break;
		}
	}
}

// Return index of selected figure
int ApplicationManager::getSelectedFigure()
{
	for (int i = 0; i < FigList.size(); i++)
		if (FigList[i]->IsSelected())
			return i;
	return -1;
}


void ApplicationManager::changeDrawColor(color drawClr)
{
	for (int i = 0; i < FigList.size(); i++)
	{
		if (FigList[i]->IsSelected())
		{
			FigList[i]->ChngDrawClr(drawClr);
		}
	}
}
//////
void ApplicationManager::changeFillColor(color FillClr)
{
	for (int i = 0; i < FigList.size(); i++)
	{
		if (FigList[i]->IsSelected())
		{
			FigList[i]->ChngFillClr(FillClr);
		}
	}
}


void ApplicationManager::unselectAll()
{
	for (int i = 0; i < FigList.size(); i++)
	{
		FigList[i]->SetSelected(false);
	}
}

void ApplicationManager::Resize_figure(GUI* pGUI, float size) const {
	for (int i = 0; i < FigList.size(); i++)
	{
		if (FigList[i]->IsSelected())
		{
			FigList[i]->Resize(pGUI, size);
		}
	}
}

int ApplicationManager::getFigCount()const {
	return FigList.size();
}

CFigure* ApplicationManager::getAnyFigure()
{
	if (FigList.size())
	{
		srand(time(NULL));
		return FigList[rand() % FigList.size()];
	}
	return nullptr;
}

bool ApplicationManager::hasDifferentColors() {
	for (int i = 0; i < FigList.size() - 1; i++) {
		if (FigList[i]->GetFillClr() != FigList[i + 1]->GetFillClr())
			return true;
	}
	return false;
}

CFigure* ApplicationManager::getFigList(int i) const
{
	return FigList[i];
}

bool ApplicationManager::AnySelected()
{
	for (int i = 0; i < FigList.size(); i++)
	{
		if (FigList[i]->IsSelected())
		{
			return true;
		}
	}
	return false;
}
bool ApplicationManager::GetColor(color& inputColor) 
{

	bool isColor = true;
	//Creating the color toolbar
	pGUI->CreateColorToolBar();
	//Inputting draw color action
	ActionType inputColorAction = pGUI->MapInputToActionType();

	switch (inputColorAction) {

	case SET_RED:
		inputColor = RED;
		break;

	case SET_GREEN:
		inputColor = GREEN;
		break;

	case SET_BLUE:
		inputColor = BLUE;
		break;

	case SET_PINK:
		inputColor = PINK;
		break;

	case SET_MAROON:
		inputColor = MAROON;
		break;

	case SET_PURPLE:
		inputColor = PURPLE;
		break;

	default:
		isColor = false;
	}

	//Restoring the draw toolbar
	pGUI->CreateDrawToolBar();

	return isColor;
}


string ApplicationManager::getRandomFigure(int& count)
{
	string figureName;
	int rondom;
	count = 0;

	if (FigList.size() != 0)
	{
		if (FigList.size() != 1)
		{
			rondom = rand() % (FigList.size());
			figureName = FigList[rondom]->getFigureName();
			for (int i = 0; i < FigList.size(); i++)
			{
				if (FigList[rondom]->getFigureName() == FigList[i]->getFigureName())
				{
					count++;
				}

			}
		}
		else
		{
			return FigList[0]->getFigureName();
			count = 1;
		}

		return figureName;

	}
	else
	{
		return "empty";
	}

}////////////////////////////////////////////////////////////

void ApplicationManager::showAllFigure()
{
	for (int i = 0; i < FigList.size(); i++)
	{
		FigList[i]->show(true);
	}
}


//////
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
//void ApplicationManager::UpdateInterface() const
//{
//	pGUI->ClearDrawArea();
//	for (int i = 0; i < FigList.size(); i++)
//		
//	{
//		FigList[i]->DrawMe(pGUI); 	//Call Draw function (virtual member fn)
//	}	
//
//}


void ApplicationManager::UpdateInterface() const
{
	pGUI->ClearDrawArea();
	for (int i = 0; i < FigList.size(); i++) {
		if (!FigList[i]->getHiddenValue())
		{
			FigList[i]->DrawMe(pGUI);
		}
	}
	if (UI.InterfaceMode == MODE_DRAW)
		pGUI->CreateDrawToolBar();
	else if (UI.InterfaceMode == MODE_PLAY)
		pGUI->CreatePlayToolBar();
	else if (UI.InterfaceMode == MODE_COLOR)
		pGUI->CreateColorToolBar();
	else if (UI.InterfaceMode == MODE_SIZE)
		pGUI->CreateSizeBar();
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigList.size(); i++)
		delete FigList[i];
	delete pGUI;	
}

//==================================================================================//
//							     Save   							            	//
//==================================================================================//

void ApplicationManager::saveAll(ofstream& savedFile) {

	if (savedFile.is_open())
	{
		savedFile << to_string(FigList.size()) << "\n"; //Write number of figures in the file

		for (int i = 0; i < FigList.size(); i++)
			FigList[i]->Save(savedFile);
	}
}

void ApplicationManager::clearFigList() {
	for (int i = 0; i < FigList.size(); i++)
		FigList[i] = NULL;
	FigCount = 0;
}

//==================================================================================//
//						      	Send To Back									    //
//==================================================================================//

void ApplicationManager::SendToBack(int selectedIndex)
{
	if (selectedIndex != 0)
	{
		CFigure* tmp = FigList[0];//Back Figure
		FigList[0] = FigList[selectedIndex];//Swap Back Figure with our selected figure
		FigList[selectedIndex] = tmp;
	}
}

//==================================================================================//
//							Bring To Front											//
//==================================================================================//

void ApplicationManager::BringToFront(int selectedIndex)
{
	if (selectedIndex != FigList.size() - 1)
	{
		CFigure* tmp = FigList[FigList.size() - 1];//Front Figure
		FigList[FigList.size() - 1] = FigList[selectedIndex];//Swap Front Figure with our selected figure
		FigList[selectedIndex] = tmp;
	}
}