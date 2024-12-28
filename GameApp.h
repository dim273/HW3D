#ifndef GAMEAPP_H
#define GAMEAPP_H

#include"d3dApp.h"
class GameApp :public D3DApp
{
public:
	GameApp(HINSTANCE hInstance, const std::wstring& windowName, int initWidth, int initHeight);
	~GameApp();

	bool Init();
	void OnResize();
	void Update(float dt);
	void DrawUpdate();
};

#endif // ! GAMEAPP_H
