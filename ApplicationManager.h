#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include <vector>

#include "DEFS.h"
#include "Figures\CFigure.h"

class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	int flag;
	//CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	vector<CFigure*>FigList;/////منك لله يا اخي ....(

	//Pointers to Input and Output classes
	GUI* pGUI;
	

public:	
	ApplicationManager(); 
	~ApplicationManager();

	void saveAll(ofstream& Out);

	void clearFigList();

	void Run();		//to run the application
	
	// -- Action-Related Functions
	Action* CreateAction(ActionType);
	void ExecuteAction(Action*&) ; //Execute an action
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions	
	GUI *GetGUI() const; //Return pointer to the interface
	void UpdateInterface() const;	//Redraws all the drawing window	

	int ApplicationManager::GetIndex(CFigure* c);

	void ApplicationManager::DeleteShape();
	/////
	void ApplicationManager::Resize_figure(GUI* pGUI, float size) const;
	void changeFillColor(color FillClr);
	void changeDrawColor(color drawClr);
	bool GetColor(color&);
	bool AnySelected();
	void  unselectAll();
	//void displayAllFigures();

	string getRandomFigure(int& count);   //radwa
	void showAllFigure();
	int getFigCount() const;
	CFigure* ApplicationManager::getAnyFigure();
	bool ApplicationManager::hasDifferentColors();
	CFigure* getFigList(int)const;

};

#endif