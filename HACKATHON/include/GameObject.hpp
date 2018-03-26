#pragma once

#include <SFML/Graphics.hpp>

class Game;
class GameObject
{
protected:
	sf::RectangleShape textureBox;
	sf::RectangleShape collisionBox;
	sf::Texture texture;
	bool detectCollisions;
	Game* gameState;

public:
	GameObject(Game* gameState);
	virtual ~GameObject();

	virtual void setPosition(sf::Vector2f position);

	virtual sf::Vector2f getPosition();
	virtual sf::Vector2f getSize();

	virtual void update(sf::RenderWindow& window, const double& deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};