#include "Game.h"

void Game::gameInit()
{
 hg::texture tx;
 tx.load("Assets\\Hugos.png");
 newGameObject("Ball", new hg::Sprite(500,200,10,10,tx,30));
 newGameObject("Paddle1", new hg::Rectangle(sf::Vector2f(10,200),sf::Vector2f(0,0),sf::Color::Red,false,10);
 newGameObject("Paddle2", new hg::Rectangle(sf::Vector2f(10,200),sf::Vector2f(1000,0),sf::Color::Red,false,10);
}
   
void Game::gameLoop(float delta){
 auto paddle1 = getGameObject("Paddle1", hg::GameObject::Type::RectangleShape);
 auto paddle2 = getGameObject("Paddle2", hg::GameObject::Type::RectangleShape);
 if(isKeyPressed(sf::Key::W)){
  paddle1.move(0,1,deltaTime);
 }
}