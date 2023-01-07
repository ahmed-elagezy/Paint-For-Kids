#ifndef CFIGURE_H
#define CFIGURE_H
#include "..\DEFS.h"
#include "..\GUI\GUI.h"
#include<fstream>
#include<string>



//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	double CalcDistance(Point, Point) const;
	bool isHidden;
	color DrwColor, FillColor;
	bool IsFill;
	bool shown = true;
	
	/// Add more parameters if needed.

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool );	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void DrawMe(GUI*) const  = 0 ;		//Draw the figure
	virtual void Resize(GUI* pGUI, float size) = 0;
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual void PrintInfo(GUI* pGUI, int r) = 0;
	virtual bool BelongTo(int x, int y) = 0;
	//bool isShapeHiddin();
	//void HideShape();
	//void displayShape();
	int getHiddenValue();
	void show(bool x);     //radwa
	virtual string getFigureName() const = 0;  ///radwa	


	string CFigure::GetFillClr();
	//string CFigure::colorToString(color c);
	void CFigure::displayShape();
	


	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure

	string ColorString(color c); //validate the name of the color
	color StringColor(string s) const;
	/*void setGFX();*/
	virtual void Save(ofstream &OutFile)=0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile)=0;	//Load the figure parameters to the file

	void CFigure::HideShape();

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif