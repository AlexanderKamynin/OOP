#pragma once
#include "../../Background/Field.h"
#include "../../EventsFactory/GameProcessEventFactory/GameProcessEventFactory.h"


template <int x, int y>
class RuleExitSpawn
{
public:
	void operator()(Field* field) {
		GameProcessEventFactory event_factory(field);
		int cur_x = x % field->get_width();
		int cur_y = y % field->get_height();
		bool flag = false;
		while (flag != true) {
			if (field->get_player_position().first != cur_x && field->get_player_position().second != cur_y) {
					field->get_field()[y][x]->set_passability(true);
					field->get_field()[y][x]->set_event(event_factory.createExitEvent());
					flag = true;
			}
			else {
				cur_x = (cur_x + 1) % field->get_width();
				cur_y = (cur_y + 1) % field->get_height();
			}
		}
	}
};

