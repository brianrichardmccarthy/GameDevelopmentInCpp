//#include "TiledMap.hpp"
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