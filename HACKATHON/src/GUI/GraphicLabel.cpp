#include "GUI/GraphicLabel.hpp"

GraphicLabel::GraphicLabel()
{
	numbersTextures.resize(10);
	for (size_t i = 0; i < 10; i++)
		numbersTextures[i].loadFromFile("../graphics/num" + std::to_string(i) + std::string(".png"));
}

void GraphicLabel::setTextPosition(const sf::Vector2f& position)
{
	this->position = position;
	text.setPosition(position);
	updatePosition();
}

//void GraphicLabel::setTextString(const sf::String& string)
//{
//	text.setString(string);
//}

void GraphicLabel::setTextValue(int value)
{
	if (value)
	{
		numbers.resize(0);
		do {
			int digit = value % 10;
			numbers.resize(numbers.size() + 1 );
			numbers[numbers.size() - 1].setTexture(numbersTextures[digit]);
			value /= 10;
		} while (value > 0);

		for (int i = 0; i < (int)numbers.size()/2; i++)
		{
			sf::Sprite val = numbers[i];
			numbers[i] = numbers[numbers.size() -1- i];
			numbers[numbers.size() -1 - i] = val;
		}
	}
	else
	{
		numbers.resize(1);
		numbers[0].setTexture(numbersTextures[0]);
	}
	updatePosition();
}

void GraphicLabel::update()
{
}

void GraphicLabel::updatePosition()
{
	for (size_t i = 0; i < numbers.size(); i++)
		numbers[i].setPosition(sf::Vector2f(
			position.x + numbers[i].getGlobalBounds().width * i,
			position.y));
}

void GraphicLabel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (size_t i = 0; i < numbers.size(); i++)
		target.draw(numbers[i]);
}