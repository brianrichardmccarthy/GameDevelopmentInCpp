#include "Logger.hpp"
#include "AssetManager.hpp"
#include "TiledMap.hpp"

Logger Logger::logger;

void Logger::Close() {
}

void Logger::Write(const std::string& line) {
	logger.write.open(LOGGER_PATH + logger.name + LOGGER_EXTENSION);

	if (logger.write.is_open()) {
		logger.write << line << std::endl;
		logger.write.close();
	}

}

void Logger::Init(const std::string& name) {
	logger.name = name;
}

Logger::~Logger() {
	if (logger.write.is_open()) logger.write.close();
}

void Json::Write(const std::unordered_map<std::string, std::string> &object, const std::string &name) {
	json j(object);
	std::filebuf filebuf;
	filebuf.open(JSON_FILE_PATH + name + JSON_EXTENSION, std::ios::out);
	std::ostream os(&filebuf);
	os << j << std::endl;
	filebuf.close();
}

template<class T>
void Json::Read(T &object, const std::string &name) {
	json j;
	std::filebuf fb;
	fb.open(JSON_FILE_PATH + name + JSON_EXTENSION, std::ios::in);
	std::istream is(&fb);
	is >> j;
	fb.close();
	object = j;
}

void to_json(json& j, const AssetManager& manager) {}

void to_json(json& j, const TiledMap& tilemap) {}
void from_json(const json& j, AssetManager& manager) {}
void from_json(const json& j, TiledMap& tilemap) {}

/*
void to_json(json& j, const person& p) {
	j = json{{"name", p.name}, {"address", p.address}, {"age", p.age}};
}

void from_json(const json& j, person& p) {
	j.at("name").get_to(p.name);
	j.at("address").get_to(p.address);
	j.at("age").get_to(p.age);
}
*/