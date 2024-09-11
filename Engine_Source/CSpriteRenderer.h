#pragma once
#include "CEntity.h"
#include "CComponent.h"
#include "CTexture.h"

namespace ya
{
	class CSpriteRenderer : public CComponent
	{
	public:
		CSpriteRenderer();
		virtual ~CSpriteRenderer();

	private:
		graphcis::CTexture* m_pTexture;
		math::Vector2 m_vSize;

	public:
		void SetTexture(graphcis::CTexture* _pTexture) { m_pTexture = _pTexture; }
		void SetSize(math::Vector2 _vSize) { m_vSize = _vSize; }

	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC _hDC) override;
	};
}