#pragma once
#include "Action.h"
class BackToDraw :public Action {
public:
	BackToDraw(ApplicationManager* pApp);
	virtual void Execute();
};
