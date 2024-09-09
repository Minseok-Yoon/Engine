#pragma once
#include "CommonInclude.h"

namespace ya
{
	enum class KEY_STATE
	{
		Down,
		Pressed,
		Up,
		None,
	};

	enum class KEY_CODE
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		LButton, MButton, RButton,
		End,
	};

	class CInput
	{
	public:
		struct Key
		{
			KEY_CODE	eKeyCode;
			KEY_STATE	eState;
			bool		bPressed;
		};

		static void Init();
		static void Update();

		static bool GetKeyDown(KEY_CODE _code) { return mKeys[(UINT)_code].eState == KEY_STATE::Down; }
		static bool GetKeyUp(KEY_CODE _code) { return mKeys[(UINT)_code].eState == KEY_STATE::Up; }
		static bool GetKey(KEY_CODE _code) { return mKeys[(UINT)_code].eState == KEY_STATE::Pressed; }

	private:
		// Ű�� ���´� ��� Ŭ���� �ȿ����� ������ �����ؾ� �ϴ� ���� ������ ����.
		static vector<Key> mKeys;
	};
}