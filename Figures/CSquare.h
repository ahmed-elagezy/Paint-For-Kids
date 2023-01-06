#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	int length;
public:
	static int sqrID;
	CSquare();
	CSquare(Point, int, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	virtual bool BelongTo(int x, int y);
	virtual void PrintInfo(GUI* pGUI, int id);
	int calcArea();
	virtual void Save(ofstream& savedfile);
	virtual void Load(ifstream& savedfile);
	void Resize(GUI* pGUI, float size);
};

#endif