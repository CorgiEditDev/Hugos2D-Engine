#pragma once
#include <SFML/Graphics.hpp>

namespace hg {
	namespace tween {
		static float easeInBack(float x) { return (1.70158f + 1) * x * x * x - 1.70158f * x * x; }
		static float easeOutBack(float x) { return 1 + (1.70158f + 1) * pow(x - 1, 3) + 1.70158f * pow(x - 1, 2); }
		static float easeInOutQuint(float x) { return x < 0.5f ? 16 * x * x * x * x * x : 1 - pow(-2 * x + 2, 5) / 2; }
	}
	namespace Physics {
		static bool checkCollision(const sf::FloatRect& f1, const sf::FloatRect& f2) {
			return f1.intersects(f2);
		}
	};
}