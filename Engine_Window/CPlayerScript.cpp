#include "CPlayerScript.h"
#include "CInput.h"
#include "CTransform.h"
#include "CTime.h"
#include "CGameObject.h"

namespace ya
{
	CPlayerScript::CPlayerScript() :
		m_ePlayerState(PLAYER_STATE::NONE),
		m_pAnimator(nullptr)
	{
	}

	CPlayerScript::~CPlayerScript()
	{
	}

	void CPlayerScript::Init()
	{
	}

	void CPlayerScript::Update()
	{
		if (CInput::GetKey(KEY_CODE::Right))
		{
			CTransform* tr = GetOwner()->GetComponent<CTransform>();
			math::Vector2 vPos = tr->GetPosition();
			vPos.x += 100.0f * CTime::DeltaTime();
			tr->SetPosition(vPos);
		}

		if (CInput::GetKey(KEY_CODE::Left))
		{
			CTransform* tr = GetOwner()->GetComponent<CTransform>();
			math::Vector2 vPos = tr->GetPosition();
			vPos.x -= 100.0f * CTime::DeltaTime();
			tr->SetPosition(vPos);
		}

		if (CInput::GetKey(KEY_CODE::Up))
		{
			CTransform* tr = GetOwner()->GetComponent<CTransform>();
			math::Vector2 vPos = tr->GetPosition();
			vPos.y -= 100.0f * CTime::DeltaTime();
			tr->SetPosition(vPos);
		}

		if (CInput::GetKey(KEY_CODE::Down))
		{
			CTransform* tr = GetOwner()->GetComponent<CTransform>();
			math::Vector2 vPos = tr->GetPosition();
			vPos.y += 100.0f * CTime::DeltaTime();
			tr->SetPosition(vPos);
		}
	}

	void CPlayerScript::LateUpdate()
	{
	}

	void CPlayerScript::Render(HDC _hDC)
	{
	}
}