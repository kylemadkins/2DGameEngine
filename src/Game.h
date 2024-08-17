#ifndef GAME_H
#define GAME_H

#include <SDL.h>

class Game {
private:
	bool m_isRunning;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
public:
	Game();
	~Game();
	void Init();
	void Run();
	void ProcessInput();
	void Update();
	void Render();
	void Destroy();

	int windowWidth;
	int windowHeight;
};

#endif
