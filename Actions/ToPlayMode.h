
#include "Action.h"

class ToPlayMode :public Action {
public:
	ToPlayMode(ApplicationManager* pApp);

	//Executes the switch to play mode
	virtual void Execute();
};

