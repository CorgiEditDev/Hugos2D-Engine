#include "Game.h"

void Game::gameInit()
{
	newGameObject("poly", new hg::BreakableObject(sf::Vector2f(100, 100), sf::Vector2f(100, 100),
		sf::Color::Red, false, 100));
}

void Game::gameLoop(float delta) {
	
	if (isKeyPressed(sf::Keyboard::Space)) {
		getGameObjectBr("poly")->break_into(10);
	}
}