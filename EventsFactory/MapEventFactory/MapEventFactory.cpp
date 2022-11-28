#include "MapEventFactory.h"

IEvent* MapEventFactory::createMapEvent(MapEventToCreate event_to_create)
{
	IEvent* new_event = nullptr;
	switch (event_to_create) {
		case MapEventToCreate::TrapEvent: {
			new_event = this->createTrap();
			break;
		}
		case MapEventToCreate::CeilingCollapseEvent: {
			new_event = this->createCeilingCollapse();
			break;
		}
		default:
			break;
	}
	return new_event;
}

IEvent* MapEventFactory::createTrap()
{
	return new Trap(this->field->get_player());
}

IEvent* MapEventFactory::createCeilingCollapse()
{
	std::vector<Cell*> cells_to_change;
	//
	std::random_device random_device;
	std::default_random_engine generator(random_device());
	//
	std::uniform_int_distribution<int> random_seg_height(0, field->get_height() - 1);
	std::uniform_int_distribution<int> random_seg_width(0, field->get_width() - 1);
	for (int i = 0; i < 5; i++) {
		int x = random_seg_width(generator);
		int y = random_seg_height(generator);
		if (field->get_field()[y][x]->get_event() == nullptr
			&& field->get_player_position().first != x
			&& field->get_player_position().second != y) {
			cells_to_change.push_back(field->get_field()[y][x]);
		}
	}
	return new CeilingCollapse(cells_to_change);
}