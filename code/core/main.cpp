#include "main.hpp"

Core::Main::Main(I_Platform* in_platform) :
	platform{in_platform}
{
}

void Core::Main::init()
{
	game = platform->load_gamelib(gamelib_name, gamelib);
}

void Core::Main::cleanup()
{
	
}

void Core::Main::update()
{
	if(!game)
	{
		game = platform->load_gamelib(gamelib_name, gamelib);
	}
	if(platform->should_reload_gamelib(gamelib))
	{
		platform->reload_gamelib(gamelib);
	}
}
