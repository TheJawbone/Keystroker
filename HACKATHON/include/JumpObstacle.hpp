#pragma once

#include "EmptyObstacle.hpp"

class JumpObstacle : public EmptyObstacle
{
public:

	JumpObstacle(Game* gameState, char keyToPress, float range, int score, sf::Vector2f position);

	virtual bool doPlayerAction(Player* player, double deltaTime) override;

	void update(sf::RenderWindow& window, const double& deltaTime) override;
	void draw(sf::RenderWindow& window) override;


};