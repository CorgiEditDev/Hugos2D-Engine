#include "Game.h"
float zoom = 1.01;
int i = 0;
void Game::gameInit()
{

	newGameObject("Player",
	new hg::Rectangle(sf::Vector2f(100, 100), sf::Vector2f(100, 100),
		sf::Color::Black,false,654));
	// Ground
	newGameObject("Ground",
	new hg::Rectangle(sf::Vector2f(2000, 100), sf::Vector2f(0, 900),
		sf::Color::Red,false,2));
	newGameObject("Ground2",
		new hg::Rectangle(sf::Vector2f(2000, 100), sf::Vector2f(400, 700),
			sf::Color::Red, false, 3));
	newGameObject("Ground3",
		new hg::Rectangle(sf::Vector2f(2000, 100), sf::Vector2f(800, 500),
			sf::Color::Red, false, 4));
}
			
void Game::gameLoop(float delta)
{
	i++;
	if (i < 100) {
		view.zoom(zoom);
	}
	using hg::GameObject;
	const float speed = 0.6f;
	hg::Rectangle &player = *rects.at("Player");
	//setCameraPosition(player.getPosition());
	checkCollisionsFor(getGameObject("Player",GameObject::Type::RectangleShape)
	, GameObject::Type::RectangleShape);
	if (isKeyPressed(sf::Keyboard::W))
		getGameObject("Player", hg::GameObject::Type::RectangleShape).move(0, -speed, deltaTime);
	if (isKeyPressed(sf::Keyboard::A))
		getGameObject("Player", hg::GameObject::Type::RectangleShape).move(-speed, 0, deltaTime);
	if (isKeyPressed(sf::Keyboard::S))
		getGameObject("Player", hg::GameObject::Type::RectangleShape).move(0, speed, deltaTime);
	if (isKeyPressed(sf::Keyboard::D))
		getGameObject("Player", hg::GameObject::Type::RectangleShape).move(speed,0,deltaTime);
}