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
#include "CPlayerScript.h"
#include "CCamera.h"
#include "CRenderer.h"

ya::CPlayScene::CPlayScene()
{
}

ya::CPlayScene::~CPlayScene()
{
}

void ya::CPlayScene::Init()
{
#pragma region
	/*bg = object::Instantiate<CPlayer>(enums::LAYER_TYPE::BackGround, math::Vector2(100.f, 100.f));

	CSpriteRenderer* sr = bg->AddComponent<CSpriteRenderer>();

	graphcis::CTexture* bg = CResources::Find<graphcis::CTexture>(L"BG");
	sr->SetTexture(bg);*/
#pragma endregion
	// main camera
	CGameObject* camera = object::Instantiate<CGameObject>(enums::LAYER_TYPE::None, math::Vector2(344.0f, 442.0f));
	CCamera* cameraComp = camera->AddComponent<CCamera>();
	renderer::mainCamera = cameraComp;

	m_pPlayer = object::Instantiate<CPlayer>(enums::LAYER_TYPE::Player);
	CSpriteRenderer* sr = m_pPlayer->AddComponent<CSpriteRenderer>();
	sr->SetSize(math::Vector2(3.0f, 3.0f));
	m_pPlayer->AddComponent<CPlayerScript>();

	graphcis::CTexture* packmanTexture = CResources::Find<graphcis::CTexture>(L"PackMan");
	sr->SetTexture(packmanTexture);

	CGameObject* bg = object::Instantiate<CGameObject>(enums::LAYER_TYPE::BackGround);
	CSpriteRenderer* bgSr = bg->AddComponent<CSpriteRenderer>();
	bgSr->SetSize(math::Vector2(3.0f, 3.0f));
	graphcis::CTexture* bgTexture = CResources::Find<graphcis::CTexture>(L"Map");
	bgSr->SetTexture(bgTexture);

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
