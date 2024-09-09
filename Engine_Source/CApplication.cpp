#include "CApplication.h"
#include "CInput.h"

namespace ya
{
	CApplication::CApplication() :
		m_hWnd(nullptr),
		m_hDC(nullptr)
	{
	}
	CApplication::~CApplication()
	{
	}

	void CApplication::Init(HWND _hWnd)
	{
		m_hWnd = _hWnd;
		m_hDC = GetDC(m_hWnd);

		CInput::Init();
	}

	void CApplication::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void CApplication::Update()
	{
		CInput::Update();
	}

	void CApplication::LateUpdate()
	{
	}

	void CApplication::Render()
	{
		Rectangle(m_hDC, 500, 500, 600, 600);
	}
}