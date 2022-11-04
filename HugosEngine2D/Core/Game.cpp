#include "Game.h"
hg::GameObject* paddle1 = nullptr;
hg::GameObject* paddle2 = nullptr;
hg::GameObject* ball = nullptr;
hg::GameObject* top = nullptr;
hg::GameObject* bottom = nullptr;
constexpr float ballSpeed = 0.05;
void Game::gameInit() {
	srand(time(0));
	 hg::texture tx;
	 tx.load("Assets\\Ball.png");
	 newGameObject("Ball", new hg::Sprite(10,10,100,10,tx,30));
	 newGameObject("Paddle1", new hg::Rectangle(sf::Vector2f(10,200),sf::Vector2f(0,0),sf::Color::Red,false,10));
	 newGameObject("Paddle2", new hg::Rectangle(sf::Vector2f(10,200),sf::Vector2f(1000,0),sf::Color::Red,false,10));
	 
	 newGameObject("Bottom", new hg::Rectangle(sf::Vector2f(10000, 10), sf::Vector2f(0, 1020), sf::Color::Red, false, 10));
	 newGameObject("Top", new hg::Rectangle(sf::Vector2f(10000, 10), sf::Vector2f(0,-20), sf::Color::Red, false, 10));
	 
	 paddle1 = getGameObject("Paddle1", hg::GameObject::Type::RectangleShape);
	 paddle2 = getGameObject("Paddle2", hg::GameObject::Type::RectangleShape);
	 ball = getGameObject("Ball", hg::GameObject::Type::Sprite);
	 ball->getPhysics().velocity.x = -ballSpeed;
	 bottom = getGameObject("Bottom", hg::GameObject::Type::RectangleShape);
	 top = getGameObject("Bottom", hg::GameObject::Type::RectangleShape);
}
void collision();
void Game::gameLoop(float delta) {
	
	//checkCollisionsFor(*ball,hg::GameObject::Type::Sprite);
	if(isKeyPressed(sf::Keyboard::W)){
		paddle1->absMoveY(-30,deltaTime);
	} else if (isKeyPressed(sf::Keyboard::S)) {
		paddle1->absMoveY(30, deltaTime);
	}
	if (isKeyPressed(sf::Keyboard::Up)) {
		paddle2->absMoveY(-30, deltaTime);
	}
	else if (isKeyPressed(sf::Keyboard::Down)) {
		paddle2->absMoveY(30, deltaTime);
	}
	if (hg::Physics::checkCollision(ball->hitbox, paddle1->hitbox)) {
		ball->getPhysics().velocity.x = ballSpeed;
		collision();
	}
	else if (hg::Physics::checkCollision(ball->hitbox, paddle2->hitbox)) {
		ball->getPhysics().velocity.x = -ballSpeed;
		collision();
	}
	if (ball->getPosition().y < 0) {
		ball->getPhysics().velocity.y = 0.02;
	}
	if (ball->getPosition().y > 1000) {
		ball->getPhysics().velocity.y = -0.02;
	}
	
	
}

float rand_float(float mult) {
	if (rand() % 2) {
		return ballSpeed;
	}
	else {
		return -ballSpeed;
	}
}
void collision() {
	ball->getPhysics().velocity.y = (rand_float((ballSpeed)) - (ballSpeed / 2))/2;
}