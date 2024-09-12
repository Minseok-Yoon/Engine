#pragma once
#include "CComponent.h"
#include "CAnimation.h"

namespace ya
{
	class CAnimator : public CComponent
	{
	public:
		CAnimator();
		virtual ~CAnimator();

	private:
		map<wstring, CAnimation*> m_mapAnimations;
		CAnimation* m_pActiveAnimation;
		bool	m_bLoop;

	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hDC);

		void CreateAnimation(const wstring& _strName,
			graphcis::CTexture* _pSpriteSheet,
			math::Vector2 _vLeftTop,
			math::Vector2 _vSize,
			math::Vector2 _vOffset,
			UINT _iSpriteLength,
			float _fDuration);

		CAnimation* FindAnimation(const wstring& _strName);
		void PlayAnimation(const wstring& _strName, bool _bLoop = true);
	};
}