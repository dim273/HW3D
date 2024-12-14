#include"App.h"
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
		return App{}.Go();
	}
	catch (const BirdException& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBox(nullptr, e.what(), "´íÎó", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "Î´ÖªµÄ´íÎó", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}