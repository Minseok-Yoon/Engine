#include "CGameObject.h"
#include "CInput.h"
#include "CTime.h"
#include "CTransform.h"

namespace ya
{
	CGameObject::CGameObject()
	{
		initializeTransform();
	}

	CGameObject::~CGameObject()
	{
	}

	void CGameObject::Init()
	{
		for (CComponent* comp : m_vecComponents)
		{
			comp->Init();
		}
	}

	void CGameObject::Update()
	{
		for (CComponent* comp : m_vecComponents)
		{
			comp->Update();
		}
	}

	void CGameObject::LateUpdate()
	{
		for (CComponent* comp : m_vecComponents)
		{
			comp->LateUpdate();
		}
	}

	void CGameObject::Render(HDC _hDC)
	{
		for (CComponent* comp : m_vecComponents)
		{
			comp->Render(_hDC);
		}
	}
	void CGameObject::initializeTransform()
	{
		AddComponent<CTransform>();
	}
}