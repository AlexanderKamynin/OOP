#include "FilePrinter.h"

FilePrinter::FilePrinter(const std::string& filename) {
	fout.open(filename, std::ios_base::out | std::ios_base::app);
}

void FilePrinter::print_log(const Message& msg)
{
	if (fout.is_open()) {
		fout << msg;
	}
}

FilePrinter::~FilePrinter() {
	fout.close();
}