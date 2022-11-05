#pragma once
#include "GameObject.h"
#include "Polygon.h"
namespace hg {
	class BreakableObject : public GameObject
	{
	public:
		enum Type { Rectangle, Triangle, Cicrcle };
		BreakableObject(sf::Vector2f siz, sf::Vector2f pos, sf::Color col, bool phys, uint16_t i, Type t = Rectangle);
		void draw(sf::RenderTarget& target, const sf::Shader* shader);
		sf::Vector2f rpoint(float x, float y) {
			return sf::Vector2f( (float)(rand() % (int)x), (float)(rand() % (int)y));
		}
		sf::Vector2f rpoint(sf::Vector2f pos) {
			return sf::Vector2f((float)(rand() % (int)pos.x), (float)(rand() % (int)pos.y));
		}
		void break_into(uint8_t part_count) {
			if (has_broken) return;
			has_broken = true;
			shards.erase(shards.begin());			// Delete main
			for (int i = 0;i < part_count;i++) {
				std::vector<sf::Vector2f> points = { {rpoint(getSize())},
																	 {rpoint(getSize())},
																	 {rpoint(getSize())} };
				shards.push_back(new Polygon(points, true));
			}
		}

		void Update(const uint16_t deltaTime);
		private:
		bool has_broken = false;
		sf::Color color;
		std::vector<Polygon*> shards;
	};
}
