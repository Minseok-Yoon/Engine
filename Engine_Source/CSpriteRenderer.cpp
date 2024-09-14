#include "CSpriteRenderer.h"
#include "CTransform.h"
#include "CGameObject.h"
#include "CTexture.h"
#include "CRenderer.h"

namespace ya
{
	CSpriteRenderer::CSpriteRenderer() :
		CComponent(enums::COMPONENT_TYPE::Script),
		m_pTexture(nullptr),
		m_vSize(math::Vector2::One)
	{
	}

	CSpriteRenderer::~CSpriteRenderer()
	{
	}

	void CSpriteRenderer::Init()
	{
	}

	void CSpriteRenderer::Update()
	{
	}

	void CSpriteRenderer::LateUpdate()
	{
	}

	void CSpriteRenderer::Render(HDC _hDC)
	{
		if (m_pTexture == nullptr)
			assert(false);

		CTransform* tr = GetOwner()->GetComponent<CTransform>();
		math::Vector2 vPos = tr->GetPosition();
		float rot = tr->GetRotation();
		math::Vector2 vScale = tr->GetScale();
		vPos = renderer::mainCamera->CaluatePosition(vPos);

#pragma region
		/*
		Gdiplus::Graphics graphics(_hDC);
		graphics.DrawImage(m_pImage, Gdiplus::Rect(pos.x, pos.y, m_iWidth, m_iHeight));*/
#pragma endregion
		if (m_pTexture->GetTextureType() == graphics::CTexture::TEXTURE_TYPE::Bmp)
		{
			TransparentBlt(_hDC, vPos.x, vPos.y,
				m_pTexture->GetWidth() * m_vSize.x * vScale.x,
				m_pTexture->GetHeight() * m_vSize.y * vScale.y,
				m_pTexture->GetHdc(), 0, 0,
				m_pTexture->GetWidth(),
				m_pTexture->GetHeight(),
				RGB(255, 0, 255));
		}
		else if (m_pTexture->GetTextureType() == graphics::CTexture::TEXTURE_TYPE::Png)
		{
			// 투명화 시킬 픽셀의 색 범위 
#pragma region
			/*Gdiplus::Graphics graphics(_hDC);
			graphics.DrawImage(m_pTexture->GetImage(), Gdiplus::Rect(pos.x, pos.y,
				m_pTexture->GetWidth() * m_vSize.x, m_pTexture->GetHeight() * m_vSize.y));*/
#pragma endregion
			Gdiplus::ImageAttributes imgAtt = {};
			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));
			
			Gdiplus::Graphics graphics(_hDC);
			graphics.TranslateTransform(vPos.x, vPos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-vPos.x, -vPos.y);
			graphics.DrawImage(m_pTexture->GetImage(),
				Gdiplus::Rect(
					vPos.x, vPos.y,
					m_pTexture->GetWidth() * m_vSize.x * vScale.x,
					m_pTexture->GetHeight() * m_vSize.y * vScale.y),
				0, 0,
				m_pTexture->GetWidth(), m_pTexture->GetHeight(),
				Gdiplus::UnitPixel,
				nullptr);
		}
	}
}
