#pragma once

#include <windows.h>

namespace Windows
{
	class System;
	class Window;

	class Internal
	{
	public:
		HINSTANCE hInstance;

		// Modules
		System* system;
		Window* window;
	};
}
// namespace Windows
