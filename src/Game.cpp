#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <glm/glm.hpp>

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

glm::vec2 playerPos;
glm::vec2 playerVel;

void Game::Setup() {
	playerPos = glm::vec2(0.0, 0.0);
	playerVel = glm::vec2(1.0, 0.0);
}

void Game::Run() {
	Setup();
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

void Game::Update() {
	playerPos.x += playerVel.x;
	playerPos.y += playerVel.y;
}

void Game::Render() {
	SDL_SetRenderDrawColor(m_renderer, 50, 50, 50, 255);
	SDL_RenderClear(m_renderer);

	SDL_Surface* surface = IMG_Load("./assets/images/tank-tiger-right.png");
	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
	SDL_FreeSurface(surface);

	SDL_Rect dest = {static_cast<int>(playerPos.x), static_cast<int>(playerPos.y), 32, 32};
	SDL_RenderCopy(m_renderer, texture, NULL, &dest);

	SDL_DestroyTexture(texture);

	SDL_RenderPresent(m_renderer);
}

void Game::Destroy() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
