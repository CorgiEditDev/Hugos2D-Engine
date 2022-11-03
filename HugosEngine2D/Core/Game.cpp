#include "Game.h"
float zoom = 1.01;
int i = 0;
void Game::gameInit()
{
	hg::texture tx;
	tx.load("Assets\\Hugos.png");
	newGameObject("Player", new hg::Sprite(500,200,10,10,tx,0));
}
			
void Game::gameLoop(float delta)
{
}