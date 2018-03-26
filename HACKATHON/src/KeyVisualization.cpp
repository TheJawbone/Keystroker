#include "GameMaster.hpp"
#include "KeyVisualization.hpp"

KeyVisualization::KeyVisualization(KeysTextures* keysTextures, char keyToDraw)
{
	key.setTexture((*keysTextures)[keyToDraw]);
}

void KeyVisualization::setKeyTexture(KeysTextures* keysTextures, char keyToDraw)
{
	key.setTexture((*keysTextures)[keyToDraw]);
}

void KeyVisualization::setPosition(sf::Vector2f position)
{
	key.setPosition(position);
}

void KeyVisualization::highlight()
{
	key.setColor(sf::Color::Green);
}

void KeyVisualization::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(key, states);
}
