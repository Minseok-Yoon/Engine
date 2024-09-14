#include "CTexture.h"
#include "CApplication.h"
#include "CResources.h"

// 해당 전역변수가 존재함을 알리는 키워드 extern
extern ya::CApplication application;

namespace ya::graphics
{
	CTexture::CTexture() :
		CResource(enums::RESOURCE_TYPE::Texture),
		m_bAlpha(false)
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

	CTexture* CTexture::Create(const wstring& _strName, UINT _iWidth, UINT _iHeight)
	{
		CTexture* image = CResources::Find<CTexture>(_strName);
		if (image)
			return image;

		image = new CTexture();
		image->SetName(_strName);
		image->SetWidth(_iWidth);
		image->SetHeight(_iHeight);

		HDC hdc = application.GetHdc();
		HWND hwnd = application.GetHwnd();

		image->m_hBitamp = CreateCompatibleBitmap(hdc, _iWidth, _iHeight);
		image->m_hDC = CreateCompatibleDC(hdc);

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);
		Rectangle(image->m_hDC, -1, -1, image->GetWidth() + 1, image->GetHeight() + 1);
		SelectObject(hdc, oldBrush);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(image->m_hDC, image->m_hBitamp);
		DeleteObject(oldBitmap);

		CResources::Insert(_strName + L"Image", image);

		return image;
	}
}
