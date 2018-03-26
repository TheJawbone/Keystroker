#include "EmptyObstacle.hpp"

EmptyObstacle::EmptyObstacle(Game * gameState, char keyToPress, float range, int score, sf::Vector2f position)
	:Obstacle(gameState, keyToPress, range,score,position)
{

	collisionBox.setOrigin(collisionBox.getSize().x / 2, 0);
	collisionBox.setPosition(position);


	/*DEBUG*/
	collisionBox.setFillColor(sf::Color(255, 0, 0, 100));
	/*END DEBUG*/
}



void EmptyObstacle::update(sf::RenderWindow & window, const double & deltaTime)
{
}

void EmptyObstacle::draw(sf::RenderWindow & window)
{
}
