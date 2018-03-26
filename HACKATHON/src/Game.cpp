#include "GameMaster.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Platform.hpp"
#include "Background.hpp"
#include "Foreground.hpp"
#include <cmath>
#include <random>
#include <iostream>
#include "EmptyObstacle.hpp"

void Game::addObstacle(Obstacle* obstacle)
{
	gameObjects.push_back(obstacle);
	obstaclesList.push_back(obstacle);
}

void Game::createPlatform(sf::Vector2f position, sf::Vector2f size, std::string fileName)
{
	Platform* platform = new Platform(this, position, size, fileName);
	gameObjects.push_back(platform);
}

void Game::createSpinningKnifes(sf::Vector2f position, sf::Vector2f size, std::string fileName)
{
	SpinningKnifes* knifes = new SpinningKnifes(this, position, size, fileName);
	gameObjects.push_back(knifes);
}

void Game::createJumpObstacle(char keyToPress, float range, int score, sf::Vector2f position)
{
	JumpObstacle* jump = new JumpObstacle(this, keyToPress, range, score, position);
	addObstacle(jump);
}

void Game::createSlideObstacle(char keyToPress, float range, int score, sf::Vector2f position)
{
	SlideObstacle* slide = new SlideObstacle(this, keyToPress, range, score, position);
	addObstacle(slide);
}

void Game::createEmptyObstacle(char keyToPress, float range, int score, sf::Vector2f position)
{
	EmptyObstacle* empty = new EmptyObstacle(this, keyToPress, range, score, position);
	addObstacle(empty);
}

void Game::stopSound()
{

	sound.stop();

}

void Game::setScore(unsigned int score)
{
	scoreValueLabel.setTextString(std::to_string(score));
}
 
void Game::setPassedObstacles(unsigned int score)
{
	passedObstaclesValueLabel.setTextString(std::to_string(score));
}

void Game::setFailedObstacles(unsigned int score)
{
	failedObstaclesValueLabel.setTextString(std::to_string(score));
}

void Game::EndGame(std::string text)
{
	EndGameMenu* end = dynamic_cast<EndGameMenu*>(getGameMaster()->getGameState(GameMaster::EndGameScreenState));

	end->setBadKeys(failObstVal);
	end->setGoodKeys(goodObstVal);
	end->setScore(scoreVal);
	end->resetClock();
	end->setTitle(text);
	getGameMaster()->changeGameState(GameMaster::EndGameScreenState);

}

void Game::upObstacle(sf::RenderWindow &window, double deltaTime)
{

	for (auto iter2 = obstaclesList.begin(); iter2 != obstaclesList.end(); iter2++)
	{
		(*iter2)->drawKeyVisualization(window);
	}

	if (delayKeyEntered.getElapsedTime().asMilliseconds() > delayKeyPreesed)
	{

		auto iter = obstaclesList.begin();
		if (obstaclesList.size() != 0)
		{

#if ( _DEBUG )
			(*iter)->showRange(window);
#endif		
			if ((*iter)->isInRange(player->getPosition()))
				(*iter)->getKeyVisualization()->highlight();

			if (!(*iter)->wasPressed() && KeyboardEvents::isKeyPressed((*iter)->getKeyNeedToPress()))
			{
				if ((*iter)->isInRange(player->getPosition()))
				{
					
					if ((*iter)->doPlayerAction(player,deltaTime))
					{
						(*iter)->pressGoodButton();
						goodObstVal++;
						comboValue++;
						scoreVal += (*iter)->getScore();
						if (obstaclesList.size() > 1)
						{
							obstaclesList.erase(obstaclesList.begin());
							return;

						}
						else
						{
							obstaclesList.clear();
						}
					}
					return;
				}
				else
				{
					if ((*iter)->getScore())
					{
						failObstVal++;
						comboValue = 0;
					}

				}

				delayKeyEntered.restart();
				return;

			}
			else if (KeyboardEvents::isEmpty() == false)
			{
				if ((*iter)->getScore())
				{
					failObstVal++;
					comboValue=0;
				}
				delayKeyEntered.restart();
				if ((*iter)->isInRange(player->getPosition()))
					if (obstaclesList.size() > 1)
					{
						obstaclesList.erase(obstaclesList.begin());
					}
					else
					{
						obstaclesList.clear();
					}
				return;
			
			}
				if (KeyboardEvents::isEmpty() == true && player->getPosition().x > (*iter)->getPosition().x  + (*iter)->getTriggerRange())
				{
					if ((*iter)->getScore() && !(*iter)->wasPressed())
					{
						failObstVal++;
						comboValue = 0;
					}

					(*iter)->pressGoodButton();

					if (obstaclesList.size() > 1)
					{
						obstaclesList.erase(obstaclesList.begin());
					}
					else
					{
						obstaclesList.clear();
					}
					return;
				}


		}

	}
}

void Game::addKeyToList(char character)
{
	characters.push_back(character);
}

char Game::drawRandomCharacter()
{
	if (characters.size())
	{
		std::random_device device;
		std::mt19937 generator(device());
		std::uniform_int_distribution<int> distribution(0, (int)characters.size() - 1);
		return characters[distribution(generator)];
	}
	return 0;
}

Game::Game(GameMaster* master, std::vector<char> charkey)
	:GameState(master)
{
	/*Sounds*/
	buffer.loadFromFile("../sounds/test1.wav");
	sound.setBuffer(buffer);
	gameStart = true;

	startVal = false;


	failObstVal = goodObstVal = 0;

	/*Background*/
	Background* background = new Background(this);
	gameObjects.push_back(background);

	/*Player*/
	player = new Player(this);
	gameObjects.push_back(player);

	/*Foreground*/
	/*Foreground* foreground = new Foreground(this);
	foreground->setView(*player->getView());
	gameObjects.push_back(foreground);*/

	if (charkey.size() == 0)
	{
		addKeyToList('A');
		addKeyToList('B');
		addKeyToList('C');
		addKeyToList('D');
		addKeyToList('E');
		addKeyToList('F');
		addKeyToList('G');
		addKeyToList('H');
		addKeyToList('I');
		addKeyToList('J');
		addKeyToList('K');
		addKeyToList('L');
		addKeyToList('M');
		addKeyToList('O');
		addKeyToList('P');
		addKeyToList('Q');
		addKeyToList('R');
		addKeyToList('S');
		addKeyToList('T');
		addKeyToList('U');
	}
	for (auto iter = charkey.begin(); iter != charkey.end(); iter++)
	{
		addKeyToList(*iter);
	}


	createPlatform(sf::Vector2f(500, 300), sf::Vector2f(1000, 40), "platform800x40x1.png");
	createPlatform(sf::Vector2f(1000, 300), sf::Vector2f(400, 40), "platform400x40x1.png");
	createPlatform(sf::Vector2f(1480, 350), sf::Vector2f(500, 40), "platform400x40x1.png");
	createPlatform(sf::Vector2f(1960, 400), sf::Vector2f(500, 40), "platform400x40x1.png");
	createPlatform(sf::Vector2f(2440, 450), sf::Vector2f(400, 40), "platform400x40x1.png");
	createPlatform(sf::Vector2f(3110, 400), sf::Vector2f(900, 40), "platform800x40x1.png");
	createPlatform(sf::Vector2f(4070, 600), sf::Vector2f(900, 40), "platform800x40x1.png");
	createPlatform(sf::Vector2f(4750, 500), sf::Vector2f(440, 40), "platform400x40x1.png");
	createPlatform(sf::Vector2f(5230, 450), sf::Vector2f(440, 40), "platform400x40x1.png");
	createPlatform(sf::Vector2f(5470, 400), sf::Vector2f(440, 40), "platform400x40x1.png");
	createPlatform(sf::Vector2f(5710, 350), sf::Vector2f(440, 40), "platform400x40x1.png");
	createPlatform(sf::Vector2f(5950, 300), sf::Vector2f(440, 40), "platform400x40x1.png");
	createPlatform(sf::Vector2f(6190, 250), sf::Vector2f(440, 40), "platform400x40x1.png");
	createPlatform(sf::Vector2f(6430, 200), sf::Vector2f(280, 40), "platform200x40x1.png");
	createPlatform(sf::Vector2f(7150, 600), sf::Vector2f(1200, 40), "platform800x40x1.png");
	createPlatform(sf::Vector2f(8750, 550), sf::Vector2f(2000, 40), "platform800x40x1.png");

	createJumpObstacle(drawRandomCharacter(), 40, 25, sf::Vector2f(1120, 300));
	createJumpObstacle(drawRandomCharacter(), 40, 25, sf::Vector2f(1600, 350));
	createJumpObstacle(drawRandomCharacter(), 40, 25, sf::Vector2f(2080, 400));
	createJumpObstacle(drawRandomCharacter(), 40, 25, sf::Vector2f(2560, 450));
	createJumpObstacle(drawRandomCharacter(), 40, 25, sf::Vector2f(3530, 400));
	createJumpObstacle(drawRandomCharacter(), 40, 25, sf::Vector2f(4480, 600));
	createJumpObstacle(drawRandomCharacter(), 40, 25, sf::Vector2f(4970, 500));
	createJumpObstacle(drawRandomCharacter(), 40, 25, sf::Vector2f(5210, 450));
	createJumpObstacle(drawRandomCharacter(), 40, 25, sf::Vector2f(5440, 400));
	createJumpObstacle(drawRandomCharacter(), 40, 25, sf::Vector2f(5680, 350));
	createJumpObstacle(drawRandomCharacter(), 40, 25, sf::Vector2f(5930, 300));
	createJumpObstacle(drawRandomCharacter(), 40, 25, sf::Vector2f(6160, 250));
	createJumpObstacle(drawRandomCharacter(), 40, 25, sf::Vector2f(6400, 200));
	createJumpObstacle(drawRandomCharacter(), 40, 25, sf::Vector2f(6400, 200));
	createJumpObstacle(drawRandomCharacter(), 40, 25, sf::Vector2f(7720, 600));

	createSpinningKnifes(sf::Vector2f(3100, 400), sf::Vector2f(200, 200), "wirujaceOstrzeZnikad.png");
	createSpinningKnifes(sf::Vector2f(4060, 600), sf::Vector2f(200, 200), "wirujaceOstrzeZnikad.png");
	createSpinningKnifes(sf::Vector2f(6950, 600), sf::Vector2f(200, 200), "wirujaceOstrzeZnikad.png");
	createSpinningKnifes(sf::Vector2f(7170, 600), sf::Vector2f(200, 200), "wirujaceOstrzeZnikad.png");
	createSpinningKnifes(sf::Vector2f(7410, 600), sf::Vector2f(200, 200), "wirujaceOstrzeZnikad.png");
	createSpinningKnifes(sf::Vector2f(7650, 600), sf::Vector2f(200, 200), "wirujaceOstrzeZnikad.png");
	createSpinningKnifes(sf::Vector2f(7940, 550), sf::Vector2f(200, 200), "wirujaceOstrzeZnikad.png");
	createSpinningKnifes(sf::Vector2f(8150, 550), sf::Vector2f(200, 200), "wirujaceOstrzeZnikad.png");


	createSlideObstacle(drawRandomCharacter(), 60, 25, sf::Vector2f(3050, 400));
	createSlideObstacle(drawRandomCharacter(), 60, 25, sf::Vector2f(4010, 600));
	createSlideObstacle(drawRandomCharacter(), 60, 25, sf::Vector2f(6900, 600));
	createSlideObstacle(drawRandomCharacter(), 60, 25, sf::Vector2f(7120, 600));
	createSlideObstacle(drawRandomCharacter(), 60, 25, sf::Vector2f(7360, 600));
	createSlideObstacle(drawRandomCharacter(), 60, 25, sf::Vector2f(7600, 600));
	createSlideObstacle(drawRandomCharacter(), 60, 25, sf::Vector2f(7890, 550));
	createSlideObstacle(drawRandomCharacter(), 60, 25, sf::Vector2f(8100, 550));


	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(1240, 300));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(1360, 300));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(1479, 300));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(1720, 350));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(1840, 350));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(1959, 350));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(2185, 400));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(2310, 400));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(2435, 400));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(2685, 450));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(2802, 450));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(2919, 450));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(3171, 450));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(3277, 450));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(3394, 450));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(3630, 400));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(3750, 400));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(3870, 400));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(4110, 400));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(4230, 400));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(4350, 400));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(5100, 600));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(5310, 600));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(5540, 600));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(5790, 600));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(6050, 600));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(6290, 600));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(7020, 600));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(7240, 600));
	createEmptyObstacle(drawRandomCharacter(), 30, 25, sf::Vector2f(7490, 600));

	playOnced = true;


	/*Sort platform/obstacle vector*/
	std::sort(obstaclesList.begin(), obstaclesList.end(), [](Obstacle* a, Obstacle* b) -> bool {
		return a->getPosition().x < b->getPosition().x ;
	});

	comboTextTexture.loadFromFile( "../graphics/combo.png" );
	
	scoreLabel.setTextPosition(sf::Vector2f(10, 10));
	scoreLabel.setTextCharacterSize(30);
	scoreLabel.setTextFillColor(sf::Color::Black);
	scoreLabel.setTextString("SCORE:");
	gui.add(scoreLabel);

	scoreValueLabel.setTextPosition(sf::Vector2f(130, 10));
	scoreValueLabel.setTextCharacterSize(30);
	scoreValueLabel.setTextFillColor(sf::Color::Black);
	scoreValueLabel.setTextString("0");
	gui.add(scoreValueLabel);

	passedObstaclesLabel.setTextPosition(sf::Vector2f(10, 40));
	passedObstaclesLabel.setTextCharacterSize(30);
	passedObstaclesLabel.setTextFillColor(sf::Color::Black);
	passedObstaclesLabel.setTextString("PASSED OBSTACLES:");
	gui.add(passedObstaclesLabel);

	passedObstaclesValueLabel.setTextPosition(sf::Vector2f(332, 40));
	passedObstaclesValueLabel.setTextCharacterSize(30);
	passedObstaclesValueLabel.setTextFillColor(sf::Color::Black);
	passedObstaclesValueLabel.setTextString("0");
	gui.add(passedObstaclesValueLabel);

	failedObstaclesLabel.setTextPosition(sf::Vector2f(10, 70));
	failedObstaclesLabel.setTextCharacterSize(30);
	failedObstaclesLabel.setTextFillColor(sf::Color::Black);
	failedObstaclesLabel.setTextString("FAILED OBSTACLES:");
	gui.add(failedObstaclesLabel);

	failedObstaclesValueLabel.setTextPosition(sf::Vector2f(316, 70));
	failedObstaclesValueLabel.setTextCharacterSize(30);
	failedObstaclesValueLabel.setTextFillColor(sf::Color::Black);
	failedObstaclesValueLabel.setTextString("0");
	gui.add(failedObstaclesValueLabel);

	comboTextButton.setBackgroundPosition(sf::Vector2f(230,600));
	comboTextButton.setBackgroundSize(sf::Vector2f(600,150));
	comboTextButton.setBackgroundTexture(comboTextTexture);
	comboTextButton.setBackgroundCoverTexture(comboTextTexture);
	gui.add(comboTextButton);

	startMessageLabel.setTextPosition(sf::Vector2f(800, 700));
	startMessageLabel.setTextCharacterSize(30);
	startMessageLabel.setTextFillColor(sf::Color::Black);
	startMessageLabel.setTextString("PRESS SPACEBAR TO START");
	gui.add(startMessageLabel);

	comboGraphicLabel.setTextPosition(sf::Vector2f(50, 600));
	gui.add(comboGraphicLabel);

	failObstVal = goodObstVal = 0;
	 delayKeyPreesed= 250;

	 scoreVal = 0;
}

void Game::update(sf::RenderWindow & window, const double& deltaTiem)
{
	if (comboValue < 3)
	{
		comboTextButton.setBackgroundSize(sf::Vector2f(0, 0));
	}

	else
	{
		comboTextButton.setBackgroundSize(sf::Vector2f(600, 150));
	}
	if (KeyboardEvents::isKeyPressed(27))
	{
		stopSound();
		getGameMaster()->changeGameState(GameMaster::MainMenuState);
	}

	if (startVal == false && KeyboardEvents::isKeyPressed(' '))
	{
		startVal = true;
		startMessageLabel.setTextString("");
		failObstVal--;
	}
	if (playOnced)
	{
		player->setViewForPlayer();
		playOnced = false;
	}
	if (startVal)
	{
		
		if (gameStart)
		{
			sound.play();
			gameStart = false;
		}
		/*Update objects*/
		for (auto iter = gameObjects.begin(); iter != gameObjects.end(); iter++)
		{
			(*iter)->update(window, deltaTiem);

			/*Gracz wszed³ na platformê*/
			if (((abs(player->getPosition().y - (*iter)->getPosition().y)) < 10)
				&& (player->getPosition().x > (*iter)->getPosition().x - (*iter)->getSize().x / 2)
				&& (player->getPosition().x < (*iter)->getPosition().x + (*iter)->getSize().x / 2)
				&& player != *iter)
			{
				if (!player->getIsJumping())
				{
					player->setCurrentPlatform(*iter);
					player->setIsOnPlatform(true);
					player->setPosition(sf::Vector2f(player->getPosition().x, (*iter)->getPosition().y));
				}
			}
		}
	}


	/*Draw objects*/
	for (auto iter = gameObjects.begin(); iter != gameObjects.end(); iter++)
	{
		(*iter)->draw(window);
	}


	upObstacle(window,deltaTiem);
	comboGraphicLabel.setTextValue(comboValue);

	window.setView(window.getDefaultView());
	window.draw(gui);

	setScore(scoreVal);
	setPassedObstacles(goodObstVal);
	setFailedObstacles(failObstVal);

}

Game::~Game()
{
	delete player;
	for (auto iter = gameObjects.begin(); iter != gameObjects.end(); iter++)
	{
		delete (*iter);
	}
}

