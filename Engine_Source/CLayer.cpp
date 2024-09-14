#include "CLayer.h"

namespace ya
{
	CLayer::CLayer() :
		m_vecGameObjects{}
	{
	}

	CLayer::~CLayer()
	{
		for (CGameObject* gameObj : m_vecGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			delete gameObj;
			gameObj = nullptr;
		}
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

			if(_pGameObject->IsActive() == false)
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

			if (_pGameObject->IsActive() == false)
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

			if (_pGameObject->IsActive() == false)
				continue;

			_pGameObject->Render(_hDC);
		}
	}
	void CLayer::Destroy()
	{
		vector<CGameObject*> deleteObjects = {};
		findDeadGameObjects(deleteObjects);
		eraseGameObject();
		deleteGameObjects(deleteObjects);
	}

	void CLayer::findDeadGameObjects(OUT vector<CGameObject*>& _pGameObjects)
	{
		for (CGameObject* _gameObj : m_vecGameObjects)
		{
			CGameObject::STATE active = _gameObj->GetState();
			if (active == CGameObject::STATE::Dead)
				_pGameObjects.push_back(_gameObj);
		}
	}

	void CLayer::deleteGameObjects(vector<CGameObject*> _vecDeleteObjects)
	{
		for (CGameObject* _obj : _vecDeleteObjects)
		{
			delete _obj;
			_obj = nullptr;
		}
	}

	void CLayer::eraseGameObject()
	{
		erase_if(m_vecGameObjects,
			[](CGameObject* _gameObj)
		{
			return (_gameObj)->IsDead();
		});
	}
}