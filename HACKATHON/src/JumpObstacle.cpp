#include "JumpObstacle.hpp"

JumpObstacle::JumpObstacle(Game * gameState, char keyToPress, float range, int score, sf::Vector2f position)
	:EmptyObstacle(gameState,keyToPress,range,score,position)
{
}

bool JumpObstacle::doPlayerAction(Player * player, double deltaTime)
{
	return player->jump(deltaTime);
}

void JumpObstacle::update(sf::RenderWindow & window, const double & deltaTime)
{
}

void JumpObstacle::draw(sf::RenderWindow & window)
{
}
