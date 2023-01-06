#include "Action.h"
#include "ActionSelectShape.h"

class ActionResize : public Action
{
public:
	ActionResize(ApplicationManager* pApp);

	//Add resize to the ApplicationManager
	virtual void Execute();
};
