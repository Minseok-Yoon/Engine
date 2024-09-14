#pragma once
#include "CResource.h"

namespace ya::graphics
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
		bool			m_bAlpha;
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
		
		void SetWidth(UINT _iWidth) { m_iWidth = _iWidth; }
		UINT GetWidth() { return m_iWidth; }
		void SetHeight(UINT _iHeight) { m_iHeight = _iHeight; }
		UINT GetHeight() { return m_iHeight; }

		virtual HRESULT Load(const wstring& _strPath) override;
		static CTexture* Create(const wstring& _strName, UINT _iWidth, UINT _iHeight);
	};
}