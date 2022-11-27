#pragma once
#include "../../Background/Field.h"


template<int x = 0, int y = 0>
class RulePlayerSpawn
{
public:
	void operator()(Field* field) {
		if (field->get_field()[y][x]->get_passability() && !(field->get_field()[y][x]->get_event())) {
			field->set_player_position(x, y);
		}
		else {
			field->set_player_position(0, 0);
		}
	}
};

