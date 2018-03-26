#include "Game.hpp"
#include "GameObject.hpp"

GameObject::GameObject(Game* gameState)
{
	this->gameState = gameState;
}

GameObject::~GameObject()
{

}

void GameObject::setPosition(sf::Vector2f position)
{
	collisionBox.setPosition(position);
	textureBox.setPosition(position);
}

sf::Vector2f GameObject::getPosition()
{
	return collisionBox.getPosition();
}

sf::Vector2f GameObject::getSize()
{
	return collisionBox.getSize();
}
