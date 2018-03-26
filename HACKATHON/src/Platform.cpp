#include <Platform.hpp>


Platform::Platform(Game* gameState,sf::Vector2f position, sf::Vector2f size, std::string fileName)
	:GameObject(gameState)
{
	collisionBox.setSize(sf::Vector2f(size.x - 10, size.y - 10));
	collisionBox.setOrigin(collisionBox.getSize().x / 2, 0);
	collisionBox.setPosition(position);

	texture.loadFromFile("../graphics/" + fileName);

	textureBox.setTexture(&texture);
	textureBox.setSize(size);
	textureBox.setOrigin(size.x / 2, 0);
	textureBox.setPosition(sf::Vector2f(collisionBox.getPosition().x, collisionBox.getPosition().y - 5));

	/*DEBUG*/
	collisionBox.setFillColor(sf::Color(255, 0, 0, 100));
	/*END DEBUG*/
}

Platform::~Platform()
{

}


void Platform::update(sf::RenderWindow& window, const double& deltaTime)
{

}

void Platform::draw(sf::RenderWindow& window)
{
	window.draw(textureBox);

	#if(_DEBUG)
	window.draw(collisionBox);
	#endif
}

