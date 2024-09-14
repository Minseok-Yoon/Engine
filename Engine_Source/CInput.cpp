#include "CInput.h"
#include "CApplication.h"

extern ya::CApplication application;

namespace ya
{
	vector<CInput::Key> CInput::mKeys = {};
	math::Vector2 CInput::vMousePosition = math::Vector2::One;

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
		createKeys();
	}

	void CInput::Update()
	{
		updateKeys();
	}

	void CInput::createKeys()
	{
		for (size_t i = 0; i < static_cast<UINT>(KEY_CODE::End); i++)
		{
			Key key = {};
			key.bPressed = false;
			key.eState = KEY_STATE::None;
			key.eKeyCode = static_cast<KEY_CODE>(i);

			mKeys.push_back(key);
		}
	}
	void CInput::updateKeys()
	{
		for_each(mKeys.begin(), mKeys.end(),
			[](Key& key) -> void
		{
			updateKey(key);
		});
	}

	void CInput::updateKey(Key& _key)
	{
		if (GetFocus())
		{
			if (isKeyDown(_key.eKeyCode))
				updateKeyDown(_key);
			else
				updateKeyUp(_key);

			getMousePositionByWindow();
		}
		else
		{
			clearKeys();
		}
	}

	bool CInput::isKeyDown(KEY_CODE _code)
	{
		return GetAsyncKeyState(ASCII[(UINT)_code]) & 0x8000;
	}

	void CInput::updateKeyDown(Key& _key)
	{
		if (_key.bPressed == true)
			_key.eState = KEY_STATE::Pressed;
		else
			_key.eState = KEY_STATE::Down;

		_key.bPressed = true;
	}

	void CInput::updateKeyUp(Key& _key)
	{
		if (_key.bPressed == true)
			_key.eState = KEY_STATE::Up;
		else
			_key.eState = KEY_STATE::None;

		_key.bPressed = false;
	}

	void CInput::getMousePositionByWindow()
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(application.GetHwnd(), &mousePos);

		vMousePosition.x = mousePos.x;
		vMousePosition.y = mousePos.y;
	}

	void CInput::clearKeys()
	{
		for (Key& key : mKeys)
		{
			if (key.eState == KEY_STATE::Down || key.eState == KEY_STATE::Pressed)
				key.eState = KEY_STATE::Up;
			else if (key.eState == KEY_STATE::Up)
				key.eState = KEY_STATE::None;

			key.bPressed = false;
		}
	}
}