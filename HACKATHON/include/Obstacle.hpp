#pragma once
#include "GameObject.hpp"
#include "Player.hpp"
#include "KeyVisualization.hpp"
#include "Globals.hpp"


class Obstacle :public GameObject 
{

	KeyVisualization keyVisualisation;
	
protected:
	char keyToPress;
	float range;
	int score;
	bool pressed;
public:

	char getKeyNeedToPress();

	float getTriggerRange();

	Obstacle(Game* gameState,char keyToPress, float range, int scores,sf::Vector2f position);

	virtual bool doPlayerAction(Player* player, double deltaTime) = 0;

	void setNewKey(char key);

	bool wasPressed();
	bool isInRange(sf::Vector2f positionPlayer);
	void pressGoodButton();
	void  showRange(sf::RenderWindow &window);
	virtual void update(sf::RenderWindow& window, const double& deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	void drawKeyVisualization(sf::RenderWindow& window);
	KeyVisualization* getKeyVisualization();
	
	int getScore();
};