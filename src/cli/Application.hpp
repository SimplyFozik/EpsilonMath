#pragma once
#include "Terminal.hpp" // iostream and string libraries are included in Terminal.hpp
#include "CommandParser.hpp" // Command execution and parsing

class Application {
private:

	std::string version = "1.06-dev";

public:
	
	Terminal terminal;
	CommandParser parser;
	// Network network;
	// Timer timer;

	Application() : terminal(), parser(&terminal) {
		terminal.printText("All Services initialized successfully!\n", terminal.Success);
		terminal.printText("EpsilonMath version - " + version + "\n", terminal.Info);
		run();
	}

	void run() {
		while (true) {
			std::string command = terminal.cinCommand();
			parser.processCommand(command);
		}
	}
};