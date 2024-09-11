#pragma once
#include "../Engine_Source/CGameObject.h"

namespace ya
{
	class CPlayer : public CGameObject
	{
	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hDC);
	};
}