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
		HWND m_hWnd;
		HDC		m_hDC;

	public:
		void Init(HWND _hWnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
	};
}