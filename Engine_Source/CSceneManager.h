#pragma once
#include "CScene.h"

namespace ya
{
	class CSceneManager
	{
	public:
		template <typename T>
		static CScene* CreateScene(const wstring& _strName)
		{
			T* scene = new T();
			scene->SetName(_strName);
			scene->Init();

			m_Scene.insert(make_pair(_strName, scene));

			return scene;
		}

		static CScene* LoadScene(const wstring& _strName)
		{
			if (m_ActiveScene)
				m_ActiveScene->OnExit();

			map<wstring, CScene*>::iterator iter
				= m_Scene.find(_strName);

			if (iter == m_Scene.end())
				return nullptr;

			m_ActiveScene = iter->second;
			m_ActiveScene->OnEnter();

			return iter->second;
		}

	private:
		static map<wstring, CScene*> m_Scene;
		static CScene* m_ActiveScene;

	public:
		static void Init();
		static void Update();
		static void LateUpdate();
		static void Render(HDC _hDC);
	};
}