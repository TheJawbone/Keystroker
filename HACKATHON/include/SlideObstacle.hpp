#pragma once
#include "EmptyObstacle.hpp"

class SlideObstacle : public EmptyObstacle
{
public:

	SlideObstacle(Game* gameState, char keyToPress, float range, int score, sf::Vector2f position);

	virtual bool doPlayerAction(Player* player, double deltaTime) override;

	void update(sf::RenderWindow& window, const double& deltaTime) override;
	void draw(sf::RenderWindow& window) override;


};