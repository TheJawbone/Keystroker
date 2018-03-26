#pragma once
#include "GameState.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "Obstacle.hpp"
#include "SlideObstacle.hpp"
#include "EmptyObstacle.hpp"
#include "SpinningKnifes.hpp"
#include "JumpObstacle.hpp"
#include "SlideObstacle.hpp"
#include <SFML\Graphics.hpp>
#include <vector>
#include <stdarg.h>

class Game : public GameState
{
protected:
	Player* player;
	std::vector<GameObject*> gameObjects;
	std::vector<Obstacle*> obstaclesList;
	sf::Clock delayKeyEntered;
	float delayKeyPreesed;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	bool gameStart;
	bool playOnced;
	int comboValue;

	void addObstacle(Obstacle* obstacle);

	void createPlatform(sf::Vector2f position, sf::Vector2f size, std::string fileName);
	void createSpinningKnifes( sf::Vector2f position, sf::Vector2f size, std::string fileName);
	void createJumpObstacle(char keyToPress, float range, int score, sf::Vector2f position);
	void createSlideObstacle(char keyToPress, float range, int score, sf::Vector2f position);
	void createEmptyObstacle(char keyToPress, float range, int score, sf::Vector2f position);
	
	// GUI
	sf::Texture comboTextTexture;

	Label scoreLabel;
	Label scoreValueLabel;
	Label passedObstaclesLabel;
	Label passedObstaclesValueLabel;
	Label failedObstaclesLabel;
	Label failedObstaclesValueLabel;
	Label startMessageLabel;
	Button comboTextButton;
	GraphicLabel comboGraphicLabel;

	unsigned int failObstVal;
	unsigned int goodObstVal;
	unsigned int scoreVal;
	bool startVal;

	void setScore(unsigned int score);
	void setPassedObstacles(unsigned int score);
	void setFailedObstacles(unsigned int score);

	virtual void upObstacle(sf::RenderWindow &window, double deltaTime);
	std::vector< char > characters;
	void addKeyToList(char character);
	char drawRandomCharacter();

public:
	Game(GameMaster* master, std::vector<char> charkey);

	void stopSound();
	void update(sf::RenderWindow &window, const double& deltaTiem);
	void EndGame(std::string text);

	virtual ~Game();
};
