#pragma once

#if defined(DLL_PLATFORM)
	#define PLATFORM_API
#else
	#define PLATFORM_API virtual
#endif

#if defined(_WIN32)
	#include "../windows/win_types.hpp"
	typedef Windows::GameLib GameLib;
#else
	#error "Unknown platform"
#endif

class I_Game;

class I_Platform
{
public:
	PLATFORM_API void    quit();
	PLATFORM_API I_Game* load_gamelib(const char* name, GameLib&);
	PLATFORM_API void    unload_gamelib(GameLib&);
	PLATFORM_API I_Game* reload_gamelib(GameLib&);
	PLATFORM_API bool    should_reload_gamelib(const GameLib&);
};
