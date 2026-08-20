#include <iostream>
#include <string>
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

std::string lowercase(std::string text) {
	for (int i = 0; i < text.size(); i++) {
		text[i] = std::tolower(static_cast<unsigned char>(text[i]));
	}
	return text;
}

void Manager::animateText(std::string text) {
	for (int i = 0; i < text.size(); i++) {
		std::cout << text[i];
		std::this_thread::sleep_for(std::chrono::milliseconds(3));
	}
}

void Manager::sendMessage(std::string text, msgType type, msgColor color ,bool end_line, bool silent) {
	switch (type) { // print message type
	case 0:
		if (silent) { std::cout << "\033[36m[Info] "; }
		else { std::cout << "\033[36m"; animateText("[Info] "); }
		break;
	case 1:
		if (silent) { std::cout << "\033[33m[Warning] "; }
		else { std::cout << "\033[33m"; animateText("[Warning] "); }
		break;
	case 2:
		if (silent) { std::cout << "\033[31m[Error] ";}
		else { std::cout << "\033[31m"; animateText("[Error] "); }
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
	else { animateText(text); std::cout << "\033[0m"; }

	switch (end_line) {
	case 1:
		std::cout << std::endl;
		break;
	default:
		break;
	}
}

void Manager::CommandParser(std::string command) {
	command = lowercase(command);

	if (command == "help") {
		std::cout << std::endl;
		sendMessage("Here is the list of commands: ", Info, Default, true, false);
		sendMessage(" | help - Shows list of commands.", Null, Default, true, false);
		sendMessage(" | flags - Shows list of flags.", Null, Default, true, false);
		sendMessage(" | test - Runs benchmark depending on your flags.", Null, Default, true, false);
		sendMessage(" . version - Shows version of EpsilonMath.", Null, Default, true, false);
		std::cout << std::endl;
	}
}