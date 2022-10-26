#pragma once
#include "ILogPrinter.h"
#include <iostream>


class TerminalPrinter : public ILogPrinter
{
public:
	TerminalPrinter() = default;
	void print_log(const Message& msg) override;
	~TerminalPrinter() = default;
};

