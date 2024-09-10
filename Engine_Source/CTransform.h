#pragma once
#include "CEntity.h"
#include "CComponenet.h"

namespace ya
{
	class CTransform : public CComponenet
	{
	public:
		CTransform();
		virtual ~CTransform();

	public:
		virtual void Init() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC _hDC) override;
	};
}