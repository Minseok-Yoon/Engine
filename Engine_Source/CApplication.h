#pragma once
#include "CommonInclude.h"

// namespace ªÁøÎ¿Ã¿Ø class¿« ¿Ã∏ß¿Ã ∞„ƒ•±Ó∫¡
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