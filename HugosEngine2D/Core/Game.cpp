#include "Game.h"
void Game::gameInit()
{
	rects.insert({ "Rectangle0",
			new gRectangle(sf::Vector2f(100, 100), sf::Vector2f(10, 10),sf::Color::Red) });
}
void Game::gameLoop(float delta)
{
	rects.at("Rectangle0")->move(1, 0);
}