#pragma once
#include "../Engine_Source/CScene.h"

namespace ya
{
	class CPlayScene : public CScene
	{
	public:
		CPlayScene();
		virtual ~CPlayScene();

	public:
		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hDC) override;
	};
}