#pragma once
#include "../Engine_Source/CResources.h"
#include "../Engine_Source/CTexture.h"

namespace ya
{
	void LoadResources()
	{
		CResources::Load<graphics::CTexture>(L"BG",
			L"C:/Users/socls/πŸ≈¡ »≠∏È/Engine/Bin/Texture/bg.png");
	}
}