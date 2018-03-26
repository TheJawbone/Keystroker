#include "EndGameMenu.hpp"

void EndGameMenu::setTitle(std::string str)
{
	gameOverLabel.setTextString(str);
}

void EndGameMenu::setScore(int score)
{
	this->score = score;
}

void EndGameMenu::setBadKeys(int keys)
{
	badkeys = keys;
}

void EndGameMenu::setGoodKeys(int keys)
{
	goodkeys = keys;
}

void EndGameMenu::resetClock()
{
	clock.restart();
}

EndGameMenu::EndGameMenu(GameMaster* master)
	:GameState(master)
{
	int offset = 450;

	gameOverLabel.setTextPosition(sf::Vector2f(450, 100));
	gameOverLabel.setTextCharacterSize(80);
	gameOverLabel.setTextFillColor(sf::Color::White);
	gameOverLabel.setTextString("GAME OVER");
	gui.add(gameOverLabel);

	ScoreLabel.setTextPosition(sf::Vector2f(122.0f + (float)offset, 300.0f));
	ScoreLabel.setTextCharacterSize(50);
	ScoreLabel.setTextFillColor(sf::Color::White);
	ScoreLabel.setTextString("SCORE: " + std::string(std::to_string(score)));
	gui.add(ScoreLabel);

	BadKeysLabel.setTextPosition(sf::Vector2f( (float)offset, 350.0f));
	BadKeysLabel.setTextCharacterSize(50);
	BadKeysLabel.setTextFillColor(sf::Color::White);
	BadKeysLabel.setTextString("GOOD KEYS: " + std::string(std::to_string(goodkeys)));
	gui.add(BadKeysLabel);

	GoodKeysLabel.setTextPosition(sf::Vector2f(47.0f + (float)offset, 400.0f));
	GoodKeysLabel.setTextCharacterSize(50);
	GoodKeysLabel.setTextFillColor(sf::Color::White);
	GoodKeysLabel.setTextString("BAD KEYS: " + std::string(std::to_string(badkeys)));
	gui.add(GoodKeysLabel);

	goback.setTextPosition(sf::Vector2f(47.0f + (float)offset, 550.0f));
	goback.setTextCharacterSize(50);
	goback.setTextFillColor(sf::Color::White);
	goback.setTextString("Press ESC to exit");
	gui.add(goback);
}

void EndGameMenu::update(sf::RenderWindow & window, const double & deltaTiem)
{
	ScoreLabel.setTextString("SCORE: " + std::string(std::to_string(score)));
	BadKeysLabel.setTextString("GOOD KEYS: " + std::string(std::to_string(goodkeys)));
	GoodKeysLabel.setTextString("BAD KEYS: " + std::string(std::to_string(badkeys)));
	goback.setTextString("Press ESC to exit");

	if (KeyboardEvents::isKeyPressed(27) ||
		MouseEventsHandler::isButtonPressedOnce(sf::Mouse::Button::Left) || KeyboardEvents::isKeyPressed(' '))
	{
		if(dynamic_cast<Game*>(getGameMaster()->getGameState(GameMaster::GameScreenState)))
			dynamic_cast<Game*>(getGameMaster()->getGameState(GameMaster::GameScreenState))->stopSound();
	
		getGameMaster()->changeGameState(GameMaster::MainMenuState);
	}

}
