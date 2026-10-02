#pragma once
#include "Terminal.hpp" // iostream and string libraries are included in Terminal.hpp
#include "CommandParser.hpp" // Command execution and parsing

class Application {
private:

	std::string version = "1.09-dev";
	

public:
	
	Terminal terminal;
	CommandParser parser;
	// Network network;
	// Timer timer;

	Application() : terminal(), parser(&terminal) {
		#ifdef NDEBUG
		#else
			terminal.printText("All Services initialized successfully!\n", terminal.Success);
		#endif
		terminal.printText("EpsilonMath version - " + version + "\n", terminal.Info);
		run();
	}

	void run() { // infinite loop
		while (true) {
			std::string command = terminal.cinCommand();
			parser.processCommand(command);
		}
	}
};