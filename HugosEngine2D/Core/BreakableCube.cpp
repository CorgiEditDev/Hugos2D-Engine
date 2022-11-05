#include "BreakableCube.h"

hg::BreakableObject::BreakableObject(sf::Vector2f siz, sf::Vector2f pos, sf::Color col, bool phys, uint16_t i, Type t)
	: GameObject(pos, siz, phys, i)
{
	// Add Cube
	std::vector<sf::Vector2f> points = { { siz.x,siz.y },{siz.x,0 },{ 0,siz.y } };
	switch (t)
	{
	case hg::BreakableObject::Rectangle:
		shards.push_back(new Polygon(points,false));
		break;
	case hg::BreakableObject::Triangle:
		break;
	case hg::BreakableObject::Cicrcle:
		break;
	default:
		break;
	}
	this->color = sf::Color::Red;
}

void hg::BreakableObject::draw(sf::RenderTarget& target, const sf::Shader* shader) {
	for (auto& shard : shards) {
		target.draw(*shard);
	}
}

void hg::BreakableObject::Update(const uint16_t deltaTime) {
	hitbox.top = getPosition().y - getSize().y / 2;
	hitbox.left = getPosition().x - getSize().x / 2;
	hitbox.width = getSize().x;
	hitbox.height = getSize().y;
	getPhysics().update(deltaTime);
	setPosition(getPosition().x + getPhysics().velocity.x * deltaTime,
		getPosition().y + getPhysics().velocity.y * deltaTime);
	for (auto& shard : shards) {
		shard->update(deltaTime);
	}
}
