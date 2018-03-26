#pragma once

#include <SFML/Graphics.hpp>

#include <Globals.hpp>
#include <Blueprint.hpp>

class Editor
{
public:

	Editor();

	void start();

private:

	enum class ObstacleType
	{
		Platform,
		Slide,
		Empty,
		None
	};

	struct GameObject
	{
		sf::Vector2f position;
		ObstacleType obstacle;
		sf::Sprite sprite;
	};

	Blueprint blueprint;

	sf::Texture platformTexture;
	sf::Texture slideTexture;
	sf::Texture emptyTexture;

	sf::Sprite platformSprite;
	sf::Sprite slideSprite;
	sf::Sprite emptySprite;

	std::vector< GameObject > gameObjects;
	ObstacleType mode;

	void update();
	void draw( sf::RenderWindow& window );

};