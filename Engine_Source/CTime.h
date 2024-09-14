#pragma once
#include "CommonInclude.h"

namespace ya
{
	class CTime
	{
	public:
		static void Init();
		static void Update();
		static void Render(HDC _hDC);

	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float fDeltaTime;

	public:
		__forceinline static float DeltaTime() { return fDeltaTime; }
	};
}