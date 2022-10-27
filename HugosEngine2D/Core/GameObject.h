#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

namespace hg {
	#define GRAV_FORCE 0.0025f
	struct PhysicsComponent {
		sf::Vector2f velocity = sf::Vector2f(0.f,0.f);
		void update(const uint16_t deltaTime) {
			if(enabled)
			velocity.y += (GRAV_FORCE);
		}
		bool enabled = false;
	};

	class GameObject
	{
	public:
		sf::FloatRect getHitBox() {
			return hitbox;
		}
		static enum Type {
			RectangleShape, Sprite
		};
		GameObject(sf::Vector2f pos, sf::Vector2f siz,bool hasPhys = false, const uint16_t i = rand()% 65535) : position(pos), size(siz),id(i)
		{
			hitbox.top = pos.y;
			hitbox.left = pos.x;
			hitbox.width = siz.x;
			hitbox.height = siz.y;
			physics.enabled = hasPhys;
		};
		void setPosition(const sf::Vector2f pos) { position = pos; }
		void setPosition(float x, float y) { position = { x,y }; }
		void setSize(const sf::Vector2f siz) { size = size; }
		void setSize(float width, float height) { size = { width,height }; }
		sf::Vector2f getPosition() {
			return position;
		}
		sf::Vector2f getSize() {
			return size;
		}
		void move(sf::Vector2f offset, float d) {
			sf::Vector2f offset(offset.x * 10, offset.y * 10);
			std::clamp(physics.velocity.x, (float)0, offset.x);
			physics.velocity.x += sin((offset.x * (d / 250)) / 500);
			std::clamp(physics.velocity.x, (float)0, offset.y);
			physics.velocity.y += sin((offset.y * (d / 250)) / 500);
		}
		void move(float x,float y, float d) {
			sf::Vector2f offset(x*10, y*10);
			std::clamp(physics.velocity.x, (float)0, offset.x);
			physics.velocity.x += sin((offset.x * (d / 250)) / 500);
			std::clamp(physics.velocity.x, (float)0, offset.y);
			physics.velocity.y += sin((offset.y * (d / 250)) / 500);
		}
		void absMove(float x, float y, float d) {
			position.x += x * (d / 250);
			position.y += y*(d/250);
			physics.velocity = { 0,0 };
		}
		PhysicsComponent& getPhysics() {
			return physics;
		}
	
		sf::FloatRect hitbox;
		uint16_t id;
		uint16_t weight = 20;
	private:
		
		PhysicsComponent physics;
		sf::Vector2f position;
		sf::Vector2f size;
	};
}

