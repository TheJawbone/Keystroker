#include "MainMenu.hpp"

#include "GameMaster.hpp"

#include <iostream>

void MainMenu::startGame()
{

	std::vector<char> charkey;

	switch (dificultyLevel)
	{
	case 2:
		charkey.push_back('Q');
		charkey.push_back('W');
		charkey.push_back('E');
		charkey.push_back('P');
		charkey.push_back('O');
		charkey.push_back('I');
		break;
	case 3:
		charkey.push_back('Q');
		charkey.push_back('W');
		charkey.push_back('E');
		charkey.push_back('P');
		charkey.push_back('O');
		charkey.push_back('I');

		charkey.push_back('A');
		charkey.push_back('S');
		charkey.push_back('D');
		charkey.push_back('J');
		charkey.push_back('K');
		charkey.push_back('L');
		break;
	case 4:

		charkey.push_back('Q');
		charkey.push_back('W');
		charkey.push_back('E');
		charkey.push_back('P');
		charkey.push_back('O');
		charkey.push_back('I');

		charkey.push_back('A');
		charkey.push_back('S');
		charkey.push_back('D');
		charkey.push_back('J');
		charkey.push_back('K');
		charkey.push_back('L');

		charkey.push_back('Z');
		charkey.push_back('X');
		charkey.push_back('C');
		charkey.push_back('B');
		charkey.push_back('N');
		charkey.push_back('M');
		break;
	case 5:

		charkey.push_back('Q');
		charkey.push_back('W');
		charkey.push_back('E');
		charkey.push_back('P');
		charkey.push_back('O');
		charkey.push_back('I');

		charkey.push_back('A');
		charkey.push_back('S');
		charkey.push_back('D');
		charkey.push_back('J');
		charkey.push_back('K');
		charkey.push_back('L');

		charkey.push_back('Z');
		charkey.push_back('X');
		charkey.push_back('C');
		charkey.push_back('B');
		charkey.push_back('N');
		charkey.push_back('M');

		charkey.push_back('R');
		charkey.push_back('T');
		charkey.push_back('Y');
		charkey.push_back('U');
		charkey.push_back('F');
		charkey.push_back('G');
		charkey.push_back('H');

		charkey.push_back('V');
		break;
	default:
		charkey.push_back('Q');
		charkey.push_back('P');
		break;
	}
	charkey.push_back('P');

	getGameMaster()->reloadGameState(GameMaster::GameStatesMenu::GameScreenState,charkey);
	getGameMaster()->changeGameState(GameMaster::GameStatesMenu::GameScreenState);
}

void MainMenu::exitGame()
{
	getGameMaster()->getRenderWindow()->close();
}

void MainMenu::increaseDificultyLevel()
{
	if (dificultyLevel < 5)
	{
		std::cout << "Level up" << std::endl;
		dificultyLevel++;
		dificultyLevelValueGraphicLabel.setTextValue(dificultyLevel);
	}
}

void MainMenu::decreaseDificultyLevel()
{
	if (dificultyLevel > 1)
	{
		std::cout << "Level down" << std::endl;
		dificultyLevel--;
		dificultyLevelValueGraphicLabel.setTextValue(dificultyLevel);
	}
}

void MainMenu::update(sf::RenderWindow& window, const double & deltaTiem)
{
	window.draw(bg);

	if (KeyboardEvents::isKeyPressed(' '))
	{
		startGame();
	}

	if (KeyboardEvents::isKeyPressed('*'))
	{
		std::vector<char> charkey;
		charkey.push_back('Q');
		charkey.push_back('W');
		charkey.push_back('E');
		charkey.push_back('P');
		charkey.push_back('O');
		charkey.push_back('I');

		charkey.push_back('A');
		charkey.push_back('S');
		charkey.push_back('D');
		charkey.push_back('J');
		charkey.push_back('K');
		charkey.push_back('L');

		charkey.push_back('Z');
		charkey.push_back('X');
		charkey.push_back('C');
		charkey.push_back('B');
		charkey.push_back('N');
		charkey.push_back('M');

		charkey.push_back('R');
		charkey.push_back('T');
		charkey.push_back('Y');
		charkey.push_back('U');
		charkey.push_back('F');
		charkey.push_back('G');
		charkey.push_back('H');

		charkey.push_back('V');
		getGameMaster()->reloadGameState(GameMaster::GameStatesMenu::GhostGameState, charkey);
		getGameMaster()->changeGameState(GameMaster::GameStatesMenu::GhostGameState);
	}
}

MainMenu::MainMenu(GameMaster * master)
	:GameState(master)
{
	dificultyLevel = 0;

	startGameTexture.loadFromFile("../graphics/startButton.png");
	exitGameTexture.loadFromFile("../graphics/quitButton.png");
	startGameCoverTexture.loadFromFile("../graphics/startButton_hoover.png");
	exitGameCoverTexture.loadFromFile("../graphics/quitButton_hoover.png");

	arrowLeftTexture.loadFromFile("../graphics/arrowLeft.png");
	arrowRightTexture.loadFromFile("../graphics/arrowRight.png");

	dificultyLevel = 1;
	dificultyLevelValueGraphicLabel.setTextValue(dificultyLevel);
	startGameButton.setBackgroundPosition(sf::Vector2f(970, 220));
	startGameButton.setBackgroundSize(sf::Vector2f(200, 60));
	startGameButton.setBackgroundTexture(startGameTexture);
	startGameButton.setBackgroundCoverTexture(startGameCoverTexture);
	startGameButton.connect(std::bind(&MainMenu::startGame, this));
	gui.add(startGameButton);

	exitGameButton.setBackgroundPosition(sf::Vector2f(970, 310));
	exitGameButton.setBackgroundSize(sf::Vector2f(200, 60));
	exitGameButton.setBackgroundTexture(exitGameTexture);
	exitGameButton.setBackgroundCoverTexture(exitGameCoverTexture);
	exitGameButton.connect(std::bind(&MainMenu::exitGame, this));
	gui.add(exitGameButton);

	decreaseDificultyLevelButton.setBackgroundPosition(sf::Vector2f(500, 650));
	decreaseDificultyLevelButton.setBackgroundSize(sf::Vector2f(50, 50));
	decreaseDificultyLevelButton.setBackgroundTexture(arrowLeftTexture);
	decreaseDificultyLevelButton.setBackgroundCoverTexture(arrowLeftTexture);
	decreaseDificultyLevelButton.connect(std::bind(&MainMenu::decreaseDificultyLevel, this));
	gui.add(decreaseDificultyLevelButton);

	increaseDificultyLevelButton.setBackgroundPosition(sf::Vector2f(800, 650));
	increaseDificultyLevelButton.setBackgroundSize(sf::Vector2f(50, 50));
	increaseDificultyLevelButton.setBackgroundTexture(arrowRightTexture);
	increaseDificultyLevelButton.setBackgroundCoverTexture(arrowRightTexture);
	increaseDificultyLevelButton.connect(std::bind(&MainMenu::increaseDificultyLevel, this));
	gui.add(increaseDificultyLevelButton);

	dificultyLevelValueGraphicLabel.setTextPosition(sf::Vector2f(625, 600));
	dificultyLevelValueGraphicLabel.setTextValue(1);
	gui.add(dificultyLevelValueGraphicLabel);

	dificultyTextLabel.setTextPosition(sf::Vector2f(550, 560));
	dificultyTextLabel.setTextCharacterSize(30);
	dificultyTextLabel.setTextFillColor(sf::Color::Red);
	dificultyTextLabel.setTextString("DIFICULTY LEVEL:");
	gui.add(dificultyTextLabel);

	bgTexture.loadFromFile("../graphics/StartScreenFinal.png");
	bg.setTexture(&bgTexture);
	bg.setSize(sf::Vector2f(SCREEN_SIZE_X, SCREEN_SIZE_Y));
	bg.setPosition(0, 0);
}
