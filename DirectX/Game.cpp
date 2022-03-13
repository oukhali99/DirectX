#include "Game.h"
#include "btBulletDynamicsCommon.h"
#include "Clock.h"

void Game::Init(HWND hWnd) {
	instance = new Game(hWnd);
}

Game::Game(HWND hWnd) 
	:
	lastUpdateTime(Clock::GetSingleton().GetTimeSinceStart())
{}

Game* Game::GetInstance() {
	return instance;
}

void Game::AddGameObject(GameObject* gameObject) {
	gameObjects.push_back(gameObject);
}

std::vector<GameObject*> Game::GetGameObjects() {
	return gameObjects;
}

float Game::GetLastUpdateTime() {
	return lastUpdateTime;
}

void Game::Update() {
	Physics::GetInstance()->Update();

	Graphics::GetInstance()->ClearFrame();
	for (GameObject* gameObject : gameObjects) {
		gameObject->Update();
	}
	lastUpdateTime = Clock::GetSingleton().GetTimeSinceStart();

	Graphics::GetInstance()->RenderFrame();
}
