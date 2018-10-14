#ifndef ASSETMANAGER_HPP
#define ASSETMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <string>
#include <unordered_map>
#include <vector>

#include "Logger.hpp"
#include "TiledMap.hpp"

constexpr char FILES_PATH[] = "";


class AssetManager {
	public:
		AssetManager();
		~AssetManager();
		AssetManager(const AssetManager&) = delete;
		AssetManager& operator=(const AssetManager&) = delete;
		bool LoadTexture(const std::string &path, const std::string &name);
		bool LoadSound(const std::string &path, const std::string &name);
		bool LoadFont(const std::string &path, const std::string &name);
		bool LoadSprite(const std::string &path, const std::string &name);
		//bool LoadTileMap(const std::string &path, const std::string &name, std::vector<sf::Vertex>& mapSizes);

		sf::Texture* GetTexture(const std::string &name) noexcept;
		std::unique_ptr<sf::Sprite> GetSprite(const std::string &name) noexcept;
		//std::unique_ptr<sf::Sprite> GetTiledMapRegion(const std::string &name, const unsigned int &number) noexcept;
		sf::SoundBuffer* GetSoundBuffer(const std::string &name) noexcept;
		sf::Font* GetFont(const std::string &name) noexcept;

		friend void from_json(const json& j, AssetManager& manager);
		friend void to_json(json& j, const AssetManager& manager);


	private:
		std::unordered_map<std::string, sf::Texture> textures;
		std::set<std::string> sprites;
		std::unordered_map<std::string, sf::SoundBuffer> sounds;
		std::unordered_map<std::string, sf::Font> fonts;
		//std::vector<TiledMap> tiledMaps;
		
		template<class T>
		bool LoadResource(const std::string &path, const std::string &name, std::unordered_map<std::string, T> &map);
};

#endif // !ASSETMANAGER_HPP
