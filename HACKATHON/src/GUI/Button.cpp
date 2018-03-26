#include "GUI/Button.hpp"

#include "MouseEventsHandler.hpp"

Button::Button()
{
	font.loadFromFile("../fonts/arial.ttf");
	text.setFont(font);
	coverBackground = false;
}

void Button::connect(std::function<void()> function)
{
	this->function = function;
}

void Button::setBackgroundPosition(const sf::Vector2f& position)
{
	background.setPosition(position);
	backgroundCover.setPosition(position);
	updateTextPosition();
}

void Button::setBackgroundSize(const sf::Vector2f& size)
{
	background.setSize(size);
	backgroundCover.setSize(size);
}

void Button::setBackgroundFillColor(const sf::Color& fillColor)
{
	background.setFillColor(fillColor);
	backgroundCover.setFillColor(fillColor);
}

void Button::setBackgroundTexture(sf::Texture& texture)
{
	background.setTexture(&texture);
}

void Button::setBackgroundCoverTexture(sf::Texture& texture)
{
	backgroundCover.setTexture(&texture);
}

void Button::setTextCharacterSize(unsigned int size)
{
	text.setCharacterSize(size);
	updateTextPosition();
}

void Button::setTextString(const sf::String& string)
{
	text.setString(string);
	updateTextPosition();
}

void Button::setTextFillColor(const sf::Color& fillColor)
{
	text.setFillColor(fillColor);
}

void Button::updateTextPosition()
{
	text.setPosition(
		background.getPosition().x + background.getSize().x / 2 - text.getGlobalBounds().width / 2,
		background.getPosition().y + background.getSize().y / 2 - text.getGlobalBounds().height / 2 - 8);
}

void Button::update()
{
	if (background.getGlobalBounds().contains(
		(float)MouseEventsHandler::getMousePosition().x,
		(float)MouseEventsHandler::getMousePosition().y))
	{
		coverBackground = true;
		if (MouseEventsHandler::isButtonPressedOnce(sf::Mouse::Button::Left))
			function();
	}
	else
		coverBackground = false;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (!coverBackground)
		target.draw(background);
	else
		target.draw(backgroundCover);
	target.draw(text);
}
