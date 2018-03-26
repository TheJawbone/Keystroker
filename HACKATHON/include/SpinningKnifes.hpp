#pragma once
#include "GameObject.hpp"

class SpinningKnifes : public GameObject {

public:

	SpinningKnifes(Game* gameState, sf::Vector2f position, sf::Vector2f size, std::string fileName);


	void setPosition(sf::Vector2f position);

	void update(sf::RenderWindow& window, const double& deltaTime) ;
	void draw(sf::RenderWindow& window);
};