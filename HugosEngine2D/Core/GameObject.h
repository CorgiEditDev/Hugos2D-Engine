#pragma once
#include <SFML/Graphics.hpp>
class GameObject
{
public:
	static enum Type{
		RectangleShape,Sprite
	};
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
	void move(sf::Vector2f offset, float d) {
		position += {offset.x * d, offset.y* d};
	}
	void move(float x, float y,float d) {
		position += {x*d, y*d};
	}
private:
	sf::Vector2f position;
	sf::Vector2f size;
};

