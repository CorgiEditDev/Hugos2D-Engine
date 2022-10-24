#include <SFML/Graphics.hpp>
#include "Game.h"
#include "stadfx.h"
void shaderError();
bool shadersLoadedCorrectly = true;
int main()
{
    sf::Shader shader;
    const std::string url = "Shaders\\";
    if (!shader.loadFromFile(url + "vertex_shader.vert", sf::Shader::Vertex)) shaderError();
        if (!shader.loadFromFile(url + "fragment_shader.frag", sf::Shader::Fragment)) shaderError();
            if (!shader.loadFromFile(url + "vertex_shader.vert", url + "fragment_shader.frag")) shaderError();  
            if (shadersLoadedCorrectly) {
                std::unique_ptr<Game> game(new  Game());
            }
}
void shaderError() {
    using namespace std;
    shadersLoadedCorrectly = false;
    logt(10, "/");
    logl("COULD NOT LOAD THE SHADER FILE!");
    logt(10, "/");
}