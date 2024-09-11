#pragma once

namespace ya::enums
{
	enum class LAYER_TYPE
	{
		None,
		BackGround,
		Player,
		Floor,
		Particle,
		Max = 16,
	};

	enum class RESOURCE_TYPE
	{
		Texture,
		Mesh,
		Material,
		Animation,
		AudioClip,
		Shader,
		Prefab,
		End,
	};
}