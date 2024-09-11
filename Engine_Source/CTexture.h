#pragma once
#include "CResource.h"

namespace ya::graphcis
{
	class CTexture : public CResource
	{
	public:
		enum class TEXTURE_TYPE
		{
			Bmp,
			Png,
			None,
		};

		CTexture();
		~CTexture();

	private:
		TEXTURE_TYPE	m_eTextureType;
		Gdiplus::Image* m_pImage;
		HBITMAP			m_hBitamp;
		HDC				m_hDC;

		UINT			m_iWidth;
		UINT			m_iHeight;

	public:
		TEXTURE_TYPE GetTextureType() { return m_eTextureType; }
		Gdiplus::Image* GetImage() { return m_pImage; }
		HDC GetHdc() { return m_hDC; }
		
		UINT GetWidth() { return m_iWidth; }
		UINT GetHeight() { return m_iHeight; }

		virtual HRESULT Load(const wstring& _strPath) override;
	};
}