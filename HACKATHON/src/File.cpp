#include "File.hpp"

#include <filesystem>

#include "pugixml/pugixml.hpp"

namespace fs = std::experimental::filesystem;

void File::save(const GameObjects& gameObjects, const char* path)
{
	pugi::xml_document file;

	pugi::xml_node title = file.append_child("KeystrokerLevelFile");

	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		pugi::xml_node object = title.append_child("GameObject");

		pugi::xml_node position = object.append_child("position");
		pugi::xml_attribute positionX = position.append_attribute("x");
		pugi::xml_attribute positionY = position.append_attribute("y");
		positionX.set_value(gameObjects[i].position.x);
		positionY.set_value(gameObjects[i].position.y);

		pugi::xml_node origin = object.append_child("origin");
		pugi::xml_attribute originX = origin.append_attribute("x");
		pugi::xml_attribute originY = origin.append_attribute("y");
		originX.set_value(gameObjects[i].origin.x);
		originY.set_value(gameObjects[i].origin.y);

		pugi::xml_node obstacle = object.append_child("obstacle");
		pugi::xml_attribute type = obstacle.append_attribute("type");
		type.set_value((int)gameObjects[i].type);
	}

	//TODO: obs³u¿yæ b³êdy zapisu
	file.save_file(path);
}

GameObjects File::load(const char* path)
{
	GameObjects gameObjects;

	//TODO: obs³u¿yæ b³êdy ³adowania
	pugi::xml_document file;
	file.load_file(path);

	pugi::xml_node title = file.child("KeystrokerLevelFile");

	for (pugi::xml_node object = title.child("GameObject"); object; object = object.next_sibling("GameObject"))
	{
		GameObject gameObject;
		gameObject.position.x = object.child("position").attribute("x").as_float();
		gameObject.position.y = object.child("position").attribute("y").as_float();
		gameObject.origin.x = object.child("origin").attribute("x").as_float();
		gameObject.origin.y = object.child("origin").attribute("y").as_float();
		gameObject.type = (GameObject::Type)object.child("obstacle").attribute("type").as_int();

		gameObjects.push_back(gameObject);
	}

	return gameObjects;
}