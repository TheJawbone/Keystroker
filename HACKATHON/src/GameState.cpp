#include "GameMaster.hpp"
#include "GameState.hpp"


GameState::GameState(GameMaster * master)
{
	this->master = master;
}

void GameState::updateState(sf::RenderWindow & window, const double & deltaTiem)
{
	gui.update();
	window.draw(gui);
}

GameMaster * GameState::getGameMaster()
{
	return master;
}
