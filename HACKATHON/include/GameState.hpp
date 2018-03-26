#pragma once
#include <SFML/Graphics.hpp>

#include "GUI.hpp"

class GameMaster;
class GameState {

	GameMaster* master;

protected:

	GUI gui;

public:
	GameState(GameMaster* master);

	void updateState(sf::RenderWindow &window, const double& deltaTiem);
	virtual void update(sf::RenderWindow &window, const double& deltaTiem) = 0;
	
	GameMaster* getGameMaster();

};