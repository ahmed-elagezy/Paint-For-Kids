#include "CCircle.h"
#include <iostream>
#include <fstream>
#include <string>

CCircle::CCircle() {
	this->Selected = false;
	this->isHidden = false;

}

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Edge = P2;
	Radius = CalcDistance(Center, Edge);
	ID = ++CirID;
}

string CCircle::getFigureName()const
{
	return "CIRCLE";
}

int CCircle::CirID = 0;

void CCircle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawCircle(Center, Radius, FigGfxInfo, Selected);


}

bool CCircle::BelongTo(int x, int y) 
{
	//Creates a point P(x,y) to use in CalcDistance
	Point P;
	P.x = x;
	P.y = y;
	//to check if the point in the circle wa check the distance between center and the point if it is within the range
	return (Radius >= CalcDistance(Center, P));
}

void CCircle::PrintInfo(GUI* pGUI, int id)  {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Circle, ID: " + to_string(id+1) + ", Center (" + to_string(Center.x) + "," + to_string(Center.y)
		+ "), Radius: " + to_string(int(Radius));
	pGUI->PrintMessage(message);
}
void CCircle::Resize(GUI* pGUI, float size)
{

	float radius_test = Radius * size;

	if ((Center.y + radius_test) > UI.height - UI.StatusBarHeight
		|| (Center.x + radius_test * 1.5) > UI.width
		|| (Center.x - Radius * 0.5) < 1)
	{
		pGUI->PrintMessage("Circle size will be more than Drawing Area");
		Sleep(1000);
	}
	else if (radius_test < 20)
	{
		pGUI->PrintMessage("Circle size will be very small");
		Sleep(1000);
	}
	else
	{
		Radius = radius_test;
	}

}

void CCircle::Save(ofstream& savedFile) {
	if (savedFile.is_open())
	{
		savedFile << "CIRCLE"
			<< "\t" << ID
			<< "\t" << Center.x
			<< "\t" << Center.y
			<< "\t" << Edge.x
			<< "\t" << Edge.y
			<< "\t" << Radius
			<< "\t" << ColorString(this->FigGfxInfo.DrawClr);
		if (!this->FigGfxInfo.isFilled)
			savedFile << "\t" << "NO-FILL";
		else
			savedFile << "\t" << ColorString(this->FigGfxInfo.FillClr);
		savedFile << "\n";
	}
}

void CCircle::Load(ifstream& savedFile)
{
	string drwColor, fillColor;
	savedFile >> ID >> Center.x >> Center.y >> Edge.x >> Edge.y >> Radius >> drwColor >> fillColor;
	FigGfxInfo.DrawClr = this->StringColor(drwColor);
	if (fillColor == "NO-FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else
	{
		FigGfxInfo.FillClr = this->StringColor(fillColor);
		FigGfxInfo.isFilled = true;
	}
	this->FigGfxInfo.BorderWdth = 3;
	this->Selected = false;
}