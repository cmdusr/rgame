#pragma once

#include "../modules/platform.hpp"
#include "../modules/core.hpp"
#include "../modules/game.hpp"

namespace Core
{
	class Main final : public I_Core
	{
	public:
		Main(I_Platform*);
		void init();
		void cleanup();
		void update();
	private:
		const char* gamelib_name = "game";
		GameLib     gamelib;
		I_Game*     game;
		I_Platform* platform;
	};
}
// namespace Core
