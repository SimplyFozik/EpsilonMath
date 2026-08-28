#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Terminal.hpp"

class Terminal;

class CommandParser {
private:
	
	Terminal* terminal;

	inline const static std::vector<std::string> commands_list = {
		"\033[1;97mhelp:\033[0m Shows commands list",
		"\033[1;97mflags:\033[0m Shows available flags",
		"\033[1;97mversion:\033[0m Shows current EpsilonMath version",
		"\033[1;97msysinfo:\033[0m Shows info about your system overall",
		"\033[1;97mclear:\033[0m Clears the screen",
		"\033[1;97mexit:\033[0m Closes the program"
	};

public:

	std::vector<std::string> parseWords(const std::string& text);
	void lowercase(std::string& text);
	void processCommand(std::string& command);

	static std::vector<std::string> getCommandsList() {
		return commands_list;
	}

	explicit CommandParser(Terminal* terminal) : terminal(terminal) {
		terminal->printText("CommandParser service initialized successfuly\n", terminal->Debug);
	}

};