@echo off

rem Check for cl.exe
where.exe /q cl.exe
if ERRORLEVEL 1 (
	echo Error: Cannot find cl.exe. Setup your devlopment environment to include cl.exe
	echo This can be done by using vcvarsall.bat if running from a console
	echo Search for developer command prompt
	goto END
)

if not exist code (
	echo Error: Invalid directory. Must be run from the root directory
	goto END
)

if not exist build mkdir build

rem Common compiler flags
set CCFLAGS=/D_HAS_EXCEPTIONS=0 /nologo /I..\code /Zi
set LDFLAGS=-incremental:no

pushd build

rem Core rgame app
cl %CCFLAGS% /Fergame ..\code\unity\windows_unity.cpp /link %LDFALGS% user32.lib shell32.lib gdi32.lib

rem VisualStudio does not unload .pdb when .dll is unloaded.
rem Create new .pdb so that it can be loaded and not distrub existing .pdb
cl %CCFLAGS% /Fegame_temp.dll ..\code\unity\rsnake_unity.cpp /LD /link %LDFLAGS% /PDB:game_%random%.pdb /Export:get_game_api

popd

:END
