#include "GameGhost.hpp"


GameGhost::GameGhost(GameMaster * master, std::vector<char> charkey)
	:Game(master, charkey)
{

}

void GameGhost::upObstacle(sf::RenderWindow & window, double deltaTime)
{
	if (KeyboardEvents::isKeyPressed(' '))
	{
		failObstVal++;
		startVal = true;

		startMessageLabel.setTextString("");
	}
	if (KeyboardEvents::isKeyPressed(27))
	{
		stopSound();
		getGameMaster()->changeGameState(GameMaster::MainMenuState);
	}

	for (auto iter2 = obstaclesList.begin(); iter2 != obstaclesList.end(); iter2++)
	{
		(*iter2)->drawKeyVisualization(window);
	}


	auto iter = obstaclesList.begin();
	if (obstaclesList.size() != 0)
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


				delayKeyEntered.restart();
				return;

			}
			else if (KeyboardEvents::isEmpty() == false)
			{

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
			if (KeyboardEvents::isEmpty() == true && player->getPosition().x > (*iter)->getPosition().x+ (*iter)->getTriggerRange())
			{

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
