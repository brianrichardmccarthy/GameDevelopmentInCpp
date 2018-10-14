#ifndef GAME_HPP
#define GAME_HPP

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "AssetManager.hpp"
#include <vector>

constexpr int WINDOW_WIDTH{ 800 }, WINDOW_HEIGHT{ 600 };

class Game {
	private:
		struct Map {
			const std::string name;
			sf::Vector2i pos;

			Map(std::string& name, sf::Vector2i& pos) : name(name), pos(pos) {};
		};
		sf::RenderWindow window;
		sf::Color bgColor;
		char windowTitle[255] = "ImGui + SFML = <3";
		float color[3] = { 0.f, 0.f, 0.f };
		AssetManager assetManager;
		//std::vector<sf::IntRect> list1;
		sf::Sprite* draw;
		std::vector<Map> maps;
		
	public:
		Game();
		~Game();
		Game(const Game&) = delete;
		Game& operator=(const Game&) = delete;
		void Run();

	private:
		void Init();
		bool ProcessEvents();
		void Update(const sf::Time& deltaTime);
		void Render();
};

#endif // !GAME_HPP