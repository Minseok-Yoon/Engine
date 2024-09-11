#pragma once
#include "CComponent.h"

namespace ya
{
	class CScript : public CComponent
	{
	public:
		CScript();
		virtual ~CScript();

	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC _hDC) override;
	};
}