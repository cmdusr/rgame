#include "rsnake.hpp"
#include "../../modules/core.hpp"

I_Game* get_game_api(I_Core* core)
{
	static RSnake api{};
	api.set_core(core);
	return &api;
}

void RSnake::init()
{

}

void RSnake::update()
{
	
}

void RSnake::set_core(I_Core* core)
{
	internal.core = core;
}
