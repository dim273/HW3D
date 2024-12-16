#include"App.h"
#include<sstream>
#include<iomanip>


App::App()
	:
	wnd(800, 600, "Mew")
{}

int App::Go() 
{
	while(1)
	{
		if (const auto u = Window::ProcessMessages())
		{
			return *u;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, 0.6f, c);
	wnd.Gfx().EndFrame();
}