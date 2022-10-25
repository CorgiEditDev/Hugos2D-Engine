#include "Shader.h"


/// <param name="filepaths"> String1 is vertex and String2 is fragment</param>

void hg::Shader::loadShaders(const std::pair<std::string, std::string> filepaths) {
	const std::string url = "Shaders\\";
	loadedCorrectly = true;
	if (!loadFromFile(url + "vertex_shader.vert", sf::Shader::Vertex)) shaderError();
	if (!loadFromFile(url + "fragment_shader.frag", sf::Shader::Fragment)) shaderError();
	if (!loadFromFile(url + "vertex_shader.vert", url + "fragment_shader.frag")) shaderError();
	if (loadedCorrectly) {
		logl("All shaders loaded correctly");
	}
}

void hg::Shader::shaderError() {
	using namespace std;
	loadedCorrectly = false;
	logt(10, "/");
	logl("COULD NOT LOAD THE SHADER FILE!");
	logt(10, "/");
}
