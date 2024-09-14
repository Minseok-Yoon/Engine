#include "DontDestroyOnLoad.h"

namespace ya
{
	DontDestroyOnLoad::DontDestroyOnLoad()
	{
	}

	DontDestroyOnLoad::~DontDestroyOnLoad()
	{
	}

	void DontDestroyOnLoad::Init()
	{
		CScene::Init();
	}

	void DontDestroyOnLoad::Update()
	{
		CScene::Update();
	}

	void DontDestroyOnLoad::LateUpdate()
	{
		CScene::LateUpdate();
	}

	void DontDestroyOnLoad::Render(HDC _hDC)
	{
		CScene::Render(_hDC);
	}

	void DontDestroyOnLoad::OnEnter()
	{
		CScene::OnEnter();
	}

	void DontDestroyOnLoad::OnExit()
	{
		CScene::OnExit();
	}
}