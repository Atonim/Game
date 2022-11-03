#include "FileLog.h"



FileLog::FileLog() {
	set_file_output();
}

FileLog::FileLog(const char* file_path) {
	set_file_output(file_path);
}

void FileLog::free_file() {
	file.close();
}

void FileLog::print(const char* message) {
	if (file.is_open()) {
		file << message << std::endl;
	}
}
std::ostream& operator<<(std::fstream& stream, const char* str) {

	stream << std::string(str) << std::endl;
	return stream;
}

FileLog::~FileLog() {
	free_file();
}

void FileLog::enable_file_output() {
	if (file.is_open()) {
		file.close();
	}
	
	file.open(file_path, std::ios_base::out);
	if (file.fail()) {
		printf("[LOGGER] Failed to open file at %s", file_path);
	}
}

void FileLog::set_file_output() {
	file_path = "logs/log.txt";
	enable_file_output();
}

void FileLog::set_file_output(const char* file_path) {
	this->file_path = file_path;
	enable_file_output();
}