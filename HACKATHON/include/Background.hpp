#pragma  once

#include "GameObject.hpp"
#include "Globals.hpp"

class Background : public GameObject
{
private:
	sf::RectangleShape bg1;		//main bg
	sf::RectangleShape bg2;		//trees
	sf::RectangleShape bg6;		//trees 2
	sf::RectangleShape bg3;		//clouds 1
	sf::RectangleShape bg4;		//clouds 2
	sf::RectangleShape bg5;		//white

	sf::Texture tex1;
	sf::Texture tex2;
	sf::Texture tex3;
	sf::Texture tex4;

public:
	Background(Game* gameState);
	virtual ~Background();

	sf::Vector2f getPosition() { return bg1.getPosition(); }
	sf::Vector2f getSize() { return bg1.getSize(); }

	void draw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window, const double& deltaTime);
};