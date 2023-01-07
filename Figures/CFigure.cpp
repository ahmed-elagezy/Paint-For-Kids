#include "CFigure.h"

CFigure::CFigure() {};

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	isHidden = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
double CFigure::CalcDistance(Point A, Point B) const {
	return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

//radwa
void CFigure::show(bool x)
{
	shown = x;						//hide
}

int CFigure::getHiddenValue()
{
	return !shown;
}

string CFigure::ColorString(color c)
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
	if ((c.ucBlue == PINK.ucBlue) && (c.ucGreen == PINK.ucGreen) && (c.ucRed == PINK.ucRed))
		return"PINK";
	if ((c.ucBlue == MAROON.ucBlue) && (c.ucGreen == MAROON.ucGreen) && (c.ucRed == MAROON.ucRed))
		return"MAROON";
	if ((c.ucBlue == PURPLE.ucBlue) && (c.ucGreen == PURPLE.ucGreen) && (c.ucRed == PURPLE.ucRed))
		return"PURPLE";
	return "NO-FILL";
}


color CFigure::StringColor(string s)const {
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

string CFigure::GetFillClr()
{
	if (FigGfxInfo.isFilled)
		return ColorString(FigGfxInfo.FillClr);
	else
		return "NON-FILLED";
}

//string CFigure::colorToString(color c)
//{
//	if (c == BLACK) return "BLACK";
//	else if (c == BLUE) return "BLUE";
//	else if (c == WHITE) return "WHITE";
//	else if (c == RED) return "RED";
//	else if (c == YELLOW) return "YELLOW";
//	else if (c == GREEN) return "GREEN";
//	else if (c == LIGHTGOLDENRODYELLOW) return "LIGHTGOLDENRODYELLOW";
//	else if (c == MAGENTA) return "MAGENTA";
//	else if (c == TURQUOISE) return "TURQUOISE";
//	else if (c == SKYBLUE) return "SKYBLUE";
//	return "COLOR";
//}

void CFigure::HideShape() {
	isHidden = true;
}

void CFigure::displayShape() {
	isHidden = false;
}
