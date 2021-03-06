#pragma once

#define DLL_GAME

#if defined(DLL_GAME)
	#define GAME_API virtual
#else
	#define GAME_API
#endif

class I_Core;
class I_Game;

typedef I_Game* (*GetGameApiFunction)(I_Core*);
static const char* game_api_function_name = "get_game_api";

class I_Game
{
public:
	GAME_API void init();
	GAME_API void update();
};
