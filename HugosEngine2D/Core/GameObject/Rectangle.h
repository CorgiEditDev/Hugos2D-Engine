#pragma once
#include "..\GameObject.h"
namespace hg {
	class Rectangle : public GameObject
	{
	public:
		Rectangle(sf::Vector2f siz, sf::Vector2f pos, sf::Color color,bool phys,uint16_t i) : GameObject(pos, siz,phys,i)
		{
			this->color = color;
		}
		void draw(sf::RenderTarget& target, const sf::Shader* shader) {
			target.draw(rect, shader);
		}

		void Update(const uint16_t deltaTime) {
			hitbox.top = getPosition().y;
			hitbox.left = getPosition().x;
			hitbox.width = getSize().x;
			hitbox.height = getSize().y;
			getPhysics().update(deltaTime);
			setPosition(getPosition().x + getPhysics().velocity.x * deltaTime,
				getPosition().y + getPhysics().velocity.y * deltaTime);

			rect.setSize(getSize());
			rect.setFillColor(color);
			rect.setPosition(getPosition());
		}
		//private:
		sf::Color color;
		sf::RectangleShape rect;
	};
}

