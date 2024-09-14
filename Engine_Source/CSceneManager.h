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

			m_mapScene.insert(make_pair(_strName, scene));

			return scene;
		}

	private:
		static map<wstring, CScene*> m_mapScene;
		static CScene* m_ActiveScene;
		static CScene* m_DontDestroyOnLoad;

	public:
		static CScene* LoadScene(const wstring& _strName);
		static CScene* GetActiveScene() { return m_ActiveScene; }
		static CScene* GetDontDestroyOnLoad() { return m_DontDestroyOnLoad; }

	public:
		static void Init();
		static void Update();
		static void LateUpdate();
		static void Render(HDC _hDC);
		static void Destroy();
		static void Release();
	};
}