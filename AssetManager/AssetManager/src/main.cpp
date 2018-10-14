#include "Game.hpp"
#include "Logger.hpp"

int main(int argc, const char** argv) {
	
	Logger::Init("./output.txt");
	Game game;
	game.Run();
	return EXIT_SUCCESS;
}