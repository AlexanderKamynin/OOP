#include "Message.h"

Message::Message(std::string prefix, std::string msg)
{
	this->prefix = prefix + ":";
	this->msg = msg;
}

std::string Message::get_message()
{
	return this->msg;
}

std::string Message::get_prefix()
{
	return this->prefix;
}

std::ostream& operator<<(std::ostream& out, const Message& obj)
{
	out << obj.prefix << " ";
	out << obj.msg;
	return out;
}
