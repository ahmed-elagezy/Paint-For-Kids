#ifndef ACTION_ADD_Rectangle_H
#define ACTION_ADD_Rectangle_H

#include "Action.h"

//Add Rectangle Action class
class ActionAddRectangle : public Action
{
public:
	ActionAddRectangle(ApplicationManager* pApp);

	//Add Rectangle to the ApplicationManager
	virtual void Execute();

};

#endif
