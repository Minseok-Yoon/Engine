#pragma once
#include "CComponent.h"

namespace ya
{
	class CCamera : public CComponent
	{
	public:
		CCamera();
		virtual ~CCamera();

	private:
		class CGameObject* m_pTarget;
		math::Vector2 m_vDistance;
		math::Vector2 m_vResolution;
		math::Vector2 m_vLookPosition;

	public:
		math::Vector2 CaluatePosition(math::Vector2 _vPos) { return _vPos - m_vDistance; }

	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hDC);
	};
}