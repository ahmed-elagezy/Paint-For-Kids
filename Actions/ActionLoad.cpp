#include "ActionLoad.h"
#include"..\ApplicationManager.h"
#include"..\Figures\CFigure.h"
#include "..\Figures\CSquare.h";
#include "..\Figures\CRectangle.h";
#include "..\Figures\CTriangle.h";
#include "..\Figures\CCircle.h";
#include "..\Figures\CHexagon.h";
#include "..\GUI\GUI.h"
#include<fstream>
#include <iostream>

ActionLoad::ActionLoad(ApplicationManager* pApp) :Action(pApp) {
	fileName = "";
}

void ActionLoad::ReadParameters() {
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Enter file name"); //Read file name
	fileName = pGUI->GetSrting();
}

void ActionLoad::Execute() {
	ifstream loadedFile;
	string drwColor, fillColor, bgColor, shapeName;
	int figCount = 0;
	CFigure* figure;
	ReadParameters();
	GUI* pGUI = pManager->GetGUI();
	if (fileName == "") {
		pGUI->PrintMessage("Not Valid");
	}
	else {
		loadedFile.open("Saved\\" + fileName + ".txt");
		if (loadedFile.fail()) {
			pGUI->PrintMessage("File Not Exist");
		}
		else {
			loadedFile >> drwColor >> fillColor >> bgColor;
			UI.DrawColor = StringColor(drwColor);
			UI.FillColor = StringColor(fillColor);
			UI.BkGrndColor = StringColor(bgColor);

			pManager->clearFigList();
			loadedFile >> figCount;

			while (figCount) {
				loadedFile >> shapeName;
				if (shapeName == "SQUARE") {
					figure = new CSquare;
				}
				else if (shapeName == "RECTANGLE") {
					figure = new CRectangle;
				}
				else if (shapeName == "HEXAGON") {
					figure = new CHexagon;
				}
				else if (shapeName == "TRIANGLE") {
					figure = new CTriangle;
				}
				else if (shapeName == "CIRCLE") {
					figure = new CCircle;
				}
				figure->Load(loadedFile);
				pManager->AddFigure(figure);
				figCount--;
			}
			pManager->UpdateInterface();
			pGUI->ClearStatusBar();
			pGUI->PrintMessage("Shapes loaded Successfully");
		}
	}
}


color ActionLoad::StringColor(string s)const {
	if (s == "BLACK")
		return BLACK;
	if (s == "BLUE")
		return BLUE;
	if (s == "WHITE")
		return WHITE;
	if (s == "RED")
		return RED;
	if (s == "YELLOW")
		return YELLOW;
	if (s == "GREEN")
		return GREEN;
	if (s == "LIGHTGOLDENRODYELLOW")
		return LIGHTGOLDENRODYELLOW;
	if (s == "MAGENTA")
		return MAGENTA;
	if (s == "TURQUOISE")
		return TURQUOISE;
	if (s == "SKYBLUE")
		return SKYBLUE;
	if (s == "LIGHTSTEELBLUE")
		return LIGHTSTEELBLUE;
	if (s == "IVORY")
		return IVORY;
	if (s == "HONEYDEW")
		return HONEYDEW;
	if (s == "PINK")
		return PINK;
	if (s == "MAROON")
		return MAROON;
	if (s == "PURPLE")
		return PURPLE;
}