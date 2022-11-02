# Hugos2D-Engine
### Preview
An simple 2d game engine.
The editor works with c++, sfml imgui(currently not used)
# Scripting
The scripting happens in c++.
Here is a sample code that renders an image onto the screen.
```
#include "Game.h"
void Game::gameInit() {
	hg::texture tx;
	tx.load("Assets\\enemy.png");
	newGameObject("Player", new hg::Sprite(10,10,10,10,tx,0));
}
			
void Game::gameLoop(float delta){}
```

The minimal code is only three lines : 
```
#include "Game.h"
void Game::gameInit() {}
void Game::gameLoop(float delta){}
```
The game will automatically render the window and gameobjects for you, so you dont have to do that seperatly.




# Links

Link to the [SFML graphics library](https://www.sfml-dev.org)

Link to the [Dear Imgui gui library](https://github.com/ocornut/imgui)