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
	HINSTANCE GetInstance() const;				//��ȡӦ��ʵ��
	HWND MainWnd() const;						//��ȡ������
	float AspectRatio() const;					//��ȡ��Ļ��߱�

	int run();									//���г���

	virtual bool Init();						//�ø��෽����Ҫ��ʼ�����ں�Direct3D����
	virtual void OnResize();					//�ø��෽����Ҫ�ڴ��ڴ�С�䶯��ʱ�����
	virtual void Update(float dt) = 0;			//����ʵ�֣�ÿһ֡�ĸ���
	virtual void DrawUpdate() = 0;				//����ʵ�֣�ÿһ֡�Ļ���
	virtual LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
protected:
	bool InitMainWindow();			//��ʼ������
	bool InitDirect3D();			//��ʼ��Direct3D
	void CalculateFrameStats();		//����ÿһ���֡�����ڴ�����ʾ
protected:
	HINSTANCE m_hAppInstance;		//Ӧ��ʵ�����
	HWND m_hMainWnd;				//�����ھ��
	bool m_AppPaused;				//�Ƿ���ͣ
	bool m_Minimized;				//�Ƿ���С��
	bool m_Maximized;				//�Ƿ����
	bool m_Resizing;				//���ڴ�С�Ƿ�仯	
	bool m_Enable4xMsaa;			//�Ƿ���4�����ز���
	UINT m_4xMsaaQuality;			//MSAA֧�ֵ������ȼ�

	CpuTimer m_Timer;				//��ʱ��
	
	template <class T>
	using Comptr = Microsoft::WRL::ComPtr<T>;
	//Direct3D 11
	Comptr<ID3D11Device> m_pd3dDevice;							//D3D11�豸
	Comptr<ID3D11DeviceContext> m_pd3dImmediateContext;			//D3D11�豸������
	Comptr<IDXGISwapChain> m_pSwapChain;						//D3D11������
	//Direct3D 11.1
	Comptr<ID3D11Device1> m_pd3dDevice1;
	Comptr<ID3D11DeviceContext1> m_pd3dImmediateContext1;
	Comptr<IDXGISwapChain1> m_pSwapChain1;
	//���õ���Դ
	Comptr<ID3D11Texture2D> m_pDepthStencilBuffer;				//���ģ�建����
	Comptr<ID3D11RenderTargetView> m_pRenderTargetView;			//��ȾĿ����ͼ
	Comptr<ID3D11DepthStencilView> m_pDepthStencilView;			//���ģ����ͼ
	D3D11_VIEWPORT m_ScreenViewport;							//�ӿ�

	std::wstring m_MainWndCaption;								//�����ڱ���
	int m_ClientWidth;											//�ӿڿ��
	int m_ClientHeight;											//�ӿڸ߶�
};

#endif // !D3DAPP_H

