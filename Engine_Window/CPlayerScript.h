#pragma once
#include "../Engine_Source/CScript.h"

namespace ya
{
	class CPlayerScript : public CScript
	{
	public:
		enum class PLAYER_STATE
		{
			NONE,
			END,
		};

		CPlayerScript();
		virtual ~CPlayerScript();

	private:
		PLAYER_STATE	m_ePlayerState;
		class CAnimator* m_pAnimator;

	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC _hDC) override;
	};
}