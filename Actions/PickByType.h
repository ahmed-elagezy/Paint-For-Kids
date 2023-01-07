#include "../Figures/CFigure.h"
#include "Action.h"
class PickByType : public Action {

	Point p;
	int  rightAns, wrongAns;
	string figureName;
public:
	PickByType(ApplicationManager* pApp);
	void Execute();
};
