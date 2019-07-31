//
//  TileMap.hpp
//  AssetManagerv1
//
//  Created by Denis Flynn on 19/09/2018.
//  Copyright © 2018 Denis Flynn. All rights reserved.
//

#ifndef TileMap_hpp
#define TileMap_hpp
#include <string>
#include "Window.h"
#include "enums.h"
#include <iostream>

// The level tile type.
struct Tile {
	TILE type;                            // The type of tile this is.
	int columnIndex;                    // The column index of the tile.
	int rowIndex;                        // The row index of the tile.
	sf::Sprite sprite;                    // The tile sprite.
	int H;                                // Heuristic / movement cost to goal.
	int G;                                // Movement cost. (Total of entire path)
	int F;                                // Estimated cost for full path. (G + H)
	Tile* parentNode;                    // Node to reach this node.
};

class TileMap : public sf::Drawable, public sf::Transformable {
public:
	sf::Vector2f GetActualTileLocation(int columnIndex, int rowIndex);
	sf::Vector2i GetActualTileLocation(float x, float y);
	sf::Vector2i GetActualTileLocation(sf::Vector2f location);
	void printOnTile(std::string text, int row, int col);
	void rectangeOnTile(sf::Vector2i pos, sf::Color colour);
	void printOnTile(std::string text, sf::Vector2i pos);
	void printOnTileArr(std::vector<sf::Text> textArr);
	bool load(const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	sf::Vector2u m_tileSize;
	sf::Vector2u m_tileArrSize;
	sf::RectangleShape m_rectangle;
	std::vector<sf::RectangleShape> m_rectangleArr;
	sf::Vector2i m_origin;
	std::vector<int> m_grid;
	sf::Font m_font;
	sf::Text m_text;
	std::vector<sf::Text> m_GridText;
};
#endif /* TileMap_hpp */
