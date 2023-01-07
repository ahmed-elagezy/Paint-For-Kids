#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point ul;
	Point lr;

public:
	static int RecID;
	CRectangle();
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	bool BelongTo(int x, int y);
	void PrintInfo(GUI* pGHI, int id);
	virtual void Load(ifstream& SavedFile);
	virtual void Save(ofstream& SavedFile);
	void CRectangle::Resize(GUI* pGUI,float);
	string getFigureName()const;
};
#endif
