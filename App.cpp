#include"App.h"
#include<sstream>
#include<iomanip>


App::App()
	:
	wnd(800, 600, "Mew")
{}

int App::Go() 
{
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		//TranslateMessage将传递附加的WM_CHAR的键盘输入信息
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		DoFrame();
	}

	//检查GetMessage是否有用
	if (gResult == -1) 
	{
		throw CHWND_LAST_EXCEPT();
	}

	return msg.wParam;
}

void App::DoFrame()
{
	const float t = timer.Peek();
	std::ostringstream oss;
	oss << "时间" << std::setprecision(1) <<std::fixed << t << "s";
	wnd.SetTitle(oss.str());
}