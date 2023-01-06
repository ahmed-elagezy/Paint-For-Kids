#include "ActionSave.h"
#include"..\ApplicationManager.h"
#include"..\Figures\CFigure.h"
#include "..\GUI\GUI.h"
#include<fstream>
#include <iostream>

ActionSave::ActionSave(ApplicationManager* pApp) :Action(pApp) {

}

void ActionSave::ReadParameters() {
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Enter file name"); //Read file name
	fileName = pGUI->GetSrting();
}

void ActionSave::Execute() {
	ReadParameters();
	GUI* pGUI = pManager->GetGUI();
	ofstream savedFile;
	savedFile.open("Saved\\" + fileName + ".txt"); //Create txt file
	savedFile << ColorString(UI.DrawColor)
		<< "\t" << ColorString(UI.FillColor)
		<< "\t" << ColorString(UI.BkGrndColor)
		<< "\n";

	pManager->saveAll(savedFile);
	pGUI->PrintMessage("File saved successfully");
	savedFile.close();
}

string ActionSave::ColorString(color c)
{
	if ((c.ucBlue == BLACK.ucBlue) && (c.ucGreen == BLACK.ucGreen) && (c.ucRed == BLACK.ucRed))
		return "BLACK";
	if ((c.ucBlue == BLUE.ucBlue) && (c.ucGreen == BLUE.ucGreen) && (c.ucRed == BLUE.ucRed))
		return "BLUE";
	if ((c.ucBlue == WHITE.ucBlue) && (c.ucGreen == WHITE.ucGreen) && (c.ucRed == WHITE.ucRed))
		return "WHITE";
	if ((c.ucBlue == RED.ucBlue) && (c.ucGreen == RED.ucGreen) && (c.ucRed == RED.ucRed))
		return "RED";
	if ((c.ucBlue == YELLOW.ucBlue) && (c.ucGreen == YELLOW.ucGreen) && (c.ucRed == YELLOW.ucRed))
		return "YELLOW";
	if ((c.ucBlue == GREEN.ucBlue) && (c.ucGreen == GREEN.ucGreen) && (c.ucRed == GREEN.ucRed))
		return "GREEN";
	if ((c.ucBlue == LIGHTGOLDENRODYELLOW.ucBlue) && (c.ucGreen == LIGHTGOLDENRODYELLOW.ucGreen) && (c.ucRed == LIGHTGOLDENRODYELLOW.ucRed))
		return "LIGHTGOLDENRODYELLOW";
	if ((c.ucBlue == MAGENTA.ucBlue) && (c.ucGreen == MAGENTA.ucGreen) && (c.ucRed == MAGENTA.ucRed))
		return "MAGENTA";
	if ((c.ucBlue == TURQUOISE.ucBlue) && (c.ucGreen == TURQUOISE.ucGreen) && (c.ucRed == TURQUOISE.ucRed))
		return "TURQUOISE";
	if ((c.ucBlue == SKYBLUE.ucBlue) && (c.ucGreen == SKYBLUE.ucGreen) && (c.ucRed == SKYBLUE.ucRed))
		return "SKYBLUE";
	if ((c.ucBlue == LIGHTSTEELBLUE.ucBlue) && (c.ucGreen == LIGHTSTEELBLUE.ucGreen) && (c.ucRed == LIGHTSTEELBLUE.ucRed))
		return "LIGHTSTEELBLUE";
	if ((c.ucBlue == IVORY.ucBlue) && (c.ucGreen == IVORY.ucGreen) && (c.ucRed == IVORY.ucRed))
		return"IVORY";
	return "NO-FILL";
}