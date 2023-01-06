#ifndef ACTION_DELETE_H
#define ACTION_DELETE_H

#include "Action.h"

class ActionDeleteShape : public Action
{
public:
	ActionDeleteShape(ApplicationManager* pApp);

	//excute Delete
	virtual void Execute();

};

#endif
