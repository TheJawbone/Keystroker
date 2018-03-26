#pragma once

#include <SFML/Graphics.hpp>

class Widget : public sf::Drawable
{
public:

	virtual void update() = 0;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;

};