#include "core.hpp"
#include "../core/core.hpp"

void I_Core::quit()
{
	return static_cast<Core*>(this)->quit();
}
