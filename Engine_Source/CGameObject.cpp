#include "CGameObject.h"
#include "CInput.h"

namespace ya
{
	CGameObject::CGameObject()
	{
	}

	CGameObject::~CGameObject()
	{
	}

	void CGameObject::Init()
	{
		for (CComponenet* comp : m_vecComponents)
		{
			comp->Init();
		}
	}

	void CGameObject::Update()
	{
		for (CComponenet* comp : m_vecComponents)
		{
			comp->Update();
		}
	}

	void CGameObject::LateUpdate()
	{
		for (CComponenet* comp : m_vecComponents)
		{
			comp->LateUpdate();
		}
	}

	void CGameObject::Render(HDC _hDC)
	{
		for (CComponenet* comp : m_vecComponents)
		{
			comp->Render(_hDC);
		}
	}
}