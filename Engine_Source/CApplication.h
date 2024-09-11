#pragma once
#include "CommonInclude.h"

// namespace ������� class�� �̸��� ��ĥ���
namespace ya
{
	class CApplication
	{
	public:
		CApplication();
		~CApplication();

	private:
		HWND	m_hWnd;
		HDC		m_hDC;
		UINT	m_iWidth;
		UINT	m_iHeight;

		HDC		m_hBackDC;
		HBITMAP	m_hBackBuffer;

	public:
		HDC GetHdc() { return m_hDC; }

	public:
		void Init(HWND _hWnd, UINT _iWidth, UINT _iHeight);
		void Update();
		void LateUpdate();
		void Render();

		void Run();

		void AdjustWindowRect(HWND _hWnd, UINT _iWidth, UINT _iHeight);

	};
}