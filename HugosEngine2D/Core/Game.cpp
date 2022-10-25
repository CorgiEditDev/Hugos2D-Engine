#include "Game.h"
hg::texture tx;
void Game::gameInit()
{
	tx.load("Assets\\enemy.png");
	
	newGameObject("Player",new hg::Sprite(sf::Vector2f(100, 100), sf::Vector2f(100, 100), tx));
}
			
void Game::gameLoop(float delta)
{
	sprites.at("Player")->move(0.5, 0,1);
	/*if (isKeyPressed(sf::Keyboard::D))
		getGameObject("Player", GameObject::Type::Sprite).move(0.1,0,deltaTime);
	if (isKeyPressed(sf::Keyboard::A))
		getGameObject("Player", GameObject::Type::Sprite).move(-0.1, 0, deltaTime);
	if (isKeyPressed(sf::Keyboard::W))
		getGameObject("Player", GameObject::Type::Sprite).move(0, -0.1, deltaTime);
	if (isKeyPressed(sf::Keyboard::S))
		getGameObject("Player", GameObject::Type::Sprite).move(0, 0.1, deltaTime);
*/}