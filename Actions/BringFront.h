#ifndef SEND_FRONT_H
#define SEND_FRONT_H
#include "Action.h"


class BringFront : public Action
{
public:
	BringFront(ApplicationManager* pApp);
	void Execute();
};
#endif