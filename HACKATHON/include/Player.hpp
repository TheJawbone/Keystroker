#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "GameObject.hpp"
#include "KeyboardEvents.hpp"


class Player : public GameObject
{
private:
	sf::Vector2f velocity;
	sf::Vector2f spriteIndex;
	sf::IntRect intRect;
	sf::View view;
	GameObject* currentPlatform;

	double time;
	double slideTime;
	bool isOnPlatform;
	bool isJumping;
	bool isFalling;
	bool isSliding;

public:
	Player(Game* gameState);
	virtual ~Player();

	void update(sf::RenderWindow& window, const double& deltaTime);
	void draw(sf::RenderWindow& window);

	void setPosition(sf::Vector2f position);
	void setSprite(sf::Vector2f spriteIndex);
	void setCurrentPlatform(GameObject* platform);

	bool jump(double deltaTime);
	void slide();

	void setIsOnPlatform(bool cond);
	void setIsJumping(bool cond);
	void setIsFalling(bool cond);

	void setViewForPlayer();

	bool getIsOnPlatform();
	bool getIsJumping();
	bool getIsFalling();

	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	sf::View* getView();
};