#pragma once
#include "../../../Background/Field.h"
#include "../../../EventsFactory/MapEventFactory/MapEventFactory.h"


template<class Factory, int magic_number, int count>
class RuleTrapSpawn
{
public:
	void operator()(Field* field) {
		int current_count = 0;
		Factory event_factory(field->get_player());
		for (int y = 0; y < field->get_height(); y++) {
			for (int x = 0; x < field->get_width(); x++) {
				if (current_count == count) {
					return;
				}
				if ((y * magic_number) % field->get_height() == x + 2
					&& field->get_field()[y][x]->get_event() == nullptr
					&& (x != 0 || y != 0)) {
					field->get_field()[y][x]->set_passability(true);
					field->get_field()[y][x]->set_event(event_factory->createTrap());
				}
			}
		}
	}
};

