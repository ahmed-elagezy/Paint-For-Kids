#include "CRectangle.h"

CRectangle::CRectangle() {
	this->Selected = false;
}

CRectangle::CRectangle(Point _ul, Point _lr, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ul = _ul;
	lr = _lr;
	ID = ++RecID;
}

string CRectangle::getFigureName() const
{
	return "RECTANGLE";
}

int CRectangle::RecID = 0;

void CRectangle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawRectangle(ul, lr, FigGfxInfo, Selected);

}

bool CRectangle::BelongTo(int x, int y)
{
	if ((x >= min(ul.x, lr.x) && x <= max(ul.x, lr.x) && y >= min(ul.y, lr.y) && y <= max(ul.y, lr.y)))
	{
		return true;
	}
	return false;
}

void CRectangle::PrintInfo(GUI* pGUI,int id) {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Rectangle, ID: " + to_string(id+1) + ", Corner 1: (" + to_string(ul.x) + "," + to_string(ul.y)
		+ "), Corner 2: (" + to_string(lr.x) + "," + to_string(lr.y) + "), Length: "
		+ to_string(abs(ul.x - lr.x)) + ", Width: " + to_string(abs(ul.y - lr.y));
	pGUI->PrintMessage(message);
}
void CRectangle::Resize(GUI* pGUI,float resizeFactor)
{
	Point Center;
	Center.x = (ul.x + lr.x) / 2;
	Center.y = (ul.y + lr.y) / 2;

	int horizontal = abs(ul.x - Center.x);
	int vertical = abs(ul.y - Center.y);

	ul.x = Center.x + horizontal * resizeFactor;
	lr.x = Center.x - horizontal * resizeFactor;

	ul.y = Center.y + vertical * resizeFactor;
	lr.y = Center.y - vertical * resizeFactor;
}

void CRectangle::Save(ofstream& savedFile) {
	if (savedFile.is_open())
	{
		savedFile << "RECTANGLE"
			<< "\t" << ID
			<< "\t" << ul.x
			<< "\t" << ul.y
			<< "\t" << lr.x
			<< "\t" << lr.y
			<< "\t" << ColorString(this->FigGfxInfo.DrawClr);
		if (!this->FigGfxInfo.isFilled)
			savedFile << "\t" << "NO-FILL";
		else
			savedFile << "\t" << ColorString(this->FigGfxInfo.FillClr);
		savedFile << "\n";
	}
}

void CRectangle::Load(ifstream& savedFile)
{
	string drwColor, fillColor;
	savedFile >> ID >> ul.x >> ul.y >> lr.x >> lr.y >> drwColor >> fillColor;
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
