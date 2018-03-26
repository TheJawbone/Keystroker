#include "SlideObstacle.hpp"

SlideObstacle::SlideObstacle(Game * gameState, char keyToPress, float range, int score, sf::Vector2f position)
	:EmptyObstacle(gameState, keyToPress, range, score, position)
{
}

bool SlideObstacle::doPlayerAction(Player * player, double deltaTime)
{
	player->slide();
	return true;
}

void SlideObstacle::update(sf::RenderWindow & window, const double & deltaTime)
{
}

void SlideObstacle::draw(sf::RenderWindow & window)
{
}
