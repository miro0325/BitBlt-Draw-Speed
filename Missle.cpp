#include "framework.h"
#include "Missle.h"


Missile::Missile()
{

}

Missile::~Missile()
{

}

void Missile::Init()
{
	_Stat.HP = 1;
	_Stat.MaxHP = 1;
	_Stat.Speed = 600;
}

void Missile::Update()
{
	float deltaTime = GET_SINGLETON(TimeManager)->GetDeltaTime();

	_Pos.y -= deltaTime * _Stat.Speed;

}

void Missile::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _Pos, 10);
}