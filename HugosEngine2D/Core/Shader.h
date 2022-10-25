#pragma once
#include <SFML/Graphics.hpp>
#include "st"
class Shader : sf::Shader
{
public:
	/// <param name="filepaths"> String1 is vertex and String2 is fragment</param>
	void loadShaders(const std::pair<std::string, std::string> filepaths) {
		const std::string url = "Shaders\\";
		if (!loadFromFile(url + "vertex_shader.vert", sf::Shader::Vertex)) shaderError();
		if (!loadFromFile(url + "fragment_shader.frag", sf::Shader::Fragment)) shaderError();
		if (!loadFromFile(url + "vertex_shader.vert", url + "fragment_shader.frag")) shaderError();
		if (loadedCorrectly) {
			logl("All shaders loaded correctly");
		}
	}
private:
	bool loadedCorrectly = false;
};

