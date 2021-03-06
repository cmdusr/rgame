#pragma once

#include <windows.h>

namespace Windows
{
	class Internal
	{
	public:
		HINSTANCE hInstance;

		class I_Platform* platform;
		class I_Core*     core;

		// Modules
		class System*      system;
		class Window*      window;
		class GDIRenderer* gdi_renderer;
	};

	class Submodule
	{
	public:
		inline Submodule(Internal& in_internal) :
			internal{&in_internal}
		{
		}
	protected:
		Internal* internal;
	};
}
// namespace Windows
