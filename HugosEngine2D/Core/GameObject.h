#pragma once
#include <SFML/Graphics.hpp>
class GameObject
{
public:
	GameObject(sf::Vector2f pos, sf::Vector2f siz) : position(pos), size(siz){};
	void setPosition(const sf::Vector2f pos) {position = pos;}
	void setPosition(float x, float y) { position = {x,y}; }
	void setSize(const sf::Vector2f siz) { size = size; }
	void setSize(float width, float height) { size = { width,height }; }
	sf::Vector2f getPosition() {
		return position;
	}
	sf::Vector2f getSize() {
		return size;
	}
	void move(sf::Vector2f offset) {
		position += offset;
	}
	void move(float x, float y) {
		position += {x, y};
	}
private:
	sf::Vector2f position;
	sf::Vector2f size;
};

