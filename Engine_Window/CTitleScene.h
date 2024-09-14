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
		virtual void Init() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC _hDC) override;

		virtual void OnEnter() override;
		virtual void OnExit() override;
	};
}