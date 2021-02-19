#include "win_system.hpp"
#include <windows.h>

Windows::System::System(Internal& internal) : Submodule{internal}
{

}

void Windows::System::init()
{
}

void Windows::System::quit()
{
	quick_exit(EXIT_SUCCESS);
}
