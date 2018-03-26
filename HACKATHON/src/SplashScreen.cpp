#include "SplashScreen.hpp"

#include "MouseEventsHandler.hpp"

void SplashScreen::resetClock()
{
	startTime.restart();
	changeTime.restart();
}

SplashScreen::SplashScreen(GameMaster * master)
	:GameState(master)
{
	changeTimeValue = 5000;
	startTime.restart();
}

void SplashScreen::update(sf::RenderWindow & window, const double & deltaTiem)
{
	float tim = (float)startTime.getElapsedTime().asMilliseconds();
	int frame = (int)ceil((tim /40.0f));
	
	std::string path = "../graphics/Intro/Intro_000000";
	std::string extend = ".png";

	if (KeyboardEvents::isKeyPressed(27) || 
		MouseEventsHandler::isButtonPressedOnce( sf::Mouse::Button::Left) || KeyboardEvents::isKeyPressed(' '))
	{
		frame = 120;
	}

	if (frame > 119)
	{
		getGameMaster()->changeGameState(GameMaster::MainMenuState);
		return;
	}
	



	if (frame < 10)
	{
		path = "../graphics/Intro/Intro_00000";
	}
	else if (frame < 100)
	{
		path = "../graphics/Intro/Intro_0000";
		
	}
	else
	{
		path = "../graphics/Intro/Intro_000";
	}
	path += std::to_string(frame);
	path += extend;

	sf::Texture texture;
	texture.loadFromFile(path);

	sf::RectangleShape shape;
	shape.setTexture(&texture);
	shape.setSize(sf::Vector2f(SPLASH_SIZE_X, SPLASH_SIZE_Y));
	shape.setPosition((SCREEN_SIZE_X- SPLASH_SIZE_X)/2, 0);
	window.draw(shape);


}
