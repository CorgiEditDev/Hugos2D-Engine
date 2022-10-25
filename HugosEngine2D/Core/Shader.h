#pragma once
#include <SFML/Graphics.hpp>
#include "stadfx.h"
namespace hg {
	class Shader : public sf::Shader
	{
	public:
		/// <param name="filepaths"> String1 is vertex and String2 is fragment</param>
		void loadShaders(const std::pair<std::string, std::string> filepaths);
	private:
		void shaderError();
		bool loadedCorrectly = false;
	};
}
