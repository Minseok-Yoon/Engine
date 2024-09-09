#include "CInput.h"

namespace ya
{
	vector<CInput::Key> CInput::mKeys = {};

	int ASCII[static_cast<UINT>(KEY_CODE::End)] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON,
	};

	void CInput::Init()
	{
		for (size_t i = 0; i < (UINT)KEY_CODE::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.eState = KEY_STATE::None;
			key.eKeyCode = (KEY_CODE)i;

			mKeys.push_back(key);
		}
	}

	void CInput::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			//키가 눌렸다
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].eState = KEY_STATE::Pressed;
				else
					mKeys[i].eState = KEY_STATE::Down;

				mKeys[i].bPressed = true;
			}
			else // 키가 안눌렸다.
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].eState = KEY_STATE::Up;
				else
					mKeys[i].eState = KEY_STATE::None;

				mKeys[i].bPressed = false;
			}
		}
	}
}