#include "Game.h"
using GameObjects::rects;
void Game::gameInit()
{
	GameObjects::rects.insert({ "Rectangle0",
			new gRectangle(sf::Vector2f(100, 100), sf::Vector2f(10, 10),sf::Color::Red) });
	GameObjects::rects.insert({ "Rectangle0",
			new gRectangle(sf::Vector2f(100, 100), sf::Vector2f(10, 10),sf::Color::Red) });
	std::cout << "Hello";
}
void Game::gameLoop(float delta)
{
	//rects.at("Rectangle0")->move(1, 0);
}