#pragma once
#include "CComponent.h"

namespace ya
{
	class CCollider : public CComponent
	{
	public:
		CCollider(COLLIDER_TYPE _eColliderType);
		virtual ~CCollider();

	private:
		static UINT CollisionID;
		UINT32 m_iID;
		math::Vector2	m_vOffset;
		math::Vector2	m_vSize;

		COLLIDER_TYPE	m_eColliderType;

	public:
		UINT32 GetID() { return m_iID; }
		void SetOffset(math::Vector2 _vOffset) { m_vOffset = _vOffset; }
		math::Vector2 GetOffset() { return m_vOffset; }

		void SetSize(math::Vector2 _vSize) { m_vSize = _vSize; }
		math::Vector2 GetSize() { return m_vSize; }

		COLLIDER_TYPE GetColliderType() { return m_eColliderType; }

	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hDC);

		virtual void OnCollisionEnter(CCollider* _pOther);
		virtual void OnCollisionStay(CCollider* _pOther);
		virtual void OnCollisionExit(CCollider* _pOther);
	};
}