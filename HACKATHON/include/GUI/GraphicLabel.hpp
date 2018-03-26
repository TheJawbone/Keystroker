#pragma once

#include "Widget.hpp"

class GraphicLabel : public Widget
{
public:

	GraphicLabel();

	void setTextPosition(const sf::Vector2f& position);
	void setTextValue(int value);

	virtual void update() override;

private:

	sf::Vector2f position;
	sf::Text text;
	int value;

	std::vector< sf::Texture > numbersTextures;
	std::vector< sf::Sprite > numbers;

	void updatePosition();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};