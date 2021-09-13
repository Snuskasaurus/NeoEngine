#include "../../Includes/Core/Screen.h"

using namespace neo;

Screen* neo::Screen::Instance()
{
	static Screen screen;
	return &screen;
}
