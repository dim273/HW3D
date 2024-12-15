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
	const float t = timer.Peek();
	std::ostringstream oss;
	oss << "Ê±¼ä" << std::setprecision(1) <<std::fixed << t << "s";
	wnd.SetTitle(oss.str());
}