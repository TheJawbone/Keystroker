#pragma once

#include <SFML/Graphics.hpp>

class Grid : public sf::Drawable
{
public:

	Grid();
	~Grid();
	
	void setPosition(const sf::Vector2f& position);
	void setScale(float scale);

	void setScreenSize(const sf::Vector2u& size);

	void setThickLinesSpacer(size_t spacer);
	void setThickLinesDividers(size_t numberOfDividers);

private:

	sf::Vector2f position;
	float scale;

	sf::Vector2u screenSize;

	size_t thickLinesSpacer;
	size_t thickLinesDividers;

	std::vector<sf::RectangleShape*> horizontalThickLines;
	std::vector<sf::RectangleShape*> horizontalThinLines;
	std::vector<sf::RectangleShape*> verticalThickLines;
	std::vector<sf::RectangleShape*> verticalThinLines;

	size_t numberOfHorizontalThickLines;
	size_t numberOfHorizontalThinLines;
	size_t numberOfVerticalThickLines;
	size_t numberOfVerticalThinLines;

	void update();

	void allocateNewLines( size_t hThick, size_t hThin, size_t vThick, size_t vThin);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};