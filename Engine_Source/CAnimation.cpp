#include "CAnimation.h"
#include "CTime.h"
#include "CGameObject.h"
#include "CTransform.h"
#include "CRenderer.h"
#include "CCamera.h"

namespace ya
{
	CAnimation::CAnimation() :
		CResource(enums::RESOURCE_TYPE::Animation),
		m_pAnimator(nullptr),
		m_pTexture(nullptr),
		m_vecAnimationSheet{},
		m_iIndex(-1),
		m_fTime(0.0f),
		m_bComplete(false)
	{
	}

	CAnimation::~CAnimation()
	{
	}

	void CAnimation::Update()
	{
		if (m_bComplete)
			return;

		m_fTime += CTime::DeltaTime();

		if (m_vecAnimationSheet[m_iIndex].fDuration < m_fTime)
		{
			m_fTime = 0.0f;
			if (m_iIndex < m_vecAnimationSheet.size() - 1)
				m_iIndex++;
			else
				m_bComplete = true;
		}
	}

	void CAnimation::Render(HDC _hDC)
	{
		if (m_pTexture == nullptr)
			return;

		CGameObject* gameObj = m_pAnimator->GetOwner();
		CTransform* tr = gameObj->GetComponent<CTransform>();
		math::Vector2 vPos = tr->GetPosition();

		if (renderer::mainCamera)
			vPos = renderer::mainCamera->CaluatePosition(vPos);

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 125; // 0(transparent) ~ 255(Opaque)

		Sprite sprite = m_vecAnimationSheet[m_iIndex];
		HDC imgHdc = m_pTexture->GetHdc();

		AlphaBlend(_hDC,
			vPos.x, vPos.y,
			sprite.vSize.x * 5,
			sprite.vSize.y * 5,
			imgHdc,
			sprite.vLeftTop.x,
			sprite.vLeftTop.y,
			sprite.vSize.x,
			sprite.vSize.y,
			func);
	}

	HRESULT CAnimation::Load(const wstring& _strPath)
	{
		return E_NOTIMPL;
	}

	void CAnimation::CreateAnimation(const wstring& _strName, graphcis::CTexture* _pSpriteSheet, math::Vector2 _vLeftTop, 
		math::Vector2 _vSize, math::Vector2 _vOffset, UINT _iSpriteLength, float _fDuratioin)
	{
		m_pTexture = _pSpriteSheet;
		for (size_t i = 0; i < _iSpriteLength; i++)
		{
			Sprite sprite = {};
			sprite.vLeftTop.x = _vLeftTop.x + (_vSize.x * i);
			sprite.vLeftTop.y = _vLeftTop.y + (_vSize.y * i);
			sprite.vSize = _vSize;
			sprite.vOffset = _vOffset;
			sprite.fDuration = _fDuratioin;

			m_vecAnimationSheet.push_back(sprite);
		}
	}

	void CAnimation::Reset()
	{
		m_fTime = 0.0f;
		m_iIndex = 0;
		m_bComplete = false;
	}
}