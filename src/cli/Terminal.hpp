#pragma once
#include <iostream>
#include <string>

class Terminal {
private:
	
	enum messageType {
		DebugPrefix = 0,
		InfoPrefix,
		SuccessPrefix,
		WarningPrefix,
		ErrorPrefix,
		FatalPrefix,
		NullPrefix
	};

	enum messageColor {
		Black = 0,
		Red,
		Green,
		Yellow,
		Blue,
		Magenta,
		Cyan,
		White,
	};

	struct messageStyle {
		messageType Type;
		messageColor Color;
	};

public:

	messageStyle Debug = messageStyle{ messageType::DebugPrefix, messageColor::White };
	messageStyle Info = messageStyle{ messageType::InfoPrefix, messageColor::White };
	messageStyle Success = messageStyle{ messageType::SuccessPrefix, messageColor::White };
	messageStyle Warning = messageStyle{ messageType::WarningPrefix, messageColor::White };
	messageStyle Error = messageStyle{ messageType::ErrorPrefix, messageColor::White };
	messageStyle Fatal = messageStyle{ messageType::FatalPrefix, messageColor::White };

	void printPrefix(messageStyle style);
	void setColor(messageStyle style);
	void resetColor();
	void printText(std::string text, messageStyle style);

	Terminal() {
		printText("Terminal initialized successfully\n", Success);
	}
};