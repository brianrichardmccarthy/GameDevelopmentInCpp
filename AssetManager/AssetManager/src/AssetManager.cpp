#include <stdexcept>
#include "AssetManager.hpp"

AssetManager::AssetManager() {
	level = {
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0, 0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 10, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,2, 0, 1, 10, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0, 0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 10, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,2, 0, 1, 10, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1
	};
}

AssetManager::~AssetManager() {}

sf::Texture* AssetManager::GetTexture(const std::string &name) noexcept {
	if (textures.find(name) == textures.end()) {
		Logger::Write("No Texture named \"" + name + "\" exist");
		return nullptr;
	}
	return &textures[name];
}


std::unique_ptr<sf::Sprite> AssetManager::GetSprite(const std::string &name) noexcept {
	if (sprites.find(name) == sprites.end()) {
		Logger::Write("No Texture named \"" + name + "\" exist");
		return nullptr;
	}
	std::unique_ptr<sf::Sprite> sprite;
	sprite->setTexture(textures[name]);
	return sprite;
}

//std::unique_ptr<sf::Sprite> AssetManager::GetTiledMapRegion(const std::string &name, const unsigned int &number) noexcept {
//	
//	std::unique_ptr<sf::Sprite> sprite = GetSprite(name);
//	
//	if (sprite == nullptr) return sprite;
//	
//	for (auto& iter: tiledMaps)
//		if (iter.GetName() == name) {
//			// sprite->setTextureRect(sf::Vertex(iter.GetSubRegion(number)));
//			
//			return sprite;
//		}
//	
//	return nullptr;
//}

sf::SoundBuffer* AssetManager::GetSoundBuffer(const std::string &name) noexcept {
	if (sounds.find(name) == sounds.end()) { 
		Logger::Write("No Sound named \"" + name + "\" exist"); 
		return nullptr;
	}
	return &sounds[name];
}

sf::Font* AssetManager::GetFont(const std::string &name) noexcept {
	if (fonts.find(name) == fonts.end()) {
		Logger::Write("No Font named \"" + name + "\" exist");
		return nullptr;
	}
	return &fonts[name];
}

bool AssetManager::LoadTexture(const std::string &path, const std::string &name) {

	return LoadResource(path, name, textures);
}

bool AssetManager::LoadSprite(const std::string &path, const std::string &name) {
	if (sprites.find(name) != sprites.end()) {
		Logger::Write("The texture \"" + name + "\" already is loaded");
		return false;
	}
	bool result = LoadResource(path, name, textures);

	if (result) {
		sprites.emplace(name);
	} else {
		Logger::Write("Failed to load asset at path \"" + path + "\" name \"" + name + "\"");
	}

	return result;
}

bool AssetManager::LoadTileMap(const std::string &path, const std::string &name, std::vector<sf::Vertex>& mapSizes) {

	bool result = LoadResource(path, name, textures);
	if (result) {
		tiledMap.Init(*GetTexture(name), level, sf::Vector2u(32, 32));
	} else {
		Logger::Write("Failed to load asset at path \"" + path + "\" name \"" + name + "\"");
	}

	return result;
}

bool AssetManager::LoadSound(const std::string &path, const std::string &name) {
	return LoadResource(path, name, sounds);
}

bool AssetManager::LoadFont(const std::string &path, const std::string &name) {
	return LoadResource(path, name, fonts);
}

TiledMap& AssetManager::GetTiledMap() {
	return tiledMap;
}

template<class T>
bool AssetManager::LoadResource(const std::string &path, const std::string &name, std::unordered_map<std::string, T> &map) {

	if (map.find(name) != map.end()) {
		Logger::Write("The resource of type=\"\" name=\"" + name + "\" already is loaded");
		return false;
	}

	T res;
	if (!res.loadFromFile(path+name)) {
		Logger::Write("Failed to load asset at path \"" + path + "\" name \"" + name + "\"");
		return false;
	}

	map[name] = res;

	return true;
}