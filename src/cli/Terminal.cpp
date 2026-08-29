#include "Terminal.hpp"

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

void Terminal::clearScreen() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void Terminal::printPrefix(messageStyle style) {
	switch (style.Type) {
	case Terminal::messageType::DebugPrefix:
		std::cout << "\n\033[1;97m# \033[0;107m\033[107;30m [Debug] \033[0m\033[1;97m ";
		break;
	case Terminal::messageType::InfoPrefix:
		std::cout << "\n\033[1;94mi \033[0;104m\033[104;30m [Info] \033[0m\033[1;97m ";
		break;
	case Terminal::messageType::SuccessPrefix:
		std::cout << "\n\033[1;92m✓ \033[0;102m\033[102;30m [Success] \033[0m\033[1;97m ";
		break;
	case Terminal::messageType::WarningPrefix:
		std::cout << "\n\u26A0\uFE0E \033[0;43m\033[43;30m [Warning] \033[0m\033[1;97m ";
		break;
	case Terminal::messageType::ErrorPrefix:
		std::cout << "\n\033[1;31mx \033[0;101m\033[101;30m [Error] \033[0m\033[1;97m ";
		break;
	case Terminal::messageType::FatalPrefix:
		std::cout << "\n\033[1;31mx \033[0;101m\033[101;30m [Fatal] \033[0m\033[1;97m ";
		break;
	}
}

void Terminal::setColor(messageStyle style) {
	if (style.Color == Terminal::messageColor::Black) {
		std::cout << "\033[30m";
	} else if (style.Color == Terminal::messageColor::Red) {
		std::cout << "\033[31m";
	} else if (style.Color == Terminal::messageColor::Green) {
		std::cout << "\033[32m";
	} else if (style.Color == Terminal::messageColor::Yellow) {
		std::cout << "\033[33m";
	} else if (style.Color == Terminal::messageColor::Blue) {
		std::cout << "\033[34m";
	} else if (style.Color == Terminal::messageColor::Magenta) {
		std::cout << "\033[35m";
	} else if (style.Color == Terminal::messageColor::Cyan) {
		std::cout << "\033[36m";
	} else if (style.Color == Terminal::messageColor::White) {
		std::cout << "\033[37m";
	}
}

void Terminal::resetColor() {
	std::cout << "\033[1;97m";
}

void Terminal::printText(std::string text, messageStyle style) { // comes up with a prefix
	printPrefix(style);
	setColor(style);
	std::cout << text;
	resetColor();
}

std::string Terminal::cinCommand() {
	std::string command;
	printText("\n> ", Default);
	std::getline(std::cin, command);
	return command;
}