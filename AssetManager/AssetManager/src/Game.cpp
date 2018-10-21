#include "Game.hpp"

#include <SFML/OpenGL.hpp>
#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"
//#include "SFML/Graphics/Rect.hpp"

Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asset Manager") {
	window.setFramerateLimit(60);
	ImGui::SFML::Init(window);
	//sf::IntRect s1;
	//list1.emplace_back(s1);
	//assetManager.LoadTileMap("D:\Projects\College\Semester7\GameDevelopmentInCpp\AssetManager\AssetManager\media\images", "tileset.png", list1);
	//bool r = assetManager.LoadTexture("./media/images/", "cute_image.jpg");
	//std::cout << r << std::endl;
	//system("pause");
	std::vector<sf::Vertex> s;
	assetManager.LoadTileMap("./media/images/", "tileset.png", s);
}

void Game::Init() {
}

Game::~Game() {
	ImGui::SFML::Shutdown();
}

void Game::Run() {
	sf::Clock clock;
	window.resetGLStates();
	while (window.isOpen()) {
		if (!ProcessEvents()) break;
		Update(clock.restart());
		Render();
	}
}

bool Game::ProcessEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		ImGui::SFML::ProcessEvent(event);
		if (event.type == sf::Event::Closed) {
			window.close();
			break;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) return false;
	}
	return true;
}

void Game::Update(const sf::Time& deltaTime) {
	ImGui::SFML::Update(window, deltaTime);
}

void Game::Render() {
	sf::Sprite s{*assetManager.GetTexture("cute_image.jpg")};
	s.setPosition(sf::Vector2f(100, 100));
	s.setScale(sf::Vector2f(0.1f, 0.1f));
	ImGui::Begin("Sample window");

	if (ImGui::ColorEdit3("Background color", color)) {
		bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
		bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
		bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
	}

	ImGui::InputText("Window title", windowTitle, 255);

	if (ImGui::Button("Update window title")) {
		window.setTitle(windowTitle);
	}

	if (ImGui::ImageButton(s)) {
		std::cout << "Image Clicked" << std::endl;
		draw = &s;
	}

	ImGui::End();

	window.clear(bgColor);
	window.draw(s);
	window.draw(assetManager.GetTiledMap());
	ImGui::SFML::Render(window);
	window.display();
}