#pragma once

#include "Obstacle.hpp"

class EmptyObstacle : public Obstacle
{
public:

	EmptyObstacle(Game* gameState, char keyToPress, float range, int score, sf::Vector2f position);

	virtual bool doPlayerAction(Player* player, double deltaTime) { return true; };

	void update(sf::RenderWindow& window, const double& deltaTime) override;
	void draw(sf::RenderWindow& window) override;


};