#pragma once
#include <vector>

class KeyboardEvents {

	static std::vector<char> pressedKeys;

public:

	static bool isKeyPressed(const char& key);

	static void AddKey(const char& key);

	static void Clear();

	static bool isEmpty();
};