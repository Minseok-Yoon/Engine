#pragma once
#include "CEntity.h"
#include "CGameObject.h"
#include "CLayer.h"

namespace ya
{
	class CScene : public CEntity
	{
	public:
		CScene();
		virtual ~CScene();

	private:
		vector<CLayer*>	m_vecLayers;

	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hDC);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(CGameObject* _pGameObj, const enums::LAYER_TYPE _eLayerType);
		CLayer* GetLayer(const enums::LAYER_TYPE _eLayerType) { return m_vecLayers[(UINT)_eLayerType]; }

	private:
		void createLayers();
	};
}