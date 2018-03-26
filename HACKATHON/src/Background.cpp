
#include "Background.hpp"

Background::Background(Game* gameState)
	: GameObject(gameState)
{
	tex1.loadFromFile("../graphics/backgroundMain.png");

	bg1.setSize(sf::Vector2f(SCREEN_SIZE_X, SCREEN_SIZE_Y));
	bg1.setPosition(sf::Vector2f(0, 0));
	bg1.setTexture(&tex1);

	tex2.loadFromFile("../graphics/trees.png");

	bg2.setSize(sf::Vector2f(SCREEN_SIZE_X, SCREEN_SIZE_Y - 100));
	bg2.setPosition(sf::Vector2f(SCREEN_SIZE_X, 200));
	bg2.setTexture(&tex2);

	bg6.setSize(sf::Vector2f(SCREEN_SIZE_X, SCREEN_SIZE_Y - 100));
	bg6.setPosition(sf::Vector2f(0, 200));
	bg6.setTexture(&tex2);

	tex3.loadFromFile("../graphics/clouds.png");

	bg3.setSize(sf::Vector2f(SCREEN_SIZE_X, 364));
	bg3.setPosition(sf::Vector2f(SCREEN_SIZE_X, 0));
	bg3.setTexture(&tex3);

	bg4.setSize(sf::Vector2f(SCREEN_SIZE_X, 364));
	bg4.setPosition(sf::Vector2f(0, 0));
	bg4.setTexture(&tex3);

	bg5.setSize(sf::Vector2f(SCREEN_SIZE_X, SCREEN_SIZE_Y));
	bg5.setPosition(sf::Vector2f(0, 0));
	bg5.setFillColor(sf::Color(255, 255, 255, 50));
	
}

Background::~Background()
{

}

void Background::draw(sf::RenderWindow& window)
{
	window.draw(bg1);
	window.draw(bg3);
	window.draw(bg4);
	window.draw(bg5);
	window.draw(bg2);
	window.draw(bg6);
}

void Background::update(sf::RenderWindow& window, const double& deltaTime)
{
	bg2.move(sf::Vector2f(float(-100 * deltaTime), 0));
	bg6.move(sf::Vector2f(float(-100 * deltaTime), 0));
	bg3.move(sf::Vector2f(float(-25 * deltaTime), 0));
	bg4.move(sf::Vector2f(float(-25 * deltaTime), 0));

	if (bg2.getPosition().x < -SCREEN_SIZE_X)
	{
		bg2.setPosition(sf::Vector2f(SCREEN_SIZE_X, 200));
	}

	if (bg6.getPosition().x < -SCREEN_SIZE_X)
	{
		bg6.setPosition(sf::Vector2f(SCREEN_SIZE_X, 200));
	}

	if (bg3.getPosition().x < -SCREEN_SIZE_X)
	{
		bg3.setPosition(sf::Vector2f(SCREEN_SIZE_X, 0));
	}

	if (bg4.getPosition().x < -SCREEN_SIZE_X)
	{
		bg4.setPosition(sf::Vector2f(SCREEN_SIZE_X, 0));
	}
}