#pragma once
#include "../Engine_Source/CSceneManager.h"

#include "CPlayScene.h"
#include "CTitleScene.h"

namespace ya
{
	void LoadScenes()
	{
		CSceneManager::CreateScene<CPlayScene>(L"PlayScene");
		CSceneManager::CreateScene<CTitleScene>(L"TitleScene");
		CSceneManager::CreateScene<CPlayScene>(L"EndScene");

		CSceneManager::LoadScene(L"PlayScene");
	}
}

