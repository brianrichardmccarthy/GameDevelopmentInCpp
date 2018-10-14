//#ifndef TILEDMAP_HPP
//#define TILEDMAP_HPP
//
//#include <string>
//#include <SFML/Graphics.hpp>
//#include <vector>
//
//#include "Logger.hpp"
//
//class TiledMap {
//
//	private:
//		std::vector<sf::Vertex> mapSizes;
//		std::string name;
//
//	public:
//		TiledMap(const std::string &name, std::vector<sf::Vertex>& mapSizes);
//		~TiledMap();
//		TiledMap(const TiledMap&);
//		TiledMap& operator=(const TiledMap&);
//		const std::string& GetName() noexcept;
//		const unsigned int& GetTileCount() noexcept;
//		const sf::Vertex& GetSubRegion(const int& index) noexcept;
//		friend void from_json(const json& j, TiledMap& tilemap);
//		friend void to_json(json& j, const TiledMap& tilemap);
//};
//
//#endif // !TILEDMAP_HPP