#pragma once

#include <SFML/Graphics.hpp>

struct GameObject
{
	enum class Type
	{
		Platform,
		Slide,
		Empty,
	};

	sf::Vector2f position;
	sf::Vector2f origin;
	Type type;
};

typedef std::vector< GameObject > GameObjects;

class File
{
public:

	static void save(const GameObjects& gameObjects, const char* path);
	static GameObjects load(const char* path);

private:

};