#include "KeyboardEvents.hpp"

std::vector<char> KeyboardEvents::pressedKeys;

bool KeyboardEvents::isKeyPressed(const char & key)
{
	for (auto iter = pressedKeys.begin(); iter != pressedKeys.end(); iter++)
	{
		if (key == *iter)
			return true;
	}
	return false;
}

void KeyboardEvents::AddKey(const char & key)
{
	pressedKeys.push_back(key);
}

void KeyboardEvents::Clear()
{
	pressedKeys.clear();
}

bool KeyboardEvents::isEmpty()
{
	return (pressedKeys.empty());
}
