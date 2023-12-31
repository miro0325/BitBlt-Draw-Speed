#pragma once

enum class KeyType
{
	LeftMouse = VK_LBUTTON,
	RightMouse = VK_RBUTTON,

	Up = VK_UP,
	Down = VK_DOWN,
	Left = VK_LEFT,
	Right = VK_RIGHT,

	SpaceBar = VK_SPACE,

	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',

	Q = 'Q',
	E = 'E',
};

enum class KeyState
{
	None,	
	Press,  
	Down,   
	Up,   
	End,
};

enum
{
	// KEY_TYPE_COUNT = 256
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX) + 1,
	// KEY_STATE_COUNT = 4
	KEY_STATE_COUNT = static_cast<int32>(KeyState::End),
};

class InputManager
{
	DECLARE_SINGLETON(InputManager);

public:
	void Init(HWND hWnd);
	void Update();

	bool GetButton(KeyType key) { return GetState(key) == KeyState::Press; }
	bool GetButtonDown(KeyType key) { return GetState(key) == KeyState::Down; }
	bool GetButtonUp(KeyType key) { return GetState(key) == KeyState::Up; }

	POINT GetMousePos() { return _mousePos; }

private:
	KeyState GetState(KeyType key) { return _states[static_cast<uint64> (key)]; }

private:
	HWND _hWnd = 0;

	vector<KeyState> _states;

	POINT _mousePos = {};
};

