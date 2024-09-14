#include "CTitleScene.h"

namespace ya
{
	CTitleScene::CTitleScene()
	{
	}

	CTitleScene::~CTitleScene()
	{
	}

	void CTitleScene::Init()
	{
		CScene::Init();
	}

	void CTitleScene::Update()
	{
		CScene::Update();
	}

	void CTitleScene::LateUpdate()
	{
		CScene::LateUpdate();
	}

	void CTitleScene::Render(HDC _hDC)
	{
		CScene::Render(_hDC);

		wchar_t str[50];
		swprintf_s(str, 50, L"Title Scene");
		int len = wcsnlen_s(str, 11);

		TextOut(_hDC, 0, 0, str, len);
	}
	void CTitleScene::OnEnter()
	{
		CScene::OnEnter();
	}

	void CTitleScene::OnExit()
	{
		CScene::OnExit();
	}
}