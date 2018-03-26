#include "GUI.hpp"

void GUI::add(Widget& widget)
{
	widgets.push_back(&widget);
}

void GUI::update()
{
	for (auto widget : widgets)
		widget->update();
}

void GUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto widget : widgets)
		target.draw(*widget);
}
