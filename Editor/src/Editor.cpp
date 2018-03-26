#include <Editor.hpp>

#include <MouseEventsHandler.hpp>

//TODO: testowo
#include <iostream>

Editor::Editor()
{
	platformTexture.loadFromFile("../../../../HACKATHON/Game/bin/graphics/platform200x40x1.png");
	slideTexture.loadFromFile("../../../../HACKATHON/Game/bin/graphics/wirujaceOstrzeZnikad.png");
	emptyTexture.loadFromFile("../graphics/note.png");

	platformSprite.setTexture(platformTexture);
	platformSprite.setOrigin(sf::Vector2f(
		platformSprite.getGlobalBounds().width / 2,
		platformSprite.getGlobalBounds().height / 2));
	slideSprite.setTexture(slideTexture);
	slideSprite.setOrigin(sf::Vector2f(
		slideSprite.getGlobalBounds().width / 2,
		slideSprite.getGlobalBounds().height / 2));
	emptySprite.setTexture(emptyTexture);
	emptySprite.setOrigin(sf::Vector2f(
		emptySprite.getGlobalBounds().width / 2,
		emptySprite.getGlobalBounds().height / 2));

	mode = ObstacleType::None;
}

void Editor::start()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_SIZE_X, SCREEN_SIZE_Y), "KEYSTROKER Editor");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			MouseEventsHandler::update(event);
		}

		update();

		window.clear(sf::Color(66, 134, 244));
		draw(window);
		window.display();

		MouseEventsHandler::reset();
	}
}

void Editor::update()
{
	blueprint.update();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
	{
		mode = ObstacleType::Platform;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
	{ 
		mode = ObstacleType::Slide;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3))
	{ 
		mode = ObstacleType::Empty;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4))
	{
		mode = ObstacleType::None;
	}

	platformSprite.setPosition(
		MouseEventsHandler::getMousePosition().x,
		MouseEventsHandler::getMousePosition().y);
	platformSprite.setScale(blueprint.getScale(), blueprint.getScale());
	slideSprite.setPosition(
		MouseEventsHandler::getMousePosition().x,
		MouseEventsHandler::getMousePosition().y);
	platformSprite.setScale(blueprint.getScale(), blueprint.getScale());
	emptySprite.setPosition(
		MouseEventsHandler::getMousePosition().x,
		MouseEventsHandler::getMousePosition().y);
	platformSprite.setScale(blueprint.getScale(), blueprint.getScale());

	if (MouseEventsHandler::isButtonPressedOnce(sf::Mouse::Button::Left) &&
		mode != ObstacleType::None)
	{
		GameObject object;
		object.obstacle = mode;
		object.position = blueprint.getPosition();
		switch (mode)
		{
		case ObstacleType::Platform:
			object.sprite.setTexture(platformTexture);
			break;
		case ObstacleType::Slide:
			object.sprite.setTexture(slideTexture);
			break;
		case ObstacleType::Empty:
			object.sprite.setTexture(emptyTexture);
			break;
		}
		object.sprite.setOrigin(sf::Vector2f(
			object.sprite.getGlobalBounds().width / 2,
			object.sprite.getGlobalBounds().height / 2));
		object.sprite.setPosition(
			MouseEventsHandler::getMousePosition().x, 
			MouseEventsHandler::getMousePosition().y);
		object.sprite.setScale(blueprint.getScale(), blueprint.getScale());

		gameObjects.push_back(object);
	}
}

void Editor::draw(sf::RenderWindow& window)
{
	window.draw(blueprint);

	switch (mode)
	{
	case ObstacleType::Platform:
		window.draw(platformSprite);
		break;
	case ObstacleType::Slide:
		window.draw(slideSprite);
		break;
	case ObstacleType::Empty:
		window.draw(emptySprite);
		break;
	}

	for (size_t i = 0; i < gameObjects.size(); i++)
		window.draw(gameObjects[i].sprite);
}
