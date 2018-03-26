#include <MouseEventsHandler.hpp>

sf::Vector2i MouseEventsHandler::mousePosition = sf::Vector2i();

bool  MouseEventsHandler::leftButtonPressedOnce = false;
bool  MouseEventsHandler::rightButtonPressedOnce = false;
bool  MouseEventsHandler::middleButtonPressedOnce = false;

float MouseEventsHandler::scrollWheelDelta = 0.f;

void MouseEventsHandler::update(const sf::Event& event)
{
	if (event.type == sf::Event::MouseMoved)
	{
		mousePosition.x = event.mouseMove.x;
		mousePosition.y = event.mouseMove.y;
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			leftButtonPressedOnce = true;
		}

		if (event.mouseButton.button == sf::Mouse::Left)
		{
			rightButtonPressedOnce = true;
		}

		if (event.mouseButton.button == sf::Mouse::Middle)
		{
			middleButtonPressedOnce = true;
		}
	}

	if (event.type == sf::Event::MouseWheelScrolled)
	{
		//TODO: do poprawy
 		scrollWheelDelta = event.mouseWheel.x;
		if (scrollWheelDelta < 0)
			scrollWheelDelta = -1.f;
		else
			scrollWheelDelta = 1.f;
	}
}

void MouseEventsHandler::reset()
{
	leftButtonPressedOnce = false;
	rightButtonPressedOnce = false;
	middleButtonPressedOnce = false;

	scrollWheelDelta = 0.f;
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
	case  sf::Mouse::Button::Middle:
		return sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle);
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
	case  sf::Mouse::Button::Middle:
		return middleButtonPressedOnce;
		break;
	}
	return false;
}

float MouseEventsHandler::getScrollWheelDelta()
{
	return scrollWheelDelta;
}

sf::Vector2i MouseEventsHandler::getMousePosition()
{
	return mousePosition;
}
