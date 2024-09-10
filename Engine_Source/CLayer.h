#pragma once
#include "CEntity.h"
#include "CommonInclude.h"
#include "CGameObject.h"

namespace ya
{
	class CLayer : public CEntity
	{
	public:
		CLayer();
		virtual ~CLayer();

	private:
		vector<CGameObject*> m_vecGameObjects;

	public:
		void AddGameObject(CGameObject* _pGameObject);

	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hDC);
	};
}