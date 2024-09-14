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
		const vector<CGameObject*> GetGameObjects() { return m_vecGameObjects; }

	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hDC);
		virtual void Destroy();

	private:
		void findDeadGameObjects(OUT vector<CGameObject*>& _pGameObjects);
		void deleteGameObjects(vector<CGameObject*> _vecGameObjects);
		void eraseGameObject();
	};
	typedef vector<CGameObject*>::iterator GameObjectIter;
}