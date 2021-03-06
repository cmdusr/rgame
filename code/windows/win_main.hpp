#pragma once

#include "../core/main.hpp"
#include "../modules/platform.hpp"
#include "win_internal.hpp"
#include "win_window.hpp"
#include <windows.h>

namespace Windows
{
	static const char* lib_extension = ".dll";

	class Platform final : public I_Platform
	{
	public:
		Platform();

		int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);

		PLATFORM_API void    quit();
		PLATFORM_API I_Game* load_gamelib(const char* name, GameLib&);
		PLATFORM_API void    unload_gamelib(GameLib&);
		PLATFORM_API I_Game* reload_gamelib(GameLib&);
		PLATFORM_API bool    should_reload_gamelib(const GameLib&);
	private:
		Core::Main core;
		Internal   internal;
		Window     window;

		I_Game* load_gamelib_fullpath(const char* path, GameLib&);
		static void setup_console();
	};
}
// namespace Windows
