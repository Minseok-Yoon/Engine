#pragma once
#include "CEntity.h"

namespace ya
{
	using namespace enums;

	class CGameObject;
	class CComponent : public CEntity
	{
	public:
		CComponent(enums::COMPONENT_TYPE _eComponentType);
		virtual ~CComponent();

	private:
		CGameObject* m_pOwner;
		enums::COMPONENT_TYPE m_eComponentType;

	public:
		void SetOwner(CGameObject* _pOwner) { m_pOwner = _pOwner; }
		CGameObject* GetOwner() { return m_pOwner; }
		enums::COMPONENT_TYPE GetComponentType() { return m_eComponentType; }

	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hDC);
	};
}