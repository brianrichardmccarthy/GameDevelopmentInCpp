#include "AssetManager.hpp"
#include <stdexcept>

AssetManager::AssetManager() {}
AssetManager::~AssetManager() {}

sf::Texture& AssetManager::GetTexture(const std::string &name) {
	if (textures.find(name) == textures.end()) throw std::invalid_argument("The key " + name + " doesn't exist");
	return textures[name];
}

sf::Sprite& AssetManager::GetSprite(const std::string &name) {
	if (sprites.find(name) == sprites.end()) throw std::invalid_argument("The key " + name + " doesn't exist");
	return sprites[name];
}

sf::SoundBuffer& AssetManager::GetSoundBuffer(const std::string &name) {
	if (sounds.find(name) == sounds.end()) throw std::invalid_argument("The key " + name + " doesn't exist");
	return sounds[name];
}

sf::Font& AssetManager::GetFont(const std::string &name) {
	if (fonts.find(name) == fonts.end()) throw std::invalid_argument("The key " + name + " doesn't exist");
	return fonts[name];
}

bool AssetManager::LoadTexture(const std::string &path, const std::string &name) {
	return LoadResource(path, name, textures);
}

bool AssetManager::LoadSprite(const std::string &path, const std::string &name) {
	return LoadResource(path, name, sprites);
}

bool AssetManager::LoadSound(const std::string &path, const std::string &name) {
	return LoadResource(path, name, sounds);
}

bool AssetManager::LoadFont(const std::string &path, const std::string &name) {
	return LoadResource(path, name, fonts);
}

template<class T>
bool AssetManager::LoadResource(const std::string &path, const std::string &name, std::unordered_map<std::string, T>& map) {

	T res;
	if (!res.loadFromFile(path+name)) return false;

	map[name] = res;

	return true;
}