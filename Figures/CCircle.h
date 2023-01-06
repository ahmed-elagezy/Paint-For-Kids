#ifndef CCircle_H
#define CCircle_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point Edge;
	int Radius;
public:
	static int CirID;
	CCircle();
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	bool BelongTo(int x, int y);
	void PrintInfo(GUI* pGUI, int id);
	void CCircle::Resize(GUI* pGUI, float size);
	virtual void Load(ifstream& SavedFile);
	virtual void Save(ofstream& SavedFile);
};

#endif