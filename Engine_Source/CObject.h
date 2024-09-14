#pragma once
#include "CComponent.h"
#include "CGameObject.h"
#include "CLayer.h"
#include "CSceneManager.h"
#include "CTransform.h"

namespace ya::object
{
	template <typename T>
	static T* Instantiate(enums::LAYER_TYPE _eLayerType)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(_eLayerType);
		CScene* activeScene = CSceneManager::GetActiveScene();
		CLayer* layer = activeScene->GetLayer(_eLayerType);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(enums::LAYER_TYPE _eLayerType, math::Vector2 _position)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(_eLayerType);
		CScene* activeScene = CSceneManager::GetActiveScene();
		CLayer* layer = activeScene->GetLayer(_eLayerType);
		layer->AddGameObject(gameObject);

		CTransform* tr = gameObject->GetComponent<CTransform>();
		tr->SetPosition(_position);

		return gameObject;
	}

	static void DontDestroyOnLoad(CGameObject* _gameObj)
	{
		CScene* activeScene = CSceneManager::GetActiveScene();
		// ��������� ���� ������Ʈ�� �����ش�.
		activeScene->EraseGameObject(_gameObj);

		// �ش� ���ӿ�����Ʈ�� -> DontDestroy������ �־��ش�.
		CScene* dontDestroyOnLoad = CSceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(_gameObj, _gameObj->GetLayerType());
	}
}