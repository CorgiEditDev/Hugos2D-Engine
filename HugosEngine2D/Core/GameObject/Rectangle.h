#pragma once
#include "..\GameObject.h"
class gRectangle : public GameObject
{
public:
	gRectangle(sf::Vector2f siz, sf::Vector2f pos, sf::Color color = sf::Color::White) : GameObject(pos,siz)
	{
		this->color = color;
	}
	void draw(sf::RenderTarget&target) {
		target.draw(rect);
	}

	void Update() {
		rect.setSize(getSize());
		rect.setFillColor(color);
		rect.setPosition(getPosition());
	}
//private:
	sf::Color color;
	sf::RectangleShape rect;
};

