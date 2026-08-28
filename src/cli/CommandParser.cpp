#pragma once
#include "CommandParser.hpp"
#include "Terminal.hpp"

std::vector<std::string> CommandParser::parseWords(const std::string& text) {
	std::vector<std::string> words;
	std::istringstream stream(text);
	std::string wordBuffer;
	while (stream >> wordBuffer) {
		words.push_back(wordBuffer);
	}
	return words;
}

void CommandParser::lowercase(std::string& text) {
	for (auto& x : text) {
		x = std::tolower(x);
	}
}

void CommandParser::processCommand(std::string& command) {
	lowercase(command);
	std::vector<std::string> words = parseWords(command);

	switch (words.size()) {
	case 0: // empty command
		terminal->printText("No command entered. Type 'help' to see available commands.\n", terminal->Warning);
		break;
	case 1: // non-complex commands
		break;
	default: // complex commands
		break;
	}

}