#pragma once
#include "GameState.hpp"
#include "Globals.hpp"

class MainMenu: public GameState{


	sf::Texture startGameTexture;
	sf::Texture exitGameTexture;
	sf::Texture startGameCoverTexture;
	sf::Texture exitGameCoverTexture;

	sf::Texture arrowLeftTexture;
	sf::Texture arrowRightTexture;

	Button startGameButton;
	Button exitGameButton;
	Button increaseDificultyLevelButton;
	Button decreaseDificultyLevelButton;
	GraphicLabel dificultyLevelValueGraphicLabel;
	Label dificultyTextLabel;

	sf::Texture bgTexture;
	sf::RectangleShape bg;

	void startGame();
	void exitGame();

	void increaseDificultyLevel();
	void decreaseDificultyLevel();

	int dificultyLevel;

public:
	void update(sf::RenderWindow &window, const double& deltaTiem);

	MainMenu(GameMaster* master);

};