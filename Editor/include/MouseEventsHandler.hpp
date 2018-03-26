#pragma once

#include <SFML/Graphics.hpp>

class MouseEventsHandler
{
public:

	static void update(const sf::Event& event);
	static void reset();

	static sf::Vector2i getMousePosition();

	static bool isButtonPressed(const sf::Mouse::Button& button);
	static bool isButtonPressedOnce(const sf::Mouse::Button& button);

	static float getScrollWheelDelta();

private:

	static sf::Vector2i mousePosition;

	static bool leftButtonPressedOnce;
	static bool rightButtonPressedOnce;
	static bool middleButtonPressedOnce;

	static float scrollWheelDelta;

};