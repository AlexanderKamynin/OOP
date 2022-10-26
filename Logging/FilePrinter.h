#pragma once
#include "ILogPrinter.h"
#include <fstream>

class FilePrinter : public ILogPrinter
{
public:
	FilePrinter(const std::string& filename = "log.txt");
	void print_log(const Message& msg) override;
	~FilePrinter();
private:
	std::ofstream fout;
};

