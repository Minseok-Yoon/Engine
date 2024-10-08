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
#include "CAnimator.h"
#include "CBoxCollider2D.h"
#include "CCircleCollider2D.h"
#include "CCollisionManager.h"

ya::CPlayScene::CPlayScene()
{
}

ya::CPlayScene::~CPlayScene()
{
}

void ya::CPlayScene::Init()
{
	CCollisionManager::CollisionLayerCheck(LAYER_TYPE::Player, LAYER_TYPE::Animal, true);
#pragma region
	/*bg = object::Instantiate<CPlayer>(enums::LAYER_TYPE::BackGround, math::Vector2(100.f, 100.f));

	CSpriteRenderer* sr = bg->AddComponent<CSpriteRenderer>();

	graphics::CTexture* bg = CResources::Find<graphics::CTexture>(L"BG");
	sr->SetTexture(bg);*/
#pragma endregion
	// main camera
	CGameObject* camera = object::Instantiate<CGameObject>(enums::LAYER_TYPE::Particle, math::Vector2(344.0f, 442.0f));
	CCamera* cameraComp = camera->AddComponent<CCamera>();
	renderer::mainCamera = cameraComp;
	object::DontDestroyOnLoad(m_pPlayer);

	/*m_pPlayer = object::Instantiate<CPlayer>(enums::LAYER_TYPE::Player);
	//CSpriteRenderer* sr = m_pPlayer->AddComponent<CSpriteRenderer>();
	//sr->SetSize(math::Vector2(3.0f, 3.0f));
	m_pPlayer->AddComponent<CPlayerScript>();

	graphics::CTexture* packmanTexture = CResources::Find<graphics::CTexture>(L"PackMan");
	sr->SetTexture(packmanTexture);

	// Animator
	graphics::CTexture* packmanTexture = Resources::Find<graphics::CTexture>(L"Cat");
	CAnimator* animator = m_pPlayer->AddComponent<CAnimator>();
	animator->CreateAnimation(L"CatFrontMove", packmanTexture
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.5f);

	animator->PlayAnimation(L"CatFrontMove", true);

	CGameObject* bg = object::Instantiate<CGameObject>(enums::LAYER_TYPE::BackGround);
	CSpriteRenderer* bgSr = bg->AddComponent<CSpriteRenderer>();
	bgSr->SetSize(math::Vector2(3.0f, 3.0f));
	graphics::CTexture* bgTexture = CResources::Find<graphics::CTexture>(L"Map");
	bgSr->SetTexture(bgTexture);*/

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

void ya::CPlayScene::OnEnter()
{
	CScene::OnEnter();
}

void ya::CPlayScene::OnExit()
{
	CScene::OnExit();
}
