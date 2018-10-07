#ifndef GAME_HPP
#define GAME_HPP

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

class Game {
	private:
		sf::RenderWindow window;

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