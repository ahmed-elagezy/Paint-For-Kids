#ifndef ACTION_SELECT_H
#define ACTION_SELECT_H

#include "Action.h"
//*****v2*******
//Add Square Action class
class ActionSelectShape : public Action
{
public:
	ActionSelectShape(ApplicationManager* pApp);

	//excute selection
	virtual void Execute();

};

#endif
