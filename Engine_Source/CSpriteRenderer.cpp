#include "CSpriteRenderer.h"
#include "CTransform.h"
#include "CGameObject.h"
#include "CTexture.h"

namespace ya
{
	CSpriteRenderer::CSpriteRenderer() :
		CComponent(),
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
		math::Vector2 pos = tr->GetPosition();

#pragma region
		/*
		Gdiplus::Graphics graphcis(_hDC);
		graphcis.DrawImage(m_pImage, Gdiplus::Rect(pos.x, pos.y, m_iWidth, m_iHeight));*/
#pragma endregion
		if (m_pTexture->GetTextureType() == graphcis::CTexture::TEXTURE_TYPE::Bmp)
		{
			TransparentBlt(_hDC, pos.x, pos.y,
				m_pTexture->GetWidth() * m_vSize.x,
				m_pTexture->GetHeight() * m_vSize.y,
				m_pTexture->GetHdc(), 0, 0,
				m_pTexture->GetWidth(),
				m_pTexture->GetHeight(),
				RGB(255, 0, 255));
		}
		else if (m_pTexture->GetTextureType() == graphcis::CTexture::TEXTURE_TYPE::Png)
		{
			Gdiplus::Graphics graphcis(_hDC);
			graphcis.DrawImage(m_pTexture->GetImage(), Gdiplus::Rect(pos.x, pos.y,
				m_pTexture->GetWidth() * m_vSize.x, m_pTexture->GetHeight() * m_vSize.y));
		}
	}
}
