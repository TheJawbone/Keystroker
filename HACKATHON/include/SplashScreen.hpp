#pragma once
#include "GameState.hpp"
#include "GameMaster.hpp"
#include <string>
#include "Globals.hpp"
#include "KeyboardEvents.hpp"
class SplashScreen : public GameState
{

	sf::Clock changeTime;
	sf::Clock startTime;
	float changeTimeValue;


public:
	void resetClock();
	SplashScreen(GameMaster* master);
	virtual void update(sf::RenderWindow &window, const double& deltaTiem);

};