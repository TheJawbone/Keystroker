#include "GameMaster.hpp"
#include "Game.hpp"

#include "Player.hpp"
#include "Globals.hpp"

Player::Player(Game* gameState)
	:GameObject(gameState)
{
	texture.loadFromFile("../graphics/CharacterSheet.png");
	
	spriteIndex.x = 0;
	spriteIndex.y = 0;

	intRect.height = 200;
	intRect.width = 200;
	intRect.left = intRect.width * (int)spriteIndex.x;
	intRect.top = intRect.height * (int)spriteIndex.y;

	textureBox.setSize(sf::Vector2f(200, 200));
	textureBox.setOrigin(sf::Vector2f(textureBox.getSize().x / 2, textureBox.getSize().y));
	textureBox.setTexture(&texture);
	textureBox.setTextureRect(intRect);
	
	collisionBox.setSize(sf::Vector2f(80, 140));

	detectCollisions = true;
	
	view.setSize(SCREEN_SIZE_X, SCREEN_SIZE_Y);
	view.setCenter(collisionBox.getPosition().x, collisionBox.getPosition().y);

	/*DEBUG*/
	collisionBox.setFillColor(sf::Color(255, 0, 0, 100));
	collisionBox.setOrigin(sf::Vector2f(collisionBox.getSize().x / 2, collisionBox.getSize().y));
	/*END DEBUG*/


	velocity.x = 240;
	velocity.y = 0;

	currentPlatform = nullptr;

	time = 0;

	isJumping = false;
	isOnPlatform = false;
	isFalling = false;
	isSliding = false;

	setPosition(sf::Vector2f(630, 300));
}

Player::~Player()
{

}

void Player::setPosition(sf::Vector2f position)
{
	collisionBox.setPosition(position);
	textureBox.setPosition(sf::Vector2f(collisionBox.getPosition().x, collisionBox.getPosition().y + 30));
}

bool Player::jump(double deltaTime)
{
	if (isOnPlatform)
	{
		spriteIndex.x = 0;
		spriteIndex.y = 1;
		velocity.y =  -400;
		isOnPlatform = false;
		isJumping = true;
		return true;
	}
	return false;
}

void Player::slide()
{
	if (!isSliding && !isJumping)
	{
		spriteIndex.x = 0;
		spriteIndex.y = 2;
		isSliding = true;
		slideTime = 0;
		collisionBox.setSize(sf::Vector2f(140, 80));
		collisionBox.setOrigin(sf::Vector2f(collisionBox.getSize().x / 2, collisionBox.getSize().y));
	}
}

sf::Vector2f Player::getPosition()
{
	return collisionBox.getPosition();
}

sf::Vector2f Player::getSize()
{
	return collisionBox.getSize();
}

sf::View* Player::getView()
{
	return &view;
}

void Player::update(sf::RenderWindow& window, const double& deltaTime)
{


	/*Ustaw pozycjê gracza w oparciu o prêdkoœæ*/
	time += deltaTime;
	setPosition(sf::Vector2f(getPosition().x + (velocity.x * (float)deltaTime), getPosition().y + (velocity.y) * (float)deltaTime));
	if (!isOnPlatform)
	{
		if (velocity.y < 4700)
		{
			if (velocity.y == 0 && isJumping)
			{
				isJumping = false;
				isFalling = true;
			}
			velocity.y += (float)(pow(25,2)*deltaTime);
		}
	}

	/*Set up slide stuff*/
	if (isSliding)
	{
		slideTime += deltaTime;
		if (slideTime > 0.64)
		{
			isSliding = false;
			collisionBox.setSize(sf::Vector2f(80, 140));
			collisionBox.setOrigin(sf::Vector2f(collisionBox.getSize().x / 2, collisionBox.getSize().y));
		}
	}

	/*Jeœli gracz wylecia³ poza planszê, spawn na górze planszy*/
	if (getPosition().y > SCREEN_SIZE_Y + 100)
	{
		dynamic_cast<Game*>(gameState)->EndGame("GAME OVER");
	}

	if (getPosition().x > 9000)
	{
		dynamic_cast<Game*>(gameState)->EndGame("YOU WON");
	}

	/*Jeœli gracz zszed³ z platformy, spadaj*/
	if ((currentPlatform != nullptr) &&
		((getPosition().x < currentPlatform->getPosition().x - currentPlatform->getSize().x / 2)
		|| getPosition().x > currentPlatform->getPosition().x + currentPlatform->getSize().x / 2))
	{
		isOnPlatform = false;
		isJumping = false;
		isFalling = true;
	}

	/*Prze³¹cz klatkê animacji*/
	if (time > 0.04)
	{
		time = 0;
		spriteIndex.x++;

		/*Jeœli gracz skacze, wstrzymaj animacjê skoku*/
		if (spriteIndex.y == 1)
		{
			if (velocity.y < 0)
			{
				if (spriteIndex.x > 8)
				{
					spriteIndex.x = 8;
				}
			}

			else
			{
				if (spriteIndex.x > 15)
				{
					spriteIndex.x = 15;
				}
			}
		}

		else if (spriteIndex.y == 2)
		{
			int x = 0;
		}

		if (spriteIndex.x == 16)
		{
			if (spriteIndex.y != 0)
			{
				spriteIndex.y = 0;
			}
			spriteIndex.x = 0;
		}
		setSprite(spriteIndex);
	}

	/*Ustaw view*/
	view.setCenter(collisionBox.getPosition().x, SCREEN_SIZE_Y / 2);
}



void Player::draw(sf::RenderWindow& window)
{
	window.setView(view);

	window.draw(textureBox);

	#if(_DEBUG)
	window.draw(collisionBox);
	#endif
}

void Player::setSprite(sf::Vector2f spriteIndex)
{
	intRect.left = intRect.width * (int)spriteIndex.x;
	intRect.top = intRect.height * (int)spriteIndex.y;
	textureBox.setTextureRect(intRect);
}

void Player::setIsOnPlatform(bool cond)
{
	if (cond == true)
	{
		velocity.y = 0;
		if (!isSliding)
		{
			spriteIndex.y = 0;
		}
	}
	isOnPlatform = cond;
}

void Player::setIsJumping(bool cond)
{
	isJumping = cond;
}

void Player::setIsFalling(bool cond)
{
	isFalling = cond;
}

void Player::setViewForPlayer()
{
	view.setCenter(collisionBox.getPosition().x, SCREEN_SIZE_Y / 2);
}

bool Player::getIsOnPlatform()
{
	return isOnPlatform;
}

bool Player::getIsJumping()
{
	return isJumping;
}

bool Player::getIsFalling()
{
	return isFalling;
}

void Player::setCurrentPlatform(GameObject* platform)
{
	currentPlatform = platform;
}