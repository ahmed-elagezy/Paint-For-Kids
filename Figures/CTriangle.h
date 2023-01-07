#ifndef CTriangle_H
#define CTriangle_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point head;
	Point bottom_right;
	Point bottom_left;
public:
	static int TriID;
	CTriangle();
	CTriangle(Point, Point, Point,GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	bool BelongTo(int x, int y);
	float CTriangle::Area(int x1, int y1, int x2, int y2, int x3, int y3);
	void PrintInfo(GUI* pGUI, int id);
	virtual void Load(ifstream& SavedFile);
	virtual void Save(ofstream& SavedFile);
	void Resize(GUI* pGUI, float size);
	string getFigureName()const;
};

#endif