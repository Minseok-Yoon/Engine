#pragma once
#include "CComponent.h"

namespace ya
{
	class CScript : public CComponent
	{
	public:
		CScript();
		virtual ~CScript();

	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC _hDC) override;

		virtual void OnCollisionEnter(class CCollider* _pOther);
		virtual void OnCollisionStay(class CCollider* _pOther);
		virtual void OnCollisionExit(class CCollider* _pOther);
	};
}