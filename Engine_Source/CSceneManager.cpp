#include "CSceneManager.h"
#include "DontDestroyOnLoad.h"

namespace ya
{
	map<wstring, CScene*> CSceneManager::m_mapScene = {};
	CScene* CSceneManager::m_ActiveScene = nullptr;
	CScene* CSceneManager::m_DontDestroyOnLoad = nullptr;

	CScene* CSceneManager::LoadScene(const wstring& _strName)
	{
		if (m_ActiveScene)
			m_ActiveScene->OnExit();

		map<wstring, CScene*>::iterator iter
			= m_mapScene.find(_strName);

		if (iter == m_mapScene.end())
			return nullptr;

		m_ActiveScene = iter->second;
		m_ActiveScene->OnEnter();

		return iter->second;
	}

	void CSceneManager::Init()
	{
		m_DontDestroyOnLoad = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
	}

	void CSceneManager::Update()
	{
		m_ActiveScene->Update();
		m_DontDestroyOnLoad->Update();
	}

	void CSceneManager::LateUpdate()
	{
		m_ActiveScene->LateUpdate();
		m_DontDestroyOnLoad->LateUpdate();
	}

	void CSceneManager::Render(HDC _hDC)
	{
		m_ActiveScene->Render(_hDC);
		m_DontDestroyOnLoad->Render(_hDC);
	}

	void CSceneManager::Destroy()
	{
		m_ActiveScene->Destroy();
		m_DontDestroyOnLoad->Destroy();
	}

	void CSceneManager::Release()
	{
		for (auto& iter : m_mapScene)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
}