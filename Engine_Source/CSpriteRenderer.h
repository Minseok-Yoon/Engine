#pragma once
#include "CEntity.h"
#include "CComponenet.h"

namespace ya
{
	class CSpriteRenderer : public CComponenet
	{
	public:
		CSpriteRenderer();
		virtual ~CSpriteRenderer();

	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC _hDC) override;
	};
}