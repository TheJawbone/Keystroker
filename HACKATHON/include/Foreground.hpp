#pragma  once

#include "GameObject.hpp"
#include "Globals.hpp"

class Foreground : public GameObject
{
private:
	sf::RectangleShape bg1;		//main bg
	sf::RectangleShape bg2;		//trees
	sf::RectangleShape bg3;		//trees 2

	sf::Texture tex1;
	sf::Texture tex2;
	sf::Texture tex3;

	sf::View view;

	float rotVel1;
	float rotVel2;
	float rotVel3;

	int combo;

public:
	Foreground(Game* gameState);
	virtual ~Foreground();

	void setCombo(int combo) { this->combo = combo; }
	void setView(sf::View view) { this->view = view; }
	sf::Vector2f getPosition() { return bg1.getPosition(); }
	sf::Vector2f getSize() { return bg1.getSize(); }

	void draw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window, const double& deltaTime);
};