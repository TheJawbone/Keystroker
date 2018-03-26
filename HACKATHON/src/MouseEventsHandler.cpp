#include "MouseEventsHandler.hpp"

#include <iostream>

sf::Vector2i MouseEventsHandler::mousePosition = sf::Vector2i();

bool  MouseEventsHandler::leftButtonPressedOnce = false;
bool  MouseEventsHandler::rightButtonPressedOnce = false;

void MouseEventsHandler::update(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			leftButtonPressedOnce = true;
		}

		if (event.mouseButton.button == sf::Mouse::Left)
		{
			rightButtonPressedOnce = false;
		}
	}

	if (event.type == sf::Event::MouseMoved)
	{
		mousePosition.x = event.mouseMove.x;
		mousePosition.y = event.mouseMove.y;
	}
}

void MouseEventsHandler::reset()
{
	leftButtonPressedOnce = false;
	rightButtonPressedOnce = false;
}

bool MouseEventsHandler::isButtonPressed(const sf::Mouse::Button& button)
{
	switch (button)
	{
	case  sf::Mouse::Button::Left:
		return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
		break;
	case  sf::Mouse::Button::Right:
		return sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);
		break;
	}
	return false;
}

bool MouseEventsHandler::isButtonPressedOnce(const sf::Mouse::Button& button)
{
	switch (button)
	{
	case  sf::Mouse::Button::Left:
		return leftButtonPressedOnce;
		break;
	case  sf::Mouse::Button::Right:
		return rightButtonPressedOnce;
		break;
	}
	return false;
}

sf::Vector2i MouseEventsHandler::getMousePosition()
{
	return mousePosition;
}
