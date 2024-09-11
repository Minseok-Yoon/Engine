#include "CTexture.h"
#include "CApplication.h"

// 해당 전역변수가 존재함을 알리는 키워드 extern
extern ya::CApplication application;

namespace ya::graphcis
{
	CTexture::CTexture() :
		CResource(enums::RESOURCE_TYPE::Texture)
	{
	}

	CTexture::~CTexture()
	{
	}

	HRESULT CTexture::Load(const wstring& _strPath)
	{
		wstring ext = _strPath.substr(_strPath.find_last_of(L".") + 1);

		if (ext == L"bmp")
		{
			m_eTextureType = TEXTURE_TYPE::Bmp;
			m_hBitamp = (HBITMAP)LoadImageW(nullptr, _strPath.c_str(), IMAGE_BITMAP,
				0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (m_hBitamp == nullptr)
				return S_FALSE;

			BITMAP info = {};
			GetObject(m_hBitamp, sizeof(BITMAP), &info);

			m_iWidth = info.bmWidth;
			m_iHeight = info.bmHeight;

			HDC mainDC = application.GetHdc();
			m_hDC = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(m_hDC, m_hBitamp);
			DeleteObject(oldBitmap);
		}
		else if (ext == L"png")
		{
			m_eTextureType = TEXTURE_TYPE::Png;
			m_pImage = Gdiplus::Image::FromFile(_strPath.c_str());
			if (m_pImage == nullptr)
				return S_FALSE;

			m_iWidth = m_pImage->GetWidth();
			m_iHeight = m_pImage->GetHeight();
		}
		return S_OK;
	}
}
