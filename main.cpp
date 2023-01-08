#include "ApplicationManager.h"
#include "GUI\GUI.h"
#include "Actions\PickByColor.h"

string PickByColor::lastColor = "";

int main()
{
	ApplicationManager AppManager;
	AppManager.Run();		
	return 0;
}

