#pragma once

#include "Globals.hpp"

class KeyVisualization : public sf::Drawable
{
public:

	KeyVisualization(KeysTextures* keysTextures, char keyToDraw );

	void setKeyTexture(KeysTextures* keysTextures, char keyToDraw);
	void setPosition(sf::Vector2f position);

	void highlight();

private:

	sf::Sprite key;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};