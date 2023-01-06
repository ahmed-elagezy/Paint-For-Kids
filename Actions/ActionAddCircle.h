#ifndef ACTION_ADD_CIRCLE_H
#define ACTION_ADD_CIRCLE_H

#include "Action.h"

//Add Square Action class
class ActionAddCircle : public Action
{
public:
	ActionAddCircle(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif