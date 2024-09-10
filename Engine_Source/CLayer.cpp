#include "CLayer.h"

namespace ya
{
	CLayer::CLayer() :
		m_vecGameObjects{}
	{
	}

	CLayer::~CLayer()
	{
	}

	void CLayer::AddGameObject(CGameObject* _pGameObject)
	{
		if (_pGameObject == nullptr)
			return;

		m_vecGameObjects.push_back(_pGameObject);
	}

	void CLayer::Init()
	{
		for (CGameObject* _pGameObject : m_vecGameObjects)
		{
			if (_pGameObject == nullptr)
				continue;

			_pGameObject->Init();
		}
	}

	void CLayer::Update()
	{
		for (CGameObject* _pGameObject : m_vecGameObjects)
		{
			if (_pGameObject == nullptr)
				continue;

			_pGameObject->Update();
		}
	}

	void CLayer::LateUpdate()
	{
		for (CGameObject* _pGameObject : m_vecGameObjects)
		{
			if (_pGameObject == nullptr)
				continue;

			_pGameObject->LateUpdate();
		}
	}

	void CLayer::Render(HDC _hDC)
	{
		for (CGameObject* _pGameObject : m_vecGameObjects)
		{
			if (_pGameObject == nullptr)
				continue;

			_pGameObject->Render(_hDC);
		}
	}
}