#include "CTriangle.h"


CTriangle::CTriangle() {
	this->Selected = false;
	this->isHidden = false;

}

CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	head = P1;
	bottom_right = P2;
	bottom_left = P3;
	ID = ++TriID;
}

string CTriangle::getFigureName()const
{
	return "TRIANGLE";
}

int CTriangle::TriID = 0;

void CTriangle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawTriangle(head, bottom_right,bottom_left,FigGfxInfo, Selected);


}

bool CTriangle::BelongTo(int x, int y) 
{
	int x1 = head.x;
	int y1 = head.y;
	int x2 = bottom_right.x;
	int y2 = bottom_right.y;
	int x3 = bottom_left.x;
	int y3 = bottom_left.y;

	/* Calculate area of triangle ABC */
	float A = Area(x1, y1, x2, y2, x3, y3);

	/* Calculate area of triangle PBC */
	float A1 = Area(x, y, x2, y2, x3, y3);

	/* Calculate area of triangle PAC */
	float A2 = Area(x1, y1, x, y, x3, y3);

	/* Calculate area of triangle PAB */
	float A3 = Area(x1, y1, x2, y2, x, y);
	
	return (A == A1 + A2 + A3);
}

float CTriangle::Area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}


void CTriangle::PrintInfo(GUI* pGUI, int id) {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Triangle, ID: " + to_string(id+1) + ", Corner 1: (" + to_string(head.x) + "," + to_string(head.y)
		+ "), Corner 2: (" + to_string(bottom_right.x) + "," + to_string(bottom_right.y) + "), Corner 3: (" + to_string(bottom_left.x)
		+ "," + to_string(bottom_left.y) + ")";
	pGUI->PrintMessage(message);
}

void CTriangle::Resize(GUI* pGUI, float size)
{
	if (size == 0.5) size = -1;
	else if (size == 0.25) size = -(4.0 / 3);

	Point O;
	O.x = (head.x + bottom_left.x + bottom_right.x) / 3;
	O.y = (head.y + bottom_left.y + bottom_right.y) / 3;
	if (head.x <= O.x)
		head.x -= (O.x - head.x) * size / 2;
	else
		head.x += (head.x - O.x) * size / 2;

	if (bottom_left.x <= O.x)
		bottom_left.x -= (O.x - bottom_left.x) * size / 2;
	else
		bottom_left.x += (bottom_left.x - O.x) * size / 2;

	if (bottom_right.x <= O.x)
		bottom_right.x -= (O.x - bottom_right.x) * size / 2;
	else
		bottom_right.x += (bottom_right.x - O.x) * size / 2;

	if (head.y <= O.y)
		head.y -= (O.y - head.y) * size / 2;
	else
		head.y += (head.y - O.y) * size / 2;

	if (bottom_left.y <= O.y)
		bottom_left.y -= (O.y - bottom_left.y) * size / 2;
	else
		bottom_left.y += (bottom_left.y - O.y) * size / 2;

	if (bottom_right.y <= O.y)
		bottom_right.y -= (O.y - bottom_right.y) * size / 2;
	else
		bottom_right.y += (bottom_right.y - O.y) * size / 2;
}

void CTriangle::Save(ofstream& savedFile) {
	if (savedFile.is_open())
	{
		savedFile << "TRIANGLE"
			<< "\t" << ID
			<< "\t" << head.x
			<< "\t" << head.y
			<< "\t" << bottom_right.x
			<< "\t" << bottom_right.y
			<< "\t" << bottom_left.x
			<< "\t" << bottom_left.y
			<< "\t" << ColorString(this->FigGfxInfo.DrawClr);
		if (!this->FigGfxInfo.isFilled)
			savedFile << "\t" << "NO-FILL";
		else
			savedFile << "\t" << ColorString(this->FigGfxInfo.FillClr);
		savedFile << "\n";
	}
}

void CTriangle::Load(ifstream& savedFile)
{
	string drwColor, fillColor;
	savedFile >> ID >> head.x >> head.y >> bottom_right.x >> bottom_right.y >> bottom_left.x >> bottom_left.y >> drwColor >> fillColor;
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
