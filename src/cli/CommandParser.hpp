#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>` 
#include "Terminal.hpp"

class Terminal;

class CommandParser {
private:
	
	Terminal* terminal;

	inline const static std::vector<std::string> commands_list = {
		"\n\033[1;94m+\033[0;97m ─────────────────────────────────────────────── \033[1;94m+\033+\n"
		"\033[1;97m│ \033[1;94mhelp\033[1;97m: Shows commands list                       │\n",
		"\033[1;97m│ \033[1;94msysinfo\033[1;97m: Shows info about your system overall   │\n",
		"\033[1;97m│ \033[1;94mclear\033[1;97m: Clears the screen                        │\n",
		"\033[1;97m│ \033[1;94mexit\033[1;97m: Closes the program                        │\n"
		"\033[1;94m+\033[0;97m ─────────────────────────────────────────────── \033[1;94m+\033+\n"
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