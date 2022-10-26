#pragma once
#include "ILogPrinter.h"
#include <iostream>
#include <fstream>

class TermFilePrinter : public ILogPrinter
{
public:
	TermFilePrinter(const std::string& filename = "log.txt");
	void print_log(const Message& msg) override;
	~TermFilePrinter();
private:
	std::ofstream fout;
};

