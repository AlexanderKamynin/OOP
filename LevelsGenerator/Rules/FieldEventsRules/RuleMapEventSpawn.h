#pragma once
#include "../../../Background/Field.h"
#include "../../../EventsFactory/MapEventFactory/MapEventFactory.h"


template<MapEventFactory::MapEventToCreate event, int magic_number, int count>
class RuleMapEventSpawn
{
public:
	void operator()(Field* field) {
		int current_count = 0;
		MapEventFactory event_factory(field);
		for (int y = 0; y < field->get_height(); y++) {
			for (int x = 0; x < field->get_width(); x++) {
				if (current_count == count) {
					return;
				}
				if ((y * magic_number) % field->get_height() == x + 2
					&& field->get_field()[y][x]->get_event() == nullptr
					&& (field->get_player_position().first != x)
					&& (field->get_player_position().second != y)) {
					current_count += 1;
					field->get_field()[y][x]->set_passability(true);
					field->get_field()[y][x]->set_event(event_factory.createMapEvent(event));
				}
			}
		}
	}
};

