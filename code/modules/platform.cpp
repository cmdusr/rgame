#include "platform.hpp"

#if defined(_WIN32)
	#include "../windows/win_main.hpp"
	typedef Windows::Platform Platform;
#endif

void I_Platform::quit()
{
	return static_cast<Platform*>(this)->quit();
}

I_Game* I_Platform::load_gamelib(const char* name, GameLib& lib)
{
	return static_cast<Platform*>(this)->load_gamelib(name, lib);
}

void I_Platform::unload_gamelib(GameLib& lib)
{
	return static_cast<Platform*>(this)->unload_gamelib(lib);
}

I_Game* I_Platform::reload_gamelib(GameLib& lib)
{
	return static_cast<Platform*>(this)->reload_gamelib(lib);
}

bool I_Platform::should_reload_gamelib(const GameLib& lib)
{
	return static_cast<Platform*>(this)->should_reload_gamelib(lib);
}
