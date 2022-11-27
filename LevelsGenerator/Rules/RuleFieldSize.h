#pragma once
#include "../../Background/Field.h"


template <int height = 10, int width = 10>
class RuleFieldSize
{
public:
	void operator()(Field* field) {
		delete field;
		field = new Field(height, width);
	}
};

