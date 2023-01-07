#ifndef CHEXAGON_H
#define CHEXAGON_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Top_Left;
	int Height;
	int Length;
public:
	static int HexaID;
	CHexagon();
	CHexagon(Point, int, int, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	bool BelongTo(int x, int y);
	void PrintInfo(GUI* pGUI, int id);
	int GetArea();
	float AreaTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
	virtual void Load(ifstream& SavedFile);
	virtual void Save(ofstream& SavedFile);
	void CHexagon::Resize(GUI* pGUI, float size);
	string getFigureName()const;
};

#endif