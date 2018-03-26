#pragma once

#include "Widget.hpp"

class Label : public Widget
{
public:

	Label();

	void setTextPosition(const sf::Vector2f& position);
	void setTextCharacterSize(unsigned int size);
	void setTextString(const sf::String& string);
	void setTextFillColor(const sf::Color& fillColor);

	virtual void update() override;

private:

	sf::Font font;

	sf::Text text;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};