#include "MainScene.h"
#include "RPGSAEMMOApp.h"
#include <iostream>
#include "fVector2.h"
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "Inputs.h"
#include "InputManager.h"

void MainScene::Start()
{
	
}

void MainScene::Update()
{
	InputManager::Reset();
	if (Inputs::KeyPressed(Inputs::A)) {
		InputManager::MapActions(Inputs::A);
		std::cout << "Ahuevo puto\n";
	}
	if (Inputs::KeyDown(Inputs::B)) {
		std::cout << "Ahuevo puto\n";
	}



}

void MainScene::Draw()
{

}

void MainScene::SceneEnd()
{
}
