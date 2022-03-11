#include <Windows.h>
#include <vector>

#include "Graphics.h"
#include "Physics.h"
#include "GameObject.h"

class Game {
public:
	static void Init(HWND hWnd);
	static Game* GetInstance();

	Graphics* GetGraphics();

	void AddGameObject(GameObject* gameObject);
	void Update();

	std::vector<GameObject*> GetGameObjects();

	Game(Game& game) = delete;
private:
	Game(HWND hWnd);
	inline static Game* instance;

	std::vector<GameObject*> gameObjects;
};