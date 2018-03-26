#include "GameMaster.hpp"

#include "MouseEventsHandler.hpp"

GameMaster::GameMaster()
:window(sf::VideoMode(SCREEN_SIZE_X, SCREEN_SIZE_Y), "Keystroker!")
{
	window.clear();
	sf::Texture loading;
	loading.loadFromFile("../graphics/Loading.png");
	sf::RectangleShape shape;
	shape.setTexture(&loading);
	shape.setPosition(0, 0);
	shape.setSize(sf::Vector2f(SCREEN_SIZE_X, SCREEN_SIZE_Y));
	window.draw(shape);

	window.display();

	keysTextures['A'].loadFromFile("../graphics/Letters/A.png");
	keysTextures['B'].loadFromFile("../graphics/Letters/B.png");
	keysTextures['C'].loadFromFile("../graphics/Letters/C.png");
	keysTextures['D'].loadFromFile("../graphics/Letters/D.png");
	keysTextures['E'].loadFromFile("../graphics/Letters/E.png");
	keysTextures['F'].loadFromFile("../graphics/Letters/F.png");
	keysTextures['G'].loadFromFile("../graphics/Letters/G.png");
	keysTextures['H'].loadFromFile("../graphics/Letters/H.png");
	keysTextures['I'].loadFromFile("../graphics/Letters/I.png");
	keysTextures['J'].loadFromFile("../graphics/Letters/J.png");
	keysTextures['K'].loadFromFile("../graphics/Letters/K.png");
	keysTextures['L'].loadFromFile("../graphics/Letters/L.png");
	keysTextures['M'].loadFromFile("../graphics/Letters/M.png");
	keysTextures['N'].loadFromFile("../graphics/Letters/N.png");
	keysTextures['O'].loadFromFile("../graphics/Letters/O.png");
	keysTextures['P'].loadFromFile("../graphics/Letters/P.png");
	keysTextures['Q'].loadFromFile("../graphics/Letters/Q.png");
	keysTextures['R'].loadFromFile("../graphics/Letters/R.png");
	keysTextures['S'].loadFromFile("../graphics/Letters/S.png");
	keysTextures['T'].loadFromFile("../graphics/Letters/T.png");
	keysTextures['U'].loadFromFile("../graphics/Letters/U.png");
	keysTextures['V'].loadFromFile("../graphics/Letters/V.png");
	keysTextures['W'].loadFromFile("../graphics/Letters/W.png");
	keysTextures['X'].loadFromFile("../graphics/Letters/X.png");
	keysTextures['Y'].loadFromFile("../graphics/Letters/Y.png");
	keysTextures['Z'].loadFromFile("../graphics/Letters/Z.png");


	std::vector<char> charkey;

	charkey.push_back('P');
	charkey.push_back('W');
	charkey.push_back('Q');
	charkey.push_back('E');
	charkey.push_back('O');
	charkey.push_back('I');

	states.push_back(nullptr);
	states.push_back(new MainMenu(this));
	states.push_back(new SplashScreen(this));
	states.push_back(new EndGameMenu(this));
	states.push_back(new GameGhost(this, charkey));
	makeSomeChange.needToChangeState = true;
	dynamic_cast<SplashScreen*>(states[SplashScreenState])->resetClock();
	makeSomeChange.toChangeState = states[SplashScreenState];


}

void GameMaster::changeGameState(GameStatesMenu state)
{
	makeSomeChange.toChangeState = states[state];
	makeSomeChange.needToChangeState = true;
}

void GameMaster::startGame()
{
	sf::Clock deltaTimeClock;
	double deltaTime = 0;
	while (window.isOpen())
	{
		
		if (makeSomeChange.needToChangeState)
		{
			actualState = makeSomeChange.toChangeState;
		}
		KeyboardEvents::Clear();
		

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if(event.key.code >= 0 && event.key.code < 26)
					KeyboardEvents::AddKey(event.key.code + 'A');
				else 
				{
					switch (event.key.code)
					{
					case sf::Keyboard::Escape:
						KeyboardEvents::AddKey(27);
						break;
					
					case sf::Keyboard::Space:
						KeyboardEvents::AddKey(' ');
						break;

					case sf::Keyboard::BackSpace:
						KeyboardEvents::AddKey('*');
						break;
					}
				}
			}

			MouseEventsHandler::update(event);
		}

		window.clear();
		actualState->update(window, deltaTime);
		actualState->updateState(window, deltaTime);
		window.display();

		MouseEventsHandler::reset();
		deltaTime = deltaTimeClock.restart().asSeconds();
	}
}

void GameMaster::reloadGameState(GameStatesMenu gsmenu, std::vector<char> charkey)
{
	if(states[gsmenu]!= nullptr)
		delete states[gsmenu];

	if(GhostGameState == gsmenu)
		states[gsmenu] = new GameGhost(this, charkey);
	else
		states[gsmenu] = new Game(this,charkey);
}

GameState * GameMaster::getGameState(GameStatesMenu state)
{

	return states[state];
}

sf::RenderWindow* GameMaster::getRenderWindow()
{
	return &window;
}

KeysTextures* GameMaster::getKeysTextures()
{
	return &keysTextures;
}

GameMaster::~GameMaster()
{
	for (auto iter = states.begin(); iter != states.end(); iter++)
	{
		delete (*iter);
	}
}
