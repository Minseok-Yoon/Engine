#pragma once
#include "CCollider.h"

namespace ya
{
	class CBoxCollider2D : public CCollider
	{
	public:
		CBoxCollider2D();
		virtual ~CBoxCollider2D();

	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hDC);
	};
}