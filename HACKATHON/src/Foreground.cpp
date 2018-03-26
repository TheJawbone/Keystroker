
#include "Foreground.hpp"

Foreground::Foreground(Game* gameState)
	: GameObject(gameState)
{
	tex1.loadFromFile("../graphics/light1.png");

	bg1.setSize(sf::Vector2f(500, 1600));
	bg1.setPosition(sf::Vector2f(SCREEN_SIZE_X / 2, -100));
	bg1.setTexture(&tex1);
	bg1.setOrigin(bg1.getSize().x / 2, 0);

	tex2.loadFromFile("../graphics/light2.png");

	bg2.setSize(sf::Vector2f(500, 1600));
	bg2.setPosition(sf::Vector2f(SCREEN_SIZE_X - 200, -100));
	bg2.setTexture(&tex2);
	bg2.setOrigin(bg2.getSize().x / 2, 0);
	bg2.setRotation(25);

	tex3.loadFromFile("../graphics/light3.png");

	bg3.setSize(sf::Vector2f(500, 1600));
	bg3.setPosition(sf::Vector2f(200, -100));
	bg3.setTexture(&tex3);
	bg3.setOrigin(bg3.getSize().x / 2, 0);
	bg3.setRotation(-35);

	rotVel1 = 0.05f;
	rotVel2 = 0.05f;
	rotVel3 = 0.05f;
}

Foreground::~Foreground()
{

}

void Foreground::draw(sf::RenderWindow& window)
{
	//window.setView(view);
	if (combo >= 1)
	{
		window.draw(bg1);
		if (combo >= 2)
		{
			window.draw(bg2);
			if (combo >= 3)
			{
				window.draw(bg3);
			}
		}
	}
	//window.setView(window.getDefaultView());

	combo = -1;
}

void Foreground::update(sf::RenderWindow& window, const double& deltaTime)
{
	combo++;
	bg1.rotate(rotVel1);
	if (abs(bg1.getRotation()) > 45)
	{
		rotVel1 = -rotVel1;
	}

	bg2.rotate(rotVel2);
	if (abs(bg2.getRotation()) > 45)
	{
		rotVel2 = -rotVel2;
	}

	bg3.rotate(rotVel3);
	if (abs(bg3.getRotation()) > 45)
	{
		rotVel3 = -rotVel3;
	}
}