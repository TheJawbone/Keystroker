#if!( _DEBUG )
#include <windows.h>
#endif

#include "GameMaster.hpp"

#if( _DEBUG )
int main()
#else
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd)
#endif
{
	GameMaster game;
	game.startGame();

	return 0;
}