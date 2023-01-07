#include "CHexagon.h"

CHexagon::CHexagon() {
	this->Selected = false;
	this->isHidden = false;

}

CHexagon::CHexagon(Point P1, int Len, int _Height, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Top_Left = P1;
	Length = Len;
	Height = _Height;
	ID = ++HexaID;
}

string CHexagon::getFigureName()const
{
	return "HEXAGON";
}

int CHexagon::HexaID = 0;

void CHexagon::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawHexagon(Top_Left, Length, Height, FigGfxInfo, Selected);


}


bool CHexagon::BelongTo(int x, int y) //*****v2*******
{
	// if inside inner rectangle
	if (x >= Top_Left.x && x <= Top_Left.x + Length && y >= Top_Left.y && y <= Top_Left.y + Height)
		return true;
	///////////////////////
	float sideTrianglesArea = AreaTriangle(Top_Left.x, Top_Left.y, Top_Left.x, Top_Left.y + Height, Top_Left.x - 0.5 * Length, Top_Left.y + 0.5 * Height);
	// if inside left side triangle
	// left triangle >> (x,y), (x, y+h), (x-0.5l, y+0.5h)
	float Area1 = AreaTriangle(x, y, Top_Left.x, Top_Left.y + Height, Top_Left.x - 0.5 * Length, Top_Left.y + 0.5 * Height);
	float Area2 = AreaTriangle(Top_Left.x, Top_Left.y, x, y, Top_Left.x - 0.5 * Length, Top_Left.y + 0.5 * Height);
	float Area3 = AreaTriangle(Top_Left.x, Top_Left.y, Top_Left.x, Top_Left.y + Height, x, y);
	if (Area1 + Area2 + Area3 == sideTrianglesArea)
		return true;
	// if inside right side triangle
	// right triangle >> (x+l,y), (x+l, y+h), (x+1.5l, y+0.5h)
	Area1 = AreaTriangle(x, y, Top_Left.x + Length, Top_Left.y + Height, Top_Left.x + 1.5 * Length, Top_Left.y + 0.5 * Height);
	Area2 = AreaTriangle(Top_Left.x + Length, Top_Left.y, x, y, Top_Left.x + 1.5 * Length, Top_Left.y + 0.5 * Height);
	Area3 = AreaTriangle(Top_Left.x + Length, Top_Left.y, Top_Left.x + Length, Top_Left.y + Height, x, y);
	if (Area1 + Area2 + Area3 == sideTrianglesArea)
		return true;

	return false;
}

void CHexagon::PrintInfo(GUI* pGUI, int id) //*****v2*******
{
	// print figure information
	string msg = "ID=";
	msg += to_string(id+1);
	msg += ", center Point>> X=";
	msg += to_string(Top_Left.x + 0.5 * Length);
	msg += " Y=";
	msg += to_string(Top_Left.y + 0.5 * Height);
	msg += ", top & bottom length=";
	msg += to_string(Length);
	msg += ", Height=";
	msg += to_string(Height);
	msg += ", area=";
	msg += to_string(GetArea());
	pGUI->PrintMessage(msg);
}

void CHexagon::Resize(GUI* pGUI, float size)
{

	float length_test = Length * size;
	float height_test = Height * size;
	if ((Top_Left.y + height_test) > UI.height - UI.StatusBarHeight
		|| (Top_Left.x + length_test * 1.5) > UI.width
		|| (Top_Left.x - length_test * 0.5) < 1)
	{
		pGUI->PrintMessage("Hexagon size will be more than Drawing Area");
		Sleep(1000);
	}
	else if (length_test < 20 || height_test < 20)
	{
		pGUI->PrintMessage("Hexagon size will be very small");
		Sleep(1000);
	}
	else
	{
		Length = length_test;
		Height = height_test;
	}

}
int CHexagon::GetArea()
{
	return (Length * Height + Height * 0.5 * Length);
}

float CHexagon::AreaTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) * 0.5);
}

void CHexagon::Save(ofstream& savedFile) {
	if (savedFile.is_open())
	{
		savedFile << "HEXAGON"
			<< "\t" << ID
			<< "\t" << Top_Left.x
			<< "\t" << Top_Left.y
			<< "\t" << Length
			<< "\t" << Height
			<< "\t" << ColorString(this->FigGfxInfo.DrawClr);
		if (!this->FigGfxInfo.isFilled)
			savedFile << "\t" << "NO-FILL";
		else
			savedFile << "\t" << ColorString(this->FigGfxInfo.FillClr);
		savedFile << "\n";
	}
}

void CHexagon::Load(ifstream& savedFile)
{
	string drwColor, fillColor;
	savedFile >> ID >> Top_Left.x >> Top_Left.y >> Length >> Height >> drwColor >> fillColor;
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
