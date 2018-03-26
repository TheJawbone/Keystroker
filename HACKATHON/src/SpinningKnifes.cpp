#include "SpinningKnifes.hpp"

SpinningKnifes::SpinningKnifes(Game * gameState, sf::Vector2f position, sf::Vector2f size, std::string fileName)
	:GameObject(gameState)
{
	texture.loadFromFile("../graphics/" + fileName);
	
	textureBox.setTexture(&texture);
	textureBox.setSize(size);
	textureBox.setOrigin(textureBox.getSize().x / 2, textureBox.getSize().y / 4);
	
	collisionBox.setSize(sf::Vector2f(size.x - 10, size.y - 10));
	collisionBox.setOrigin(sf::Vector2f(collisionBox.getSize().x / 2, collisionBox.getSize().y));
	collisionBox.setFillColor(sf::Color(255, 0, 0, 100));
	
	setPosition(position);
}

void SpinningKnifes::setPosition(sf::Vector2f position)
{
	collisionBox.setPosition(sf::Vector2f(position.x, position.y - 10));
	textureBox.setPosition(sf::Vector2f(position.x, position.y - 150));
}


void SpinningKnifes::update(sf::RenderWindow & window, const double & deltaTime)
{
	textureBox.rotate(5);
}

void SpinningKnifes::draw(sf::RenderWindow & window)
{
	window.draw(textureBox);
	#if(_DEBUG)
	window.draw(collisionBox);
	#endif

}
