#pragma once

#include <SFML/Graphics.hpp>

#include <Grid.hpp>

class Blueprint : public sf::Drawable
{
public:

	Blueprint();

	void update();
	void setScale(float scale);

	sf::Vector2f getPosition();
	float getScale();

private:

	sf::Vector2f position;
	sf::Vector2f previousDragPosition;
	sf::Vector2f dragPositionOrigin;

	float scale;

	Grid grid;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};