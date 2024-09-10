#include "CApplication.h"
#include "CInput.h"
#include "CTime.h"
#include "CSceneManager.h"

namespace ya
{
	CApplication::CApplication() :
		m_hWnd(nullptr),
		m_hDC(nullptr),
		m_iWidth(0),
		m_iHeight(0),
		m_hBackBuffer(nullptr),
		m_hBackDC(nullptr)
	{
	}
	CApplication::~CApplication()
	{
	}

	void CApplication::Init(HWND _hWnd, UINT _iWidth, UINT _iHeight)
	{
		m_hWnd = _hWnd;
		m_hDC = GetDC(m_hWnd);

#pragma region
		//RECT rect = { 0, 0, _iWidth, _iHeight };
		//AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		//SetWindowPos(m_hWnd, nullptr, 0, 0, 
		//	rect.right - rect.left, rect.bottom - rect.top, 0);
		//ShowWindow(m_hWnd, true);

		//// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
		//m_hBackBuffer = CreateCompatibleBitmap(m_hDC, _iWidth, _iHeight);

		//// 백버퍼를 가르킬 DC 생성
		//m_hBackDC = CreateCompatibleDC(m_hDC);

		//HBITMAP m_hOldBitmap = (HBITMAP)SelectObject(m_hBackDC, m_hBackBuffer);
		//DeleteObject(m_hOldBitmap);
#pragma endregion
		AdjustWindowRect(m_hWnd, _iWidth, _iHeight);

		CInput::Init();
		CTime::Init();

		CSceneManager::Init();
	}

	void CApplication::Update()
	{
		CInput::Update();
		CTime::Update();

		CSceneManager::Update();
	}

	void CApplication::LateUpdate()
	{
		CSceneManager::LateUpdate();
	}

	void CApplication::Render()
	{
		CTime::Render(m_hDC);
		CSceneManager::Render(m_hDC);
	}

	void CApplication::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void CApplication::AdjustWindowRect(HWND _hWnd, UINT _iWidth, UINT _iHeight)
	{
		RECT rect = { 0, 0, static_cast<LONG>(_iWidth), static_cast<LONG>(_iHeight) };
		::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		m_iWidth = rect.right - rect.left;
		m_iHeight = rect.bottom - rect.top;

		SetWindowPos(_hWnd, nullptr, 0, 0, m_iWidth, m_iHeight, 0);
		ShowWindow(_hWnd, true);
	}
}