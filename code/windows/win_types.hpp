#pragma once

#include <windows.h>

class I_Game;

namespace Windows
{
	struct GameLib
	{
		HMODULE  handle;
		I_Game*  api;
		FILETIME last_write_time;
	};
}
// namespace Windows
