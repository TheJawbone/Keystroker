#include "GUI/Label.hpp"

Label::Label()
{
	font.loadFromFile("../fonts/arial.ttf");
	text.setFont(font);
}

void Label::setTextPosition(const sf::Vector2f& position)
{
	text.setPosition(position);
}

void Label::setTextCharacterSize(unsigned int size)
{
	text.setCharacterSize(size);
}

void Label::setTextString(const sf::String& string)
{
	text.setString(string);
}

void Label::setTextFillColor(const sf::Color& fillColor)
{
	text.setFillColor(fillColor);
}

void Label::update()
{
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(text);
}
