#pragma once
#include "KeyboardEvents.hpp"
#include "MouseEventsHandler.hpp"
#include "GameMaster.hpp"
#include "GameState.hpp"

class EndGameMenu : public GameState {

	int score;
	int badkeys;
	int goodkeys;
	sf::Clock clock;

	Label gameOverLabel;
	Label ScoreLabel;
	Label BadKeysLabel;
	Label GoodKeysLabel;
	Label goback;

public:

	void setTitle(std::string str);
	void setScore(int score);
	void setBadKeys(int keys);
	void setGoodKeys(int keys);
	void resetClock();

	EndGameMenu(GameMaster* master);
	void update(sf::RenderWindow &window, const double& deltaTiem);

};