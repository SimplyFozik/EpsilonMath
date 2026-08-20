#pragma once
#include <iostream>
#include <future>
#include <vector>

enum msgType {
	Info = 0,
	Warning,
	Error,
	Null
};

enum msgColor {
	Black = 0,
	Red,
	Green,
	Yellow,
	Blue,
	Magneta,
	Cyan,
	White,
	Default
};

class Manager {
private:
	bool isSilent = false;
public:

	Manager() { // Main loop on boot
		sendMessage("EpsilonMath ", Info, Default, true, true);
		std::cout << std::endl;
		std::string command;
		for (;;) {
			std::cout << "Type command: "; 	
			std::cin >> command;
			CommandParser(command);
		}
	}


	// MathOps.cpp
	long double Leibniz(long long first_iteration, long long last_iteration);
	long double LeibnizAsyncManager(long long iterations, int threads);
	
	// CLI.cpp
	void sendMessage(std::string text, msgType type, msgColor color, bool end_line, bool silent);
	void CommandParser(std::string command);
	void animateText(std::string text);

};