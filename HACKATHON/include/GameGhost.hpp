#pragma once
#include "GameMaster.hpp"
#include "KeyboardEvents.hpp"
#include "Game.hpp"

class GameGhost :public Game {

public:
	GameGhost(GameMaster* master, std::vector<char> charkey);
	void upObstacle(sf::RenderWindow &window, double deltaTime);
};
