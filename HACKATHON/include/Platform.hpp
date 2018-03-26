#pragma once

#include "GameObject.hpp"
#include <cstring>

class Platform : public GameObject
{

public:

	Platform(Game* gameState,sf::Vector2f position, sf::Vector2f size, std::string fileName);
	virtual ~Platform();

	void update(sf::RenderWindow& window, const double& deltaTime);
	void draw(sf::RenderWindow& window);

};