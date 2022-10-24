#include "Game.h"

void Game::gameInit()
{
	rects.insert({ "Player",
			new gRectangle(sf::Vector2f(100, 100), sf::Vector2f(10, 10),sf::Color::Red) });
}
void Game::gameLoop(float delta)
{
	if (isKeyPressed(sf::Keyboard::D))
		rects.at("Player")->move(1, 0);
	if (isKeyPressed(sf::Keyboard::A))
		rects.at("Player")->move(-1, 0);
	if (isKeyPressed(sf::Keyboard::W))
		rects.at("Player")->move(0, -1);
	if (isKeyPressed(sf::Keyboard::S))
		rects.at("Player")->move(0, 1);
}