#include "CCollider.h"
#include "CGameObject.h"
#include "CScript.h"

namespace ya
{
	UINT CCollider::CollisionID = 1;

	CCollider::CCollider(COLLIDER_TYPE _eColliderType) :
		CComponent(enums::COMPONENT_TYPE::Collider),
		m_eColliderType(_eColliderType),
		m_iID(CollisionID++),
		m_vSize(math::Vector2::One)
	{
	}

	CCollider::~CCollider()
	{
	}

	void CCollider::Init()
	{
	}

	void CCollider::Update()
	{
	}

	void CCollider::LateUpdate()
	{
	}

	void CCollider::Render(HDC _hDC)
	{
	}

	void CCollider::OnCollisionEnter(CCollider* _pOther)
	{
		CScript* script = GetOwner()->GetComponent<CScript>();
		script->OnCollisionEnter(_pOther);
	}

	void CCollider::OnCollisionStay(CCollider* _pOther)
	{
		CScript* script = GetOwner()->GetComponent<CScript>();
		script->OnCollisionStay(_pOther);
	}

	void CCollider::OnCollisionExit(CCollider* _pOther)
	{
		CScript* script = GetOwner()->GetComponent<CScript>();
		script->OnCollisionExit(_pOther);
	}
}