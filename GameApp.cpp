#include"GameApp.h"
#include"d3dUtil.h"
#include"DXTrace.h"

GameApp::GameApp(HINSTANCE hInstance, const std::wstring& windowName, int initWidth, int initHeight)
	:
	D3DApp(hInstance, windowName, initWidth, initHeight)
{}

GameApp::~GameApp()
{
}

bool GameApp::Init()
{
	if(!D3DApp::Init())
		return false;
	return true;
}

void GameApp::OnResize()
{
	D3DApp::OnResize();
}

void GameApp::Update(float dt)
{
}

void GameApp::DrawUpdate()
{
	assert(m_pd3dImmediateContext);
	assert(m_pSwapChain);
	static float blue[4] = { 0.0f,0.0f,1.0f,1.0f };
	m_pd3dImmediateContext->ClearRenderTargetView(m_pRenderTargetView.Get(), blue);
	m_pd3dImmediateContext->ClearDepthStencilView(m_pDepthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
}

