#pragma once
#include"Window.h"
#include"BirddimTimer.h"

class App
{
public:
	App();
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	BirddimTimer timer;
};