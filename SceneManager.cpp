#include "framework.h"
#include "SceneManager.h"
#include "Scene.h"


void SceneManager::Init()
{

}

void SceneManager::Update()
{
	if (_scene)
	{
		_scene->Update();
	}
}

void SceneManager::Render(HDC hdc)
{
	if (_scene)
	{
		_scene->Render(hdc);
	}
}

void SceneManager::ChangeScene(SceneType sceneType)
{
	if (_sceneType == sceneType)
	{
		return;
	}

	Scene* newScene = nullptr;

	switch (sceneType)
	{
	case SceneType::DevScene:
		newScene = new DevScene();
		break;

	case SceneType::EditScene:
		newScene = new EditScene();
		break;

	case SceneType::GameScene:
		newScene = new GameScene();
		break;
	}

	SAFE_DELETE(_scene);

	_scene = newScene;
	_sceneType = sceneType;

	newScene->Init();
}