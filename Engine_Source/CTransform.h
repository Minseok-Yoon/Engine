#pragma once
#include "CEntity.h"
#include "CComponent.h"

namespace ya
{
	class CTransform : public CComponent
	{
	public:
		CTransform();
		virtual ~CTransform();

	private:
		math::Vector2	m_vPosition;

	public:
		void SetPosition(math::Vector2 _vPos) { m_vPosition.x = _vPos.x; m_vPosition.y = _vPos.y; }
		math::Vector2 GetPosition() { return m_vPosition; }

	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC _hDC) override;
	};
}