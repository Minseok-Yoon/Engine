#pragma once
#include "CCollider.h"

namespace ya
{
	class CCircleCollider2D : public CCollider
	{
	public:
		CCircleCollider2D();
		virtual ~CCircleCollider2D();

	private:
		float m_fRadius;
		
	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hDC);
	};
}