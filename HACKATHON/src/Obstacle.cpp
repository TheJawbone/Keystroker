#include "GameMaster.hpp"
#include "Game.hpp"
#include "Obstacle.hpp"

char Obstacle::getKeyNeedToPress()
{
	return keyToPress;
}



float Obstacle::getTriggerRange()
{
	return range;
}

Obstacle::Obstacle(Game * gameState, char keyToPress, float range,int scores, sf::Vector2f position)
	:GameObject(gameState)
	, keyVisualisation(gameState->getGameMaster()->getKeysTextures(), keyToPress)
{
	
	this->range = range;
	this->keyToPress = keyToPress;
	pressed = false;
	keyVisualisation.setPosition(sf::Vector2f(
		position.x - 50, 50));
	score = scores;
}

void Obstacle::setNewKey(char key)
{
	keyToPress = key;
}

bool Obstacle::wasPressed()
{
	return pressed;
}

bool Obstacle::isInRange(sf::Vector2f positionPlayer)
{

	sf::Vector2f obstaclePosition = getPosition();
	float obstacleRange = getTriggerRange();
	if (obstaclePosition.x  + obstacleRange > positionPlayer.x && obstaclePosition.x - obstacleRange < positionPlayer.x)
	{
		return true;
	}

	return false;
}

void Obstacle::pressGoodButton()
{
	pressed = true;
}

void  Obstacle::showRange(sf::RenderWindow &window)
{
	sf::RectangleShape shape;
	shape.setFillColor(sf::Color(0,255,0,100));
	shape.setPosition(getPosition().x -range, 0);
	shape.setSize(sf::Vector2f(range * 2, SPLASH_SIZE_Y));
	window.draw(shape);
}

void Obstacle::drawKeyVisualization(sf::RenderWindow& window)
{
	window.draw(keyVisualisation);
}

KeyVisualization* Obstacle::getKeyVisualization()
{
	return &keyVisualisation;
}

int Obstacle::getScore()
{
	return score;
}
