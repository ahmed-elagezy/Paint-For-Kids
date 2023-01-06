#include "Action.h"

class ActionSave : public Action {
private:
	string fileName;
	//int figuresCnt;
public:
	ActionSave(ApplicationManager*);
	virtual void ReadParameters();
	virtual void Execute();
	string ColorString(color c);
};