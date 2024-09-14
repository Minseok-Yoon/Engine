#include "CScene.h"

namespace ya
{
	CScene::CScene() :
		m_vecLayers{}
	{
		createLayers();
	}

	CScene::~CScene()
	{
		for (CLayer* layer : m_vecLayers)
		{
			delete layer;
			layer = nullptr;
		}
	}

	void CScene::Init()
	{
		for (CLayer* _pLayer : m_vecLayers)
		{
			if (_pLayer == nullptr)
				continue;

			_pLayer->Init();
		}
	}

	void CScene::Update()
	{
		for (CLayer* _pLayer : m_vecLayers)
		{
			if (_pLayer == nullptr)
				continue;

			_pLayer->Update();
		}
	}

	void CScene::LateUpdate()
	{
		for (CLayer* _pLayer : m_vecLayers)
		{
			if (_pLayer == nullptr)
				continue;

			_pLayer->LateUpdate();
		}
	}

	void CScene::Render(HDC _hDC)
	{
		for (CLayer* _pLayer : m_vecLayers)
		{
			if (_pLayer == nullptr)
				continue;

			_pLayer->Render(_hDC);
		}
	}

	void CScene::Destroy()
	{
		for (CLayer* layer : m_vecLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Destroy();
		}
	}

	void CScene::OnEnter()
	{
	}

	void CScene::OnExit()
	{
	}

	void CScene::AddGameObject(CGameObject* _pGameObj, const enums::LAYER_TYPE _eLayerType)
	{
		m_vecLayers[(UINT)_eLayerType]->AddGameObject(_pGameObj);
	}

	void CScene::EraseGameObject(CGameObject* _pGameObj)
	{
		LAYER_TYPE layerType = _pGameObj->GetLayerType();
		m_vecLayers[(UINT)layerType]->EraseGameObject(_pGameObj);
	}

	void CScene::createLayers()
	{
		m_vecLayers.resize((UINT)enums::LAYER_TYPE::Max);
		for (size_t i = 0; i < (UINT)enums::LAYER_TYPE::Max; i++)
		{
			m_vecLayers[i] = new CLayer();
		}
	}
}