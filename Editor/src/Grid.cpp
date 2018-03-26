#include <Grid.hpp>

#include <Globals.hpp>

Grid::Grid()
{
	setThickLinesSpacer(50);
	setThickLinesDividers(4);
	setPosition(sf::Vector2f(0, 0));
	setScale(1.f);
}

Grid::~Grid()
{
	for (size_t y = 0; y < horizontalThickLines.size(); y++)
	{
		delete horizontalThickLines[y];
	}

	for (size_t y = 0; y < horizontalThinLines.size(); y++)
	{
		delete horizontalThinLines[y];
	}

	for (size_t x = 0; x < verticalThickLines.size(); x++)
	{
		delete verticalThickLines[x];
	}

	for (size_t x = 0; x < verticalThinLines.size(); x++)
	{
		delete verticalThinLines[x];
	}
}

void Grid::setPosition(const sf::Vector2f& position)
{
	this->position = position;
	update();
}

void Grid::setScale(float scale)
{
	this->scale = scale;
	update();
}

void Grid::setScreenSize(const sf::Vector2u& size)
{
	screenSize = size;
	update();
}

void Grid::setThickLinesSpacer(size_t spacer)
{
	thickLinesSpacer = spacer;
	update();
}

void Grid::setThickLinesDividers(size_t numberOfDividers)
{
	thickLinesDividers = numberOfDividers;
	update();
}

void Grid::update()
{
	numberOfHorizontalThickLines = (size_t)ceil(screenSize.y / thickLinesSpacer / scale) + 1;
	numberOfHorizontalThinLines = (size_t)ceil(numberOfHorizontalThickLines * thickLinesDividers / scale) + 1;
	numberOfVerticalThickLines = (size_t)ceil(screenSize.x / thickLinesSpacer / scale) + 1;
	numberOfVerticalThinLines = (size_t)ceil(numberOfVerticalThickLines * thickLinesDividers / scale) + 1;

	allocateNewLines(
		numberOfHorizontalThickLines,
		numberOfHorizontalThinLines,
		numberOfVerticalThickLines,
		numberOfVerticalThinLines);

	sf::Color linesColor = sf::Color(100,100,100);

	for (size_t y = 0; y < numberOfHorizontalThickLines; y++)
	{
		horizontalThickLines[y]->setPosition(sf::Vector2f(position.x, y*thickLinesSpacer*scale + position.y));
		horizontalThickLines[y]->setSize(sf::Vector2f(screenSize.x + thickLinesSpacer, 2 * scale));
		horizontalThickLines[y]->setFillColor(linesColor);
		horizontalThickLines[y]->setOrigin(sf::Vector2f(1, 1));
	}

	for (size_t y = 0; y < numberOfHorizontalThinLines; y++)
	{
		horizontalThinLines[y]->setPosition(sf::Vector2f(position.x, y*thickLinesSpacer*scale + position.y));
		horizontalThinLines[y]->setSize(sf::Vector2f(screenSize.x + thickLinesSpacer, 2 * scale));
		horizontalThinLines[y]->setFillColor(linesColor);
		horizontalThinLines[y]->setOrigin(sf::Vector2f(1, 1));
	}

	for (size_t x = 0; x < numberOfVerticalThickLines; x++)
	{
		///verticalThickLines[x]->setPosition(sf::Vector2f((int)abs((x*thickLinesSpacer*scale+ position.x))%SCREEN_SIZE_X, position.y));
		verticalThickLines[x]->setPosition(sf::Vector2f(x*thickLinesSpacer*scale + position.x, position.y));
		verticalThickLines[x]->setSize(sf::Vector2f(2 * scale, screenSize.y + thickLinesSpacer));
		verticalThickLines[x]->setFillColor(linesColor);
		verticalThickLines[x]->setOrigin(sf::Vector2f(1, 1));
	}

	for (size_t x = 0; x < numberOfVerticalThinLines; x++)
	{
		verticalThinLines[x]->setPosition(sf::Vector2f(x*thickLinesSpacer*scale+ position.x, position.y));
		verticalThinLines[x]->setSize(sf::Vector2f(2 * scale,screenSize.y + thickLinesSpacer));
		verticalThinLines[x]->setFillColor(linesColor);
		verticalThinLines[x]->setOrigin(sf::Vector2f(1, 1));
	}
}

void Grid::allocateNewLines(size_t hThick, size_t hThin, size_t vThick, size_t vThin)
{
	for (size_t y = horizontalThickLines.size(); y < hThick; y++)
	{
		sf::RectangleShape* line = new sf::RectangleShape;
		horizontalThickLines.push_back(line);
	}

	for (size_t y = horizontalThinLines.size(); y < hThin; y++)
	{
		sf::RectangleShape* line = new sf::RectangleShape;
		horizontalThinLines.push_back(line);
	}

	for (size_t x = verticalThickLines.size(); x < vThick; x++)
	{
		sf::RectangleShape* line = new sf::RectangleShape;
		verticalThickLines.push_back(line);
	}

	for (size_t x = verticalThinLines.size(); x < vThin; x++)
	{
		sf::RectangleShape* line = new sf::RectangleShape;
		verticalThinLines.push_back(line);
	}
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (size_t y = 0; y < numberOfHorizontalThickLines; y++)
	{
		target.draw(*horizontalThickLines[y]);
	}

	for (size_t y = 0; y < numberOfHorizontalThinLines; y++)
	{
		//target.draw(*horizontalThinLines[y]);
	}

	for (size_t x = 0; x < numberOfVerticalThickLines; x++)
	{
		target.draw(*verticalThickLines[x]);
	}

	for (size_t x = 0; x < numberOfVerticalThinLines; x++)
	{
		//target.draw(*verticalThinLines[x]);
	}
}
