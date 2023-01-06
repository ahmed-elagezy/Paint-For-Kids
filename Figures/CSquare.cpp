#include "CSquare.h"
#include <iostream>
#include <fstream>
#include <string>


CSquare::CSquare()
{
	this->Selected = false;
};

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
	ID = ++sqrID;
}
int CSquare::sqrID = 0;
	

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	

}

bool CSquare::BelongTo(int x, int y) {
	if (x >= TopLeftCorner.x && x <= (TopLeftCorner.x + length) && y >= TopLeftCorner.y && y <= (TopLeftCorner.y + length))
		return true;
	else
		return false;
}

void CSquare::PrintInfo(GUI* pGUI, int id) {
	string msg = "ID=";
	msg += to_string(id+1);
	msg += ", top left Point>> X=";
	msg += to_string(TopLeftCorner.x);
	msg += " Y=";
	msg += to_string(TopLeftCorner.y);
	msg += ", length=";
	msg += to_string(length);
	msg += ", area=";
	msg += to_string(calcArea());
	pGUI->PrintMessage(msg);
}

int CSquare::calcArea() {
	return pow(length, 2);
}
void CSquare::Resize(GUI* pGUI, float size)
{
	float length_test = length;
	Point test1 = TopLeftCorner;
	Point test2;
	test2.x = test1.x + length;
	test2.y = test1.y + length;
	length_test *= size;
	test2.x = test1.x + length_test;
	test2.y = test1.y + length_test;

	if (test1.y < UI.ToolBarHeight || test2.y > UI.height - UI.StatusBarHeight
		|| test2.x > UI.width || test1.x < 1)
	{
		pGUI->PrintMessage("Square size will be more than Drawing Area");
		Sleep(1000);
	}
	else if (length_test < 20)
	{
		pGUI->PrintMessage("Square size will be very small");
		Sleep(1000);
	}
	else
	{
		TopLeftCorner = test1;
		length = length_test;
		//PrintInfo(pGUI);
	}
}
void CSquare::Save(ofstream& savedFile) {
	if (savedFile.is_open())
	{
		savedFile << "SQUARE"
			<< "\t" << ID
			<< "\t" << TopLeftCorner.x
			<< "\t" << TopLeftCorner.y
			<< "\t" << length
			<< "\t" << ColorString(this->FigGfxInfo.DrawClr);
		if (!this->FigGfxInfo.isFilled)
			savedFile << "\t" << "NO-FILL";
		else
			savedFile << "\t" << ColorString(this->FigGfxInfo.FillClr);
		savedFile << "\n"; 
	}
}


void CSquare::Load(ifstream& savedFile)
{
	string drwColor, fillColor;
	savedFile >> ID >> TopLeftCorner.x >> TopLeftCorner.y >> length >> drwColor >> fillColor;
	FigGfxInfo.DrawClr = this->StringColor(drwColor);
	if (fillColor == "NO-FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else
	{
		FigGfxInfo.FillClr = this-> StringColor(fillColor);
		FigGfxInfo.isFilled = true;
	}
	this->FigGfxInfo.BorderWdth = 3;
	this->Selected = false;
//setGFX();
}
