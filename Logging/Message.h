#pragma once
#include <iostream>
#include <string>

class Message
{
public:
	Message(std::string prefix, std::string msg);

	std::string get_message();

	std::string get_prefix();

	friend std::ostream& operator << (std::ostream& out, const Message& obj);
private:
	std::string msg;
	std::string prefix;
};

