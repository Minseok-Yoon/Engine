#pragma once
#include "../Engine_Source/CResources.h"
#include "../Engine_Source/CTexture.h"

namespace ya
{
	void LoadResources()
	{
		CResources::Load<graphcis::CTexture>(L"BG",
			L"C:/Users/socls/πŸ≈¡ »≠∏È/Engine/Bin/Texture/bg.png");
	}
}