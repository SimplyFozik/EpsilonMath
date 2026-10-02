#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>`
#include "Terminal.hpp"
#include "cpuid.hpp"

class Terminal;

class CommandParser {
private:
	
	Terminal* terminal;
	CPUInfo cinfo;

	short sysinfo_list_size = 64;


	std::vector<std::string> sysinfo_list = {
		"CPU \033[0;97m        " + cinfo.model().erase(cinfo.model().find('\0')),
		"Cores \033[0;97m      " + std::to_string(cinfo.logicalCpus()),
		std::string("SSE \033[0;97m        ") + ((cinfo.isSSE() == 1) ? "\033[0;92m✓" : "\033[0;91mX"),
		std::string("SSE2 \033[0;97m       ") + ((cinfo.isSSE2() == 1) ? "\033[0;92m✓" : "\033[0;91mX"),
		std::string("SSE3 \033[0;97m       ") + ((cinfo.isSSE3() == 1) ? "\033[0;92m✓" : "\033[0;91mX"),
		std::string("SSE41 \033[0;97m      ") + ((cinfo.isSSE41() == 1) ? "\033[0;92m✓" : "\033[0;91mX"),
		std::string("SSE42 \033[0;97m      ") + ((cinfo.isSSE42() == 1) ? "\033[0;92m✓" : "\033[0;91mX"),
		std::string("AVX \033[0;97m        ") + ((cinfo.isAVX() == 1) ? "\033[0;92m✓" : "\033[0;91mX"),
		std::string("AVX2 \033[0;97m       ") + ((cinfo.isAVX2() == 1) ? "\033[0;92m✓" : "\033[0;91mX")
	};

	inline const static std::vector<std::string> commands_list = {
		"\n\033[0;90m ╭─ \033[1;97mHelp\033[0;90m ────────────────────────────────────╮ \n",
		"\033[0;90m │                                           │\n",
		"\033[0;90m │  \033[0;97mGeneral\033[0;90m                                  │\n",
		"\033[0;90m │    \033[1;94mhelp      \033[0;97mShow commands list\033[0;90m           │\n",
		"\033[0;90m │    \033[1;94mclear     \033[0;97mClear the screen\033[0;90m             │\n",
		"\033[0;90m │    \033[1;94mexit      \033[0;97mClose the program\033[0;90m            │\n",
		"\033[0;90m │                                           │\n",
		"\033[0;90m │  \033[0;97mSystem\033[0;90m                                   │\n",
		"\033[0;90m │    \033[1;94msysinfo   \033[0;97mShow info about your system\033[0;90m  │\n",
		"\033[0;90m │                                           │\n",
		"\033[0;90m ╰───────────────────────────────────────────╯ \n"
	 };

public:

	std::vector<std::string> parseWords(const std::string& text);
	void lowercase(std::string& text);
	void processCommand(std::string& command);

	static std::vector<std::string> getCommandsList() {
		return commands_list;
	}

	void sysinfo_list_print() {
		std::cout << "\n\033[0;90m ╭─ \033[1;97mSystem Info\033[0;90m ───────────────────────────────────────────────────╮ \n";
		std::cout << "\033[0;90m │"; for (int i = 0; i <= sysinfo_list_size; i++) { std::cout << ' '; } std::cout << "│\n";
		std::cout << "\033[0;90m │  \033[0;97mCPU\033[0;90m"; for (int i = 0; i <= sysinfo_list_size - 5; i++) { std::cout << ' '; } std::cout << "│\n";
		for (int i = 0; i < 2; i++) {
			std::cout << "\033[0;90m │    \033[0;94m" << sysinfo_list[i];
			for (int j = 1; j < sysinfo_list_size - sysinfo_list[i].size() + 4; j++) {
				std::cout << ' ';
			}
			std::cout << "\033[0;90m │" << std::endl;
		}
		
		std::cout << "\033[0;90m │"; for (int i = 0; i <= sysinfo_list_size; i++) { std::cout << ' '; } std::cout << "│\n";
		std::cout << "\033[0;90m │  \033[0;97mInstructions\033[0;90m"; for (int i = 0; i <= sysinfo_list_size - 14; i++) { std::cout << ' '; } std::cout << "│\n";
		for (int i = 2; i < sysinfo_list.size(); i++) {
			std::cout << "\033[0;90m │    \033[0;94m" << sysinfo_list[i];
			for (int j = 1; j < sysinfo_list_size - sysinfo_list[i].size() + 13; j++) {
				std::cout << ' ';
			}
			std::cout << "\033[0;90m │" << std::endl;
		}
		
		std::cout << "\033[0;90m │"; for (int i = 0; i <= sysinfo_list_size; i++) { std::cout << ' '; } std::cout << "│\n";
		std::cout << "\033[0;90m ╰─────────────────────────────────────────────────────────────────╯ \n";

	}

	explicit CommandParser(Terminal* terminal) : terminal(terminal), cinfo() {
		#ifdef NDEBUG
		#else
			terminal->printText("Command Parser Service initialized successfuly\n", terminal->Debug);
		#endif	

		
	}
};