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

void Terminal::printPrefix(messageStyle style) {
	if (style.Type == Terminal::messageType::DebugPrefix) {
		std::cout << "\033[1;97m[Debug]\033[0m ";
	} else if (style.Type == Terminal::messageType::InfoPrefix) {
		std::cout << "\033[1;96m[Info]\033[0m ";
	} else if (style.Type == Terminal::messageType::SuccessPrefix) {
		std::cout << "\033[1;92m[Success]\033[0m ";
	} else if (style.Type == Terminal::messageType::WarningPrefix) {
		std::cout << "\033[1;93m[Warning]\033[0m ";
	} else if (style.Type == Terminal::messageType::ErrorPrefix) {
		std::cout << "\033[0;91m[Error]\033[0m ";
	} else if (style.Type == Terminal::messageType::FatalPrefix) {
		std::cout << "\033[1;91m[Fatal]\033[0m ";
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
	std::cout << "\033[0m";
}

void Terminal::printText(std::string text, messageStyle style) { // comes up with a prefix
	printPrefix(style);
	setColor(style);
	std::cout << text;
	resetColor();
}