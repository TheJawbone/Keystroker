#pragma once

#include <SFML/Graphics.hpp>

#define SCREEN_SIZE_X 1366
#define SCREEN_SIZE_Y 768

#define SCALE_MULTIPLIER 1.01f

sf::Vector2f toVector2f(const sf::Vector2i& vector);
sf::Vector2f toVector2f(const sf::Vector2u& vector);