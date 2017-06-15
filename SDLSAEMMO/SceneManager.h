#pragma once
#include "Scene.h"
#include "RPGSAEMMOApp.h"
class SceneManager
{
public:
	static SceneManager* GetSceneManager();
	static void DeleteSceneManager();
	void ChangeScene(Scene* const& _scene);
	Scene* GetCurrentScene();
	~SceneManager();
private:
	static SceneManager* sceneManager;
	SceneManager();
	Scene* scene;
};




