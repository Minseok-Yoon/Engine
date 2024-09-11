#pragma once
#include "../Engine_Source/CScript.h"

namespace ya
{
	class CPlayerScript : public CScript
	{
	public:
		CPlayerScript();
		virtual ~CPlayerScript();

	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC _hDC) override;
	};
}