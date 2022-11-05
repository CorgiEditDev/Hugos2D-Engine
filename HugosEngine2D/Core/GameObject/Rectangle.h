#pragma once
#include "..\GameObject.h"
namespace hg {
	class Rectangle : public GameObject
	{
	public:
		Rectangle(sf::Vector2f siz, sf::Vector2f pos, sf::Color col,bool phys,uint16_t i) : GameObject(pos, siz,phys,i)
		{
			rect.setOrigin(siz.x / 2,siz.y/2);
			this->color = sf::Color::Red;
		}
		void draw(sf::RenderTarget& target, const sf::Shader* shader) {
			target.draw(rect, shader);
		}

		void Update(const uint16_t deltaTime) {
			hitbox.top = getPosition().y-getSize().y/2;
			hitbox.left = getPosition().x - getSize().x / 2;
			hitbox.width = getSize().x;
			hitbox.height = getSize().y;
			getPhysics().update(deltaTime);
			setPosition(getPosition().x + getPhysics().velocity.x * deltaTime,
				getPosition().y + getPhysics().velocity.y * deltaTime);

			rect.setSize(getSize());
			
			rect.setPosition(getPosition());
		}
		//private:
		sf::Color color;
		sf::RectangleShape rect;
	};
}

