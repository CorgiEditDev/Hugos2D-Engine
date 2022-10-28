#include "Game.h"
float zoom = 1.01;
int i = 0;
void Game::gameInit()
{

	newGameObject("Player",
		new hg::Rectangle(sf::Vector2f(100, 100), sf::Vector2f(100, 100),
			sf::Color::Red, false, 654));
	// Ground
	newGameObject("Ground",
		new hg::Rectangle(sf::Vector2f(1000, 1000), sf::Vector2f(0, 500),
			sf::Color::Red, false, 2));
}
			
void Game::gameLoop(float delta)
{
	
	if (i < 100) {
		view.zoom(zoom);
		i++;
	}
	using hg::GameObject;
	const float speed = 0.1f;
	hg::Rectangle &player = *rects.at("Player");
	
	checkCollisionsFor(getGameObject("Player",GameObject::Type::RectangleShape), GameObject::Type::RectangleShape);


	if (isKeyPressed(sf::Keyboard::W))
		getGameObject("Player", hg::GameObject::Type::RectangleShape).move(0, -speed, deltaTime);
	if (isKeyPressed(sf::Keyboard::A))
		getGameObject("Player", hg::GameObject::Type::RectangleShape).move(-speed, 0, deltaTime);
	if (isKeyPressed(sf::Keyboard::S))
		getGameObject("Player", hg::GameObject::Type::RectangleShape).move(0, speed, deltaTime);
	if (isKeyPressed(sf::Keyboard::D))
		getGameObject("Player", hg::GameObject::Type::RectangleShape).move(speed,0,deltaTime);
}