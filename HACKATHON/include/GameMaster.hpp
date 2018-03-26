#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "Game.hpp"
#include "GameGhost.hpp"
#include "Globals.hpp"
#include "KeyboardEvents.hpp"
#include "MainMenu.hpp"
#include "SplashScreen.hpp"
#include "EndGameMenu.hpp"

class GameMaster {
	
	struct ChangingStateStruct 
	{
		bool needToChangeState;
		GameState* toChangeState;
	};

	ChangingStateStruct makeSomeChange;

	std::vector<GameState*> states;

	sf::RenderWindow window;
	GameState* actualState;

	KeysTextures keysTextures;

public:
	enum GameStatesMenu { GameScreenState, MainMenuState, SplashScreenState, EndGameScreenState, GhostGameState };

	GameMaster();
	void changeGameState(GameStatesMenu state);
	void startGame();

	void reloadGameState(GameStatesMenu gsmenu, std::vector<char> charkey);

	GameState* getGameState(GameStatesMenu state);
	sf::RenderWindow* getRenderWindow();
	KeysTextures* getKeysTextures();
	virtual ~GameMaster();

};