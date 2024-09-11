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
			m_ActiveScene = scene;
			scene->Init();

			m_Scene.insert(make_pair(_strName, scene));

			return scene;
		}

		static CScene* LoadScene(const wstring& _strName);

	private:
		static map<wstring, CScene*> m_Scene;
		static CScene* m_ActiveScene;

	public:
		static CScene* GetActiveScene() { return m_ActiveScene; }

	public:
		static void Init();
		static void Update();
		static void LateUpdate();
		static void Render(HDC _hDC);
	};
}