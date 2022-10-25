#pragma once
#include "..\GameObject.h"
namespace hg {
	class Rectangle : public GameObject
	{
	public:
		Rectangle(sf::Vector2f siz, sf::Vector2f pos, sf::Color color = sf::Color::White) : GameObject(pos, siz)
		{
			this->color = color;
		}
		void draw(sf::RenderTarget& target, const sf::Shader* shader) {
			target.draw(rect, shader);
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
}

