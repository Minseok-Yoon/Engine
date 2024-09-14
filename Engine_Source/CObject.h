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
		// 현재씬에서 게임 오브젝트를 지워준다.
		activeScene->EraseGameObject(_gameObj);

		// 해당 게임오브젝트를 -> DontDestroy씬으로 넣어준다.
		CScene* dontDestroyOnLoad = CSceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(_gameObj, _gameObj->GetLayerType());
	}
}