#ifndef ASSETMANAGER_HPP
#define ASSETMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <string>
#include <unordered_map>

class AssetManager {
	public:
		AssetManager();
		~AssetManager();
		AssetManager(const AssetManager&) = delete;
		AssetManager& operator=(const AssetManager&) = delete;
		bool LoadTexture(const std::string &path, const std::string &name);
		bool LoadSound(const std::string &path, const std::string &name);
		bool LoadFont(const std::string &path, const std::string &name);
		bool LoadTexture(const std::string &path, const std::string &name);
		bool LoadSprite(const std::string &path, const std::string &name);
		bool LoadTileMap(const std::string &path, const std::string &name, const sf::Vector2u &size);

		sf::Texture& GetTexture(const std::string &name);
		sf::Sprite& GetSprite(const std::string &name);
		sf::SoundBuffer& GetSoundBuffer(const std::string &name);
		sf::Font& GetFont(const std::string &name);

	private:
		std::unordered_map<std::string, sf::Texture> textures;
		std::unordered_map<std::string, sf::Sprite> sprites;
		std::unordered_map<std::string, sf::SoundBuffer> sounds;
		std::unordered_map<std::string, sf::Font> fonts;
		template<class T>
		bool LoadResource(const std::string &path, const std::string &name, std::unordered_map<std::string, T> &map);
};

#endif // !ASSETMANAGER_HPP
