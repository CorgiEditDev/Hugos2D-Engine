#pragma once
#include "Display.h"
#include "GameObject/Rectangle.h"
#include "stadfx.h"



class Game
{
public:
	
	std::map<std::string, gRectangle*> rects;
	
	Game() {
		display.createWindow("Game");
		gameInit();
		m_gameLoop();
	}
private:
	float deltaTime = 0.0f;
	sf::Clock deltaCock;
	void m_gameLoop() {
		while (running) {
			while (display.hasEvents()) {
				if (display.shouldClose()) {
					display.closeWindow();
					running = false;
				}
			}
			display.clearDisplay();
			for (auto& rect : rects) {
				rect.second->draw(display);
				rect.second->Update();
			}
			gameLoop(deltaTime);
			display.show();
			deltaTime = deltaCock.restart().asMicroseconds()/100;
		}
	}
	bool running = true;
	Display display;
	void gameInit();
	void gameLoop(float delta);
};
