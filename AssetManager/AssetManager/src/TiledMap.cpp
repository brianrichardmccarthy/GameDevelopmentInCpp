#include "TiledMap.hpp"
//
//TiledMap::TiledMap(const std::string &name, std::vector<sf::Vertex> &mapSizes) : name(name), mapSizes(mapSizes) {}
//
//TiledMap::~TiledMap() {}
//
////TiledMap::TiledMap(const TiledMap &other) {
////	operator=(other);
////}
////
////TiledMap& TiledMap::operator=(const TiledMap &other) {
////	TiledMap tm(other.name, other.mapSizes);
////	return *this;
////}
//
//const std::string& TiledMap::GetName() noexcept {
//	return name;
//}
//
//const unsigned int& TiledMap::GetTileCount() noexcept {
//	return mapSizes.size();
//}
//
//const sf::Vertex& TiledMap::GetSubRegion(const int& index) noexcept {
//	return mapSizes[index];
//}

TiledMap::TiledMap() {
}

TiledMap::~TiledMap() {
}

//TiledMap::TiledMap(const TiledMap&) {}

void TiledMap::Init(sf::Texture &texture, const std::vector<unsigned int> &level, const sf::Vector2u &tileSize) {
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(texture.getSize().x * texture.getSize().y * 4);

	for (unsigned int i = 0; i < texture.getSize().x; i++) {
		for (unsigned int j = 0; j < texture.getSize().y; j++) {
			int titleNumber = level[(i + j)*texture.getSize().x];
			int tu = titleNumber % (texture.getSize().x / tileSize.x);
			int tv = titleNumber / (texture.getSize().x / tileSize.x);

			sf::Vertex* quad = &vertices[((i + j) * texture.getSize().x) * 4];

			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}
	}
}

void TiledMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	states.texture = &texture;
	target.draw(vertices, states);
}

//void from_json(const json& j, TiledMap& tilemap) {
//}
//
//void to_json(json& j, const TiledMap& tilemap) {
//}