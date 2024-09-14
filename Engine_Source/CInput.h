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

		__forceinline static bool GetKeyDown(KEY_CODE _code) { return mKeys[(UINT)_code].eState == KEY_STATE::Down; }
		__forceinline static bool GetKeyUp(KEY_CODE _code) { return mKeys[(UINT)_code].eState == KEY_STATE::Up; }
		__forceinline static bool GetKey(KEY_CODE _code) { return mKeys[(UINT)_code].eState == KEY_STATE::Pressed; }
		__forceinline static math::Vector2 GetMousePosition() { return vMousePosition; }

	private:
		static void createKeys();
		static void updateKeys();
		static void updateKey(Key& _key);

		static bool isKeyDown(KEY_CODE _code);
		static void updateKeyDown(Key& _key);
		static void updateKeyUp(Key& _key);
		static void getMousePositionByWindow();
		static void clearKeys();

		// Ű�� ���´� ��� Ŭ���� �ȿ����� ������ �����ؾ� �ϴ� ���� ������ ����.
		static vector<Key> mKeys;
		static math::Vector2 vMousePosition;
	};
}