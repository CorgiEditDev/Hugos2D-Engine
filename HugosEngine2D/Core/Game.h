#pragma once
#include "Display.h"
#include "GameObject/Rectangle.h"
#include "GameObject/Sprite.h"
#include "stadfx.h"



class Game
{
public:
	
	void newGameObject(const std::string &id, hg::Rectangle*obj) {
		rects.insert({ id,obj });
	}
	void newGameObject(const std::string& id, hg::Sprite* obj) {
		sprites.insert({ id,obj });
	}

	GameObject &getGameObject(const std::string& id, GameObject::Type type) {
		switch (type)
		{
		case GameObject::RectangleShape:
			return *(hg::Rectangle*)rects.at(id);
			break;
		case GameObject::Sprite:
			return *(hg::Sprite*)sprites.at(id);
			break;
		default:
			std::cout << "getGameObject() - method is not implemented for this shape type yet.";
			break;
		}
	}
	
	bool isKeyPressed(sf::Keyboard::Key key) {
		return display.isKeyPressed(key);
	}
	std::map<std::string, hg::Rectangle*> rects;
	std::map < std::string, hg::Sprite* > sprites;
	Game() {
		sf::Shader shader;
		const std::string url = "Shaders\\";
		if (!shader.loadFromFile(url + "vertex_shader.vert", sf::Shader::Vertex)) shaderError();
		if (!shader.loadFromFile(url + "fragment_shader.frag", sf::Shader::Fragment)) shaderError();
		if (!shader.loadFromFile(url + "vertex_shader.vert", url + "fragment_shader.frag")) shaderError();
		if (shadersLoadedCorrectly) {
			logl("All shaders loaded correctly");
		}
		display.createWindow("Game");
		gameInit();
		m_gameLoop();
	}
private:
	bool shadersLoadedCorrectly = true;
	void shaderError() {
		using namespace std;
		shadersLoadedCorrectly = false;
		logt(10, "/");
		logl("COULD NOT LOAD THE SHADER FILE!");
		logt(10, "/");
	}
	sf::Shader shader;
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
				rect.second->draw(display, &shader);
				rect.second->Update();
			}
			for (auto& rect : sprites) {
				rect.second->draw(display,&shader);
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
