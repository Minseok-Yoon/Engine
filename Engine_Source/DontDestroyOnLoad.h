#pragma once
#include "CScene.h"

namespace ya
{
	class DontDestroyOnLoad : public CScene
	{
	public:
		DontDestroyOnLoad();
		virtual ~DontDestroyOnLoad();

	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC _hDC) override;

		virtual void OnEnter() override;
		virtual void OnExit() override;
	};
}