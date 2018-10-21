#ifndef TILEDMAP_HPP
#define TILEDMAP_HPP

#include <string>
#include "SFML/Graphics.hpp"
#include <vector>

#include "Logger.hpp"

class TiledMap : public sf::Drawable, public sf::Transformable {

	private:
		sf::VertexArray vertices;
		sf::Texture texture;

	public:
		TiledMap();
		~TiledMap();
		TiledMap(const TiledMap&) = delete;
		void Init(sf::Texture& texture, const std::vector<unsigned int>& level, const sf::Vector2u& tileSize);
		TiledMap& operator=(const TiledMap&) = delete;
		// void draw(RenderTarget& target, RenderStates states) const
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		/*friend void from_json(const json& j, TiledMap& tilemap);
		friend void to_json(json& j, const TiledMap& tilemap);*/
};

#endif // !TILEDMAP_HPP