#include "CGameObject.h"
#include "CInput.h"
#include "CTime.h"
#include "CTransform.h"

namespace ya
{
	CGameObject::CGameObject() :
		m_eState(STATE::Active),
		m_eLayerType(LAYER_TYPE::None)
	{
		m_vecComponents.resize((UINT)enums::COMPONENT_TYPE::End);
		initializeTransform();
	}

	CGameObject::~CGameObject()
	{
	}

	void CGameObject::Init()
	{
		for (CComponent* comp : m_vecComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Init();
		}
	}

	void CGameObject::Update()
	{
		for (CComponent* comp : m_vecComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Update();
		}
	}

	void CGameObject::LateUpdate()
	{
		for (CComponent* comp : m_vecComponents)
		{
			if (comp == nullptr)
				continue;

			comp->LateUpdate();
		}
	}

	void CGameObject::Render(HDC _hDC)
	{
		for (CComponent* comp : m_vecComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Render(_hDC);
		}
	}
	void CGameObject::initializeTransform()
	{
		AddComponent<CTransform>();
	}
}