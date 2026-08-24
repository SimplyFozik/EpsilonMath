#pragma once
#include "Terminal.hpp" // iostream and string libraries are included in Terminal.hpp

class Application {
private:

public:
	
	Application() {
		Terminal terminal;
		terminal.printText("Services initialized successfully\n", terminal.Success);
	}
};