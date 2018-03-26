#if!( _DEBUG )
#include <windows.h>
#endif

#include <Editor.hpp>

#if( _DEBUG )
int main()
#else
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd)
#endif
{
	Editor editor;
	editor.start();

	return 0;
}