#include "CAnimation.h"
#include "CAnimator.h"
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
		float rot = tr->GetRotation();
		math::Vector2 vScale = tr->GetScale();

		if (renderer::mainCamera)
			vPos = renderer::mainCamera->CaluatePosition(vPos);
#pragma region
		/*BLENDFUNCTION func = {};
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
			func);*/
#pragma endregion

		Sprite sprite = m_vecAnimationSheet[m_iIndex];
		graphics::CTexture::TEXTURE_TYPE _eTextureType = m_pTexture->GetTextureType();
		if (_eTextureType == graphics::CTexture::TEXTURE_TYPE::Bmp)
		{
			//BLENDFUNCTION func = {};
			//func.BlendOp = AC_SRC_OVER;
			//func.BlendFlags = 0;
			//func.AlphaFormat = AC_SRC_ALPHA;
			//func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)


			HDC imgHdc = m_pTexture->GetHdc();

			/*AlphaBlend(_hDC,
				vPos.x - (sprite.vSize.x / 2.0f), 
				vPos.y - (sprite.vSize.y / 2.0f),
				sprite.vSize.x * vScale.x,
				sprite.vSize.y * vScale.y,
				imgHdc,
				sprite.vLeftTop.x,
				sprite.vLeftTop.y,
				sprite.vSize.x,
				sprite.vSize.y,
				func);*/

			if (m_pTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255;

				AlphaBlend(_hDC,
					vPos.x - (sprite.vSize.x / 2.0f) + sprite.vOffset.x,
					vPos.y - (sprite.vSize.y / 2.0f) + sprite.vOffset.y,
					sprite.vSize.x * vScale.x,
					sprite.vSize.y * vScale.y,
					imgHdc,
					sprite.vLeftTop.x,
					sprite.vLeftTop.y,
					sprite.vSize.x,
					sprite.vSize.y,
					func);
			}
			else
			{
				TransparentBlt(_hDC,
					vPos.x - (sprite.vSize.x / 2.0f) + sprite.vOffset.x,
					vPos.y - (sprite.vSize.y / 2.0f) + sprite.vOffset.y,
					sprite.vSize.x * vScale.x,
					sprite.vSize.y * vScale.y,
					imgHdc,
					sprite.vLeftTop.x,
					sprite.vLeftTop.y,
					sprite.vSize.x,
					sprite.vSize.y,
					RGB(255, 0, 255));
			}
			Rectangle(_hDC, vPos.x, vPos.y, vPos.x + 10, vPos.y + 10);
		}
		else if (_eTextureType == graphics::CTexture::TEXTURE_TYPE::Png)
		{
			// 내가 원하는 픽셀을 투명화 시킬 때
			Gdiplus::ImageAttributes imgAtt = {};

			// 투명화 시킬 픽셀의 색 범위
			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(_hDC);

			graphics.TranslateTransform(vPos.x, vPos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-vPos.x, -vPos.y);

			graphics.DrawImage(m_pTexture->GetImage(),
				Gdiplus::Rect
				(
					vPos.x - (sprite.vSize.x / 2.0f),
					vPos.y - (sprite.vSize.y / 2.0f),
					sprite.vSize.x * vScale.x,
					sprite.vSize.y * vScale.y),
				sprite.vLeftTop.x,
				sprite.vLeftTop.y,
				sprite.vSize.x,
				sprite.vSize.y,
				Gdiplus::UnitPixel,
				nullptr);
		}
	}

	HRESULT CAnimation::Load(const wstring& _strPath)
	{
		return E_NOTIMPL;
	}

	void CAnimation::CreateAnimation(const wstring& _strName, graphics::CTexture* _pSpriteSheet, math::Vector2 _vLeftTop, 
		math::Vector2 _vSize, math::Vector2 _vOffset, UINT _iSpriteLength, float _fDuratioin)
	{
		m_pTexture = _pSpriteSheet;
		for (size_t i = 0; i < _iSpriteLength; i++)
		{
			Sprite sprite = {};
			sprite.vLeftTop.x = _vLeftTop.x + (_vSize.x * i);
			sprite.vLeftTop.y = _vLeftTop.y;
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