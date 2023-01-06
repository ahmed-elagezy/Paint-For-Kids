#include "Action.h"

class ActionLoad : public Action {
private:
	string fileName;
	//int figuresCnt;
public:
	ActionLoad(ApplicationManager*);
	virtual void ReadParameters();
	virtual void Execute();
	color StringColor(string s) const;
};