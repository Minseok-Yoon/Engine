#include "CSceneManager.h"

namespace ya
{
	map<wstring, CScene*> CSceneManager::m_Scene = {};
	CScene* CSceneManager::m_ActiveScene = nullptr;

	void CSceneManager::Init()
	{
	}

	void CSceneManager::Update()
	{
		m_ActiveScene->Update();
	}

	void CSceneManager::LateUpdate()
	{
		m_ActiveScene->LateUpdate();
	}

	void CSceneManager::Render(HDC _hDC)
	{
		m_ActiveScene->Render(_hDC);
	}
}