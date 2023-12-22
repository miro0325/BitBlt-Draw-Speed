#include "framework.h"
#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	Super::Init();
	_Player = new Player();
	_Player->Init();
}

void GameScene::Update()
{
	Super::Update();
	if (_Player != nullptr)	_Player->Update();
}

void GameScene::Render(HDC hdc)
{
	Super::Render(hdc);
	if (_Player) _Player->Render(hdc);
}
