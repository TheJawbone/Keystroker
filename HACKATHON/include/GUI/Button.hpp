#pragma once

#include <functional>

#include "Widget.hpp"

class Button : public Widget
{
public:

	Button();

	void connect(std::function<void()> function);

	void setBackgroundPosition(const sf::Vector2f& position);
	void setBackgroundSize(const sf::Vector2f& size);
	void setBackgroundFillColor(const sf::Color& fillColor);
	void setBackgroundTexture(sf::Texture& texture);
	void setBackgroundCoverTexture(sf::Texture& texture);

	void setTextCharacterSize(unsigned int size);
	void setTextString(const sf::String& string);
	void setTextFillColor(const sf::Color& fillColor);

private:

	sf::Font font;

	sf::RectangleShape background;
	sf::RectangleShape backgroundCover;
	sf::Text text;

	bool coverBackground;

	std::function<void()> function;

	void updateTextPosition();

	virtual void update() override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
};