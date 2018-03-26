#pragma once

#include <SFML/Graphics.hpp>

#include "GUI/Widgets.hpp"

class GUI : public sf::Drawable
{
public:

	void add(Widget& widget);

	void update();

private:

	std::vector< Widget* > widgets;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


};