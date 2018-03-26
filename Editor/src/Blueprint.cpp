#include <Blueprint.hpp>

#include <MouseEventsHandler.hpp>
#include <Globals.hpp>

Blueprint::Blueprint()
{
	scale = 0.5f;
	grid.setScale(scale);
	grid.setScreenSize(sf::Vector2u(SCREEN_SIZE_X, SCREEN_SIZE_Y));
}

void Blueprint::update()
{
	if (MouseEventsHandler::isButtonPressedOnce(sf::Mouse::Button::Middle))
	{
		previousDragPosition = toVector2f(MouseEventsHandler::getMousePosition());
	}
	else if (MouseEventsHandler::isButtonPressed(sf::Mouse::Button::Middle))
	{
		sf::Vector2f newPosition = toVector2f(MouseEventsHandler::getMousePosition());
		dragPositionOrigin = newPosition - previousDragPosition;
		previousDragPosition = newPosition;

		position += dragPositionOrigin;

		grid.setPosition(position);
	}

	if (float scaleDelta = MouseEventsHandler::getScrollWheelDelta())
	{
		if (scaleDelta > 0)
			scale *= SCALE_MULTIPLIER;
		else
			scale /= SCALE_MULTIPLIER;
		setScale(scale);
	}
}

void Blueprint::setScale(float scale)
{
	this->scale = scale;
	grid.setScale(scale);
}

sf::Vector2f Blueprint::getPosition()
{
	return position;
}

float Blueprint::getScale()
{
	return scale;
}

void Blueprint::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(grid, states);
}
