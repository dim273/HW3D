#ifndef D3DAPP_H
#define D3DAPP_H

#include<string>
#include<wrl/client.h>
#include<d3d11_1.h>
#include<DirectXMath.h>
#include"WinMin.h"
#include"CpuTimer.h"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "D3DCompiler.lib")
#pragma comment(lib, "winmm.lib")


class D3DApp
{
public:
	D3DApp(HINSTANCE hInstance, const std::wstring& windowName, int initWidth, int initHeight);
	virtual ~D3DApp();
	HINSTANCE GetInstance() const;				//获取应用实例
	HWND MainWnd() const;						//获取主窗口
	float AspectRatio() const;					//获取屏幕宽高比

	int run();									//运行程序

	virtual bool Init();						//该父类方法需要初始化窗口和Direct3D部分
	virtual void OnResize();					//该父类方法需要在窗口大小变动的时候调用
	virtual void Update(float dt) = 0;			//子类实现，每一帧的更新
	virtual void DrawUpdate() = 0;				//子类实现，每一帧的绘制
	virtual LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
protected:
	bool InitMainWindow();			//初始化窗口
	bool InitDirect3D();			//初始化Direct3D
	void CalculateFrameStats();		//计算每一秒的帧数并在窗口显示
protected:
	HINSTANCE m_hAppInstance;		//应用实例句柄
	HWND m_hMainWnd;				//主窗口句柄
	bool m_AppPaused;				//是否暂停
	bool m_Minimized;				//是否最小化
	bool m_Maximized;				//是否最大化
	bool m_Resizing;				//窗口大小是否变化	
	bool m_Enable4xMsaa;			//是否开启4倍多重采样
	UINT m_4xMsaaQuality;			//MSAA支持的质量等级

	CpuTimer m_Timer;				//计时器
	
	template <class T>
	using Comptr = Microsoft::WRL::ComPtr<T>;
	//Direct3D 11
	Comptr<ID3D11Device> m_pd3dDevice;							//D3D11设备
	Comptr<ID3D11DeviceContext> m_pd3dImmediateContext;			//D3D11设备上下文
	Comptr<IDXGISwapChain> m_pSwapChain;						//D3D11交换链
	//Direct3D 11.1
	Comptr<ID3D11Device1> m_pd3dDevice1;
	Comptr<ID3D11DeviceContext1> m_pd3dImmediateContext1;
	Comptr<IDXGISwapChain1> m_pSwapChain1;
	//常用的资源
	Comptr<ID3D11Texture2D> m_pDepthStencilBuffer;				//深度模板缓冲区
	Comptr<ID3D11RenderTargetView> m_pRenderTargetView;			//渲染目标视图
	Comptr<ID3D11DepthStencilView> m_pDepthStencilView;			//深度模板视图
	D3D11_VIEWPORT m_ScreenViewport;							//视口

	std::wstring m_MainWndCaption;								//主窗口标题
	int m_ClientWidth;											//视口宽度
	int m_ClientHeight;											//视口高度
};

#endif // !D3DAPP_H

