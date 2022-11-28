#pragma once
#include "../Events/IEvent.h"
#include "../Background/Field.h"
#include <random>
#include <ctime>
#include <algorithm>


class IEventFactory {
public:
	IEventFactory(Field* field) : field(field) {};
protected:
	Field* field;
};