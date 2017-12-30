#include "game.h"
#include "window.h"
// #include "resourcemanager.h"	// TESTING
// #include "quadrenderer.h"	// TESTING
#include <GL/glew.h>
#include <iostream>
#include <cstdlib>
using std::cout;

// int tex;		// TESTING

Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
	Window::init();
	initGl();
	
	// tex = ResourceManager::loadTexture("textures/container.jpg");
	// QuadRenderer::init();
}

void Game::clear()
{
	Window::clear();
}

void Game::update()
{
	Window::update();
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	// QuadRenderer::setSize(800.0f, 600.0f);
	// QuadRenderer::setTexture(tex);
	// QuadRenderer::render(0.0f, 0.0f);
}

void Game::initGl()
{
	glewExperimental = GL_TRUE;
	if (glewInit())
	{
		cout << "Failed to init GLEW!\n";
		exit(1);
	}
	// glClearColor(0.2f, 0.5f, 0.5f, 1.0f);	// TESTING
}

void Game::run()
{
	init();
	while (Window::isRunning())
	{
		update();
		render();
	}
	clear();
}