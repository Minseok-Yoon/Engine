#pragma once
#include "CResource.h"
#include "CTexture.h"

namespace ya
{
	class CAnimation : public CResource
	{
	public:
		struct Sprite
		{
			math::Vector2	vLeftTop;
			math::Vector2	vSize;
			math::Vector2	vOffset;
			float			fDuration;

			Sprite() :
				vLeftTop(math::Vector2::Zero),
				vSize(math::Vector2::Zero),
				vOffset(math::Vector2::Zero),
				fDuration(0.0f)
			{}
		};

		CAnimation();
		virtual ~CAnimation();

	private:
		class CAnimator* m_pAnimator;
		graphcis::CTexture* m_pTexture;

		vector<Sprite> m_vecAnimationSheet;
		int	m_iIndex;
		float	m_fTime;
		bool	m_bComplete;

	public:
		void SetAnimator(class CAnimator* _pAnimator) { m_pAnimator = _pAnimator; }
		bool IsComplete() { return m_bComplete; }

		void Update();
		void Render(HDC _hDC);

		HRESULT Load(const wstring& _strPath) override;

		void CreateAnimation(const wstring& _strName,
			graphcis::CTexture* _pSpriteSheet,
			math::Vector2 _vLeftTop,
			math::Vector2 _vSize,
			math::Vector2 _vOffset,
			UINT _iSpriteLength,
			float _fDuratioin);
		void Reset();
	};
}