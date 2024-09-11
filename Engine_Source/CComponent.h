#pragma once
#include "CEntity.h"

namespace ya
{
	class CGameObject;
	class CComponent : public CEntity
	{
	public:
		CComponent();
		virtual ~CComponent();

	private:
		CGameObject* m_pOwner;

	public:
		void SetOwner(CGameObject* _pOwner) { m_pOwner = _pOwner; }
		CGameObject* GetOwner() { return m_pOwner; }

	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hDC);
	};
}