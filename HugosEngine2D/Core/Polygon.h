#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <vector>
#include <iostream>
class Polygon : public sf::VertexArray
{
public:
	Polygon(std::vector<sf::Vector2f> v, bool phys) : sf::VertexArray(sf::Triangles, 3) {
		physics.enabled = phys;
		for (auto& _v : v) {
			this->append(_v);
		}
	}
	hg::PhysicsComponent physics;
	void update(uint16_t delta) {
		physics.update(delta);
		for (int i = 0; i < getVertexCount(); i++) {
			this[0][i].position.y += physics.velocity.y*delta/2;
		}
	}
private:
	
};

