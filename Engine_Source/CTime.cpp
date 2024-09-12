#include "CTime.h"

namespace ya
{
	LARGE_INTEGER CTime::CpuFrequency = {};
	LARGE_INTEGER CTime::PrevFrequency = {};
	LARGE_INTEGER CTime::CurrentFrequency = {};
	float CTime::fDeltaTime = 0.0f;

	void CTime::Init()
	{
		// Cpu 고유 진동수
		QueryPerformanceFrequency(&CpuFrequency);

		// 프로그램이 시작 했을 때 현재 진동수
		QueryPerformanceCounter(&PrevFrequency);
	}

	void CTime::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);
		fDeltaTime = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void CTime::Render(HDC _hDC)
	{
		/*static float time = 0.0f;

		time += DeltaTime;
		float fps = 1.0f / DeltaTime;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)fps);
		int len = wcsnlen_s(str, 50);

		TextOut(_hDC, 0, 0, str, len);*/
	}
}