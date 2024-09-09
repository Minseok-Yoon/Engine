#pragma once
#include "CommonInclude.h"

namespace ya
{
	class CGameObject
	{
	public:
		CGameObject();
		~CGameObject();

	private:

	public:
		void Update();
		void LateUpdate();
		void Render(HDC _hDC);
	};
}