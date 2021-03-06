#include "win_main.hpp"
#include <cstring>
#include <cstdlib>
#include <cstdio>

Windows::Platform::Platform() : I_Platform{},
	core{this},
	internal{},
	window{internal}
{
}

void Windows::Platform::quit()
{
	std::quick_exit(EXIT_SUCCESS);
}

void Windows::Platform::setup_console()
{
	FILE* temp;
	AllocConsole();
	freopen_s(&temp, "CONIN$",  "r", stdin);
	freopen_s(&temp, "CONOUT$", "w", stdout);
	freopen_s(&temp, "CONOUT$", "w", stderr);
}

bool Windows::Platform::should_reload_gamelib(const GameLib& lib)
{
	char lib_path[MAX_PATH]{};
	GetModuleFileName(lib.handle, lib_path, sizeof(lib_path));

    WIN32_FILE_ATTRIBUTE_DATA attributes;
	GetFileAttributesExA(lib_path, GetFileExInfoStandard, &attributes);
	return CompareFileTime(&attributes.ftLastWriteTime, &lib.last_write_time) != 0;
}

I_Game* Windows::Platform::load_gamelib(const char* name, GameLib& lib)
{
	char lib_path[MAX_PATH]{};
	strcpy_s(lib_path, name);
	strcat_s(lib_path, lib_extension);
	return load_gamelib_fullpath(lib_path, lib);
}

I_Game* Windows::Platform::load_gamelib_fullpath(const char* lib_path, GameLib& lib)
{
    WIN32_FILE_ATTRIBUTE_DATA attributes;
	if(GetFileAttributesEx(lib_path, GetFileExInfoStandard, &attributes) == INVALID_FILE_ATTRIBUTES)
	{
		// File not found
		return nullptr;
	}

	lib.last_write_time = attributes.ftLastWriteTime;

	lib.handle = LoadLibrary(lib_path);
	if(!lib.handle)
	{
		return nullptr;
	}

	auto get_api = (GetGameApiFunction)GetProcAddress(lib.handle, game_api_function_name);
	if(!get_api)
	{
		return nullptr;
	}
	return get_api(internal.core);
}

void Windows::Platform::unload_gamelib(GameLib& lib)
{
	FreeLibrary(lib.handle);
}

I_Game* Windows::Platform::reload_gamelib(GameLib& lib)
{
	char lib_path[MAX_PATH]{};
	GetModuleFileName(lib.handle, lib_path, sizeof(lib_path));

	unload_gamelib(lib);
	return load_gamelib_fullpath(lib_path, lib);
}

int Windows::Platform::main(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	internal.hInstance = hInstance;
	internal.platform  = this;
	internal.core      = &core;

	setup_console();

	core.init();

	for(;;)
	{
		core.update();
	}

	// Never reach here
	return 0;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	static Windows::Platform platform{};
	return platform.main(hInstance, hPrevInstance, pCmdLine, nCmdShow);
}
