#pragma once
#include <SFML/Graphics.hpp>
class Display : sf::RenderWindow
{
private:
	sf::Event _winEvent;
	sf::Color clearColor;
public:
	friend class Game;
	Display(const bool create = false, const char* title = "Window");
	void createWindow(const char* title = "Window") {
		clearColor = sf::Color::Color(5, 21, 93);
		create(sf::VideoMode(sf::VideoMode::getDesktopMode().width,
										sf::VideoMode::getDesktopMode().height), title
										,sf::Style::None);
		//setFramerateLimit(144);
	}
	
	void setClearColor(sf::Color clearColor) { this->clearColor = clearColor;  };
	void clearDisplay() {
		clear(clearColor);
	}
	bool hasEvents() {
		return pollEvent(_winEvent);
	}
	bool shouldClose() {
		return _winEvent.type == sf::Event::Closed;
	}
	bool isKeyPressed(sf::Keyboard::Key key) {
		return sf::Keyboard::isKeyPressed(key);
	}
	void closeWindow() {
		close();
	}
	void show() {
		display();
	}
};

