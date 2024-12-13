#include"Window.h"
#include<WinUser.h>
#include<sstream>

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int		  nCmdShow) 
{
	try
	{
		Window wnd(600, 500, "Mew");
		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (wnd.kbd.KeyIsPressed(VK_SPACE))
				MessageBox(nullptr, "我想看看你的作业！", "陛下，大事不好了!", MB_OK | MB_ICONEXCLAMATION);
			if(wnd.kbd.KeyIsPressed(0x41))
				MessageBox(nullptr, "刘zy变成奶龙了!", "陛下，大事不好了!", MB_OK | MB_ICONEXCLAMATION);
			if (wnd.kbd.KeyIsPressed(0x42))
				wnd.SetTitle("Mew");
			while (!wnd.mouse.IsEmpty())
			{
				const auto mou = wnd.mouse.Read();
				switch (mou.GetType())
				{
				case Mouse::Event::Type::Leave:
					wnd.SetTitle("离开");
					break;
				case Mouse::Event::Type::Move:
					{
						std::ostringstream oss;
						oss << "老鼠的位置在 (" << mou.GetPosX() << " , " << mou.GetPosY() << ")";
						wnd.SetTitle(oss.str());
					}
				}
			}
		}
		if (gResult == -1)
		{
			return -1;
		}
		return msg.wParam;
	}
	catch (const BirdException& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBox(nullptr, e.what(), "错误", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "未知的错误", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}