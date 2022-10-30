#include "Message.h"

Message::Message(EnumClass::LogLevels log_level, std::string msg)
{
	this->prefix = log_level;
	this->msg = msg;
}

EnumClass::LogLevels Message::get_log_level()
{
	return this->prefix;
}

std::ostream& operator<<(std::ostream& out, const Message& obj)
{
	EnumClass logs;
	auto It = logs.log_levels.find(obj.prefix);
	out << It->second;
	out	<< ":" << obj.msg << '\n';
	return out;
}