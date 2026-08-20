#pragma once
#include <iostream>
#include <future>
#include <vector>
#include <string>

enum animationType {
	Typing = 0,
	FadeIn,
	Silent
};

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
	bool silent = false;
	std::string version = "v1.03-dev";
public:
	bool isSilent() {
		return silent;
	}

	void switchSilent() {
		silent = !silent;
	}

	Manager() { // Main loop on boot
		
		sendMessage("EpsilonMath ", Info, Default, Typing, false, false);
		sendMessage(version, Null, Default, Typing, true, false);

		std::cout << std::endl;
		std::string command;
		for (;;) {
			std::cout << "Type command: "; 	
			std::getline(std::cin, command);
			CommandParser(command, silent);
		}
	}

	// MathOps.cpp
	long double Leibniz(long long first_iteration, long long last_iteration);
	long double LeibnizAsyncManager(long long iterations, int threads);

	// CLI.cpp
	void sendMessage(std::string text, msgType type, msgColor color, animationType animtype, bool end_line, bool silent);
	void CommandParser(std::string command, bool isSilent);
	void animateText(std::string text, animationType type);
};