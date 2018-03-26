#include <Globals.hpp>

sf::Vector2f toVector2f(const sf::Vector2i& vector)
{
	return sf::Vector2f(
		(float)vector.x,
		(float)vector.y);
}

sf::Vector2f toVector2f(const sf::Vector2u& vector)
{
	return sf::Vector2f(
		(float)vector.x,
		(float)vector.y);
}