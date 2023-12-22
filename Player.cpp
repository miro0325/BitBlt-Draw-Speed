#include "framework.h"
#include "Player.h"
#include "Missle.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Init()
{
	_Stat.HP = 100;
	_Stat.MaxHP = 100;
	_Stat.Speed = 500;

	_Pos.x = 400;
	_Pos.y = 500;
}

void Player::Update()
{
	float deltaTime = GET_SINGLETON(TimeManager)->GetDeltaTime();

	if (GET_SINGLETON(InputManager)->GetButton(KeyType::A))
	{
		_Pos.x -= _Stat.Speed * deltaTime;
	}
	if (GET_SINGLETON(InputManager)->GetButton(KeyType::D))
	{
		_Pos.x += _Stat.Speed * deltaTime;
	}
	if (GET_SINGLETON(InputManager)->GetButton(KeyType::W))
	{
		_Pos.y -= _Stat.Speed * deltaTime;
	}
	if (GET_SINGLETON(InputManager)->GetButton(KeyType::S))
	{
		_Pos.y += _Stat.Speed * deltaTime;
	}

	if (GET_SINGLETON(InputManager)->GetButton(KeyType::SpaceBar))
	{
		//미사일 발사
		Missile* missile = new Missile();
	}


}

void Player::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _Pos, 50);
}