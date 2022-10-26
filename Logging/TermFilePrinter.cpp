#include "TermFilePrinter.h"

TermFilePrinter::TermFilePrinter(const std::string& filename) {
	fout.open(filename, std::ios_base::out | std::ios_base::app);
}

void TermFilePrinter::print_log(const Message& msg)
{
	if (fout.is_open()) {
		fout << msg;
	}
	std::cout << msg;
}

TermFilePrinter::~TermFilePrinter() {
	fout.close();
}