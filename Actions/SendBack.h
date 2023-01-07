#ifndef SEND_BACK_H
#define SEND_BACK_H
#include "Action.h"

#pragma once
class SendBack : public Action
{
public:
	SendBack(ApplicationManager* pApp);
	void Execute();
};


#endif