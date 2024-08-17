#include <iostream>
#include <SDL.h>

#include "Game.h"

Game::Game() : m_isRunning(false), m_window(nullptr), m_renderer(nullptr), windowWidth(1280), windowHeight(720) {}

Game::~Game() {}

void Game::Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "Error initializing SDL" << std::endl;
		return;
	}

	m_window = SDL_CreateWindow("2D Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
	if (!m_window) {
		std::cerr << "Error creating window" << std::endl;
		return;
	}
	SDL_SetWindowFullscreen(m_window, SDL_WINDOW_FULLSCREEN);

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!m_renderer) {
		std::cerr << "Error creating renderer" << std::endl;
		return;
	}

	m_isRunning = true;
}

void Game::Run() {
	while (m_isRunning) {
		ProcessInput();
		Update();
		Render();
	}
}

void Game::ProcessInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				m_isRunning = false;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					m_isRunning = false;
				}
				break;
		}
	}
}

void Game::Update() {}

void Game::Render() {
	SDL_SetRenderDrawColor(m_renderer, 69, 179, 157, 255);
	SDL_RenderClear(m_renderer);

	// Render game objects

	SDL_RenderPresent(m_renderer);
}

void Game::Destroy() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
