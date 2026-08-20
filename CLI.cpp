#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include "Manager.hpp"

// ANSI-Colors
// \033[30m Black
// \033[31m Red
// \033[32m Green
// \033[33m Yellow
// \033[34m Blue
// \033[35m Magneta (Purple)
// \033[36m Cyan
// \033[37m White
// \033[0m Default

const std::vector<std::string> commands_list = {
	"   \033[1;97mhelp:\033[0m Shows commands list",
	"   \033[1;97mflags:\033[0m Shows available flags",
	"   \033[1;97mversion:\033[0m Shows current EpsilonMath version",
	"   \033[1;97msysinfo:\033[0m Shows info about your system overall",
	"   \033[1;97mclear:\033[0m Clears the screen",
	"   \033[1;97mexit:\033[0m Closes the program"

};

std::string lowercase(std::string text) {
	for (int i = 0; i < text.size(); i++) {
		text[i] = std::tolower(static_cast<unsigned char>(text[i]));
	}
	return text;
}

std::vector<std::string> parseWords(std::string text) {
	std::vector<std::string> words;
	std::stringstream ss(text);
	std::string buffer;

	while (ss >> buffer) {
		words.push_back(buffer);
	}

	return words;
}

void Manager::animateText(std::string text, animationType type) {
	if (Manager::isSilent()) { std::cout << text; }
	else {
		switch (type) {
		default:
			std::cout << text;
			break;
		case 0:
			for (int i = 0; i < text.size(); i++) {
				std::cout << text[i];
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
			break;
		case 1:
			std::vector<std::string> words = parseWords(text);

			for (int i = 0; i < words.size(); i++) {
				std::cout << words[i] << ' ';
				std::this_thread::sleep_for(std::chrono::milliseconds(25));
			}
			break;
		};
	}
}

void Manager::sendMessage(std::string text, msgType type, msgColor color, animationType animtype, bool end_line, bool silent) {
	switch (type) { // print message type
	case 0:
		if (silent) { std::cout << "\033[36m[Info] "; }
		else { std::cout << "\033[36m"; animateText("[Info] ", animtype); }
		break;
	case 1:
		if (silent) { std::cout << "\033[33m[Warning] "; }
		else { std::cout << "\033[33m"; animateText("[Warning] ", animtype); }
		break;
	case 2:
		if (silent) { std::cout << "\033[31m[Error] ";}
		else { std::cout << "\033[31m"; animateText("[Error] ", animtype); }
		break;
	default: // no type
		break;
	};

	std::cout << "\033[0m";

	switch (color) { // set init message color
	case 0:
		std::cout << "\033[30m";
		break;
	case 1:
		std::cout << "\033[31m";
		break;
	case 2:
		std::cout << "\033[32m";
		break;
	case 3:
		std::cout << "\033[33m";
		break;
	case 4:
		std::cout << "\033[34m";
		break;
	case 5:
		std::cout << "\033[35m";
		break;
	case 6:
		std::cout << "\033[36m";
		break;
	case 7:
		std::cout << "\033[37m";
		break;
	default: // no color
		break;
	}

	if (silent) { std::cout << text << "\033[0m"; }
	else { animateText(text, animtype); std::cout << "\033[0m"; }

	switch (end_line) {
	case 1:
		std::cout << std::endl;
		break;
	default:
		break;
	}
}

void Manager::CommandParser(std::string command, bool isSilent) {
	command = lowercase(command);
	std::vector<std::string> commands = parseWords(command);

	for (int i = 0; i < commands.size(); i++) {
		switch (commands.size()) {
		default: // complex commands [with flags]
			break;
		case 1: // simple commands [without flags]
			if (commands[i] == "help") 
			{ 
				sendMessage("Here is the list of available commands: ", Info, Default, Silent, true, isSilent);
				for (int i = 0; i < commands_list.size(); i++) {
					sendMessage(commands_list[i], Null, Default, Typing, true, isSilent);
				}
			}
			break;
		};
	}
}