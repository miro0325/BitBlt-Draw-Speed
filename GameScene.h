#pragma once
#include "Scene.h"
#include "Player.h"

class GameScene : public Scene
{
	using Super = Scene;
public:
	GameScene();
	virtual ~GameScene() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	Player* _Player = nullptr;
};

