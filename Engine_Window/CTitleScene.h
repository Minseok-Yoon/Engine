#pragma once
#include "../Engine_Source/CScene.h"

namespace ya
{
	class CTitleScene : public CScene
	{
	public:
		CTitleScene();
		virtual ~CTitleScene();

	public:
		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC _hDC) override;
	};
}