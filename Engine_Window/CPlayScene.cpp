#include "CPlayScene.h"
#include "CGameObject.h"
#include "CInput.h"
#include "CTitleScene.h"
#include "CSceneManager.h"
#include "CSpriteRenderer.h"
#include "CObject.h"
#include "CTexture.h"
#include "CResources.h"
#include "../Engine_Window/CPlayer.h"

ya::CPlayScene::CPlayScene()
{
}

ya::CPlayScene::~CPlayScene()
{
}

void ya::CPlayScene::Init()
{
	bg = object::Instantiate<CPlayer>(enums::LAYER_TYPE::BackGround, math::Vector2(100.f, 100.f));

	CSpriteRenderer* sr = bg->AddComponent<CSpriteRenderer>();

	graphcis::CTexture* bg = CResources::Find<graphcis::CTexture>(L"BG");
	sr->SetTexture(bg);

	CScene::Init();
}

void ya::CPlayScene::Update()
{
	CScene::Update();
}

void ya::CPlayScene::LateUpdate()
{
	CScene::LateUpdate();

	if (CInput::GetKeyDown(KEY_CODE::N))
	{
		CSceneManager::LoadScene(L"TitleScene");
	}
}

void ya::CPlayScene::Render(HDC _hDC)
{
	CScene::Render(_hDC);

	wchar_t str[50];
	swprintf_s(str, 50, L"Play Scene");
	int len = wcsnlen_s(str, 10);

	TextOut(_hDC, 0, 0, str, len);
}
