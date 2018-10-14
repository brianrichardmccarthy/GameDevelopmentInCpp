#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

#include "nlohmann/json.hpp"

using json = nlohmann::json;
constexpr char JSON_FILE_PATH[] = "/media/data/";
constexpr char LOGGER_PATH[] = "/media/logger/";
constexpr char JSON_EXTENSION[] = ".json";
constexpr char LOGGER_EXTENSION[] = ".txt";

class AssetManager;
class TiledMap;

class Logger {
	public:
		static void Write(const std::string& line);
		static void Init(const std::string& name);
		static void Close();

	private:
		~Logger();
		Logger() {};
		static Logger logger;
		std::ofstream write;
		std::string name;

		Logger(const Logger&) = delete;
		Logger& operator=(const Logger&) = delete;

};

class Json {
	public:
		void Write(const std::unordered_map<std::string, std::string> &object, const std::string &name);
		template <class T>
		void Read(T &object, const std::string &name);
};

void to_json(json& j, const AssetManager& manager);
void to_json(json& j, const TiledMap& tilemap);
void from_json(const json& j, AssetManager& manager);
void from_json(const json& j, TiledMap& tilemap);

#endif // !LOGGER_HPP