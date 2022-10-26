#include "FileLog.h"

FileLog::FileLog() {
	set_file_output();
}

FileLog::FileLog(const char* file_path) {
	set_file_output(file_path);
}

void FileLog::free_file() {
	fclose(file);
	file = 0;
}

void FileLog::print(const char* message) {
	if (file) {
		fprintf(file, message);
		fprintf(file, "\n");
	}
	
}

FileLog::~FileLog() {
	free_file();
}

void FileLog::enable_file_output() {
	if (file != 0) {
		fclose(file);
	}
	
	file = fopen(file_path, "a");
	if (file == 0) {
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