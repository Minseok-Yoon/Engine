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
		math::Vector2	m_vScale;
		float			m_fRotation;

	public:
		void SetPosition(math::Vector2 _vPos) { m_vPosition.x = _vPos.x; m_vPosition.y = _vPos.y; }
		math::Vector2 GetPosition() { return m_vPosition; }

		void SetScale(math::Vector2 _vScale) { m_vScale = _vScale; }
		math::Vector2 GetScale() { return m_vScale; }

		void SetRotation(float _fRotate) { m_fRotation = _fRotate; }
		float GetRotation() { return m_fRotation; }

	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC _hDC) override;
	};
}