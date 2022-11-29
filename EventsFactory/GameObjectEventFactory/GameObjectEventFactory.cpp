#include "GameObjectEventFactory.h"


IEvent* GameObjectEventFactory::createGameObject(GameObjectToCreate object_to_create)
{
	IEvent* new_object = nullptr;
	switch (object_to_create) {
		case GameObjectToCreate::AltarObject: {
			new_object = this->createAltar();
			break;
		}
		case GameObjectToCreate::LockedTreasureObject: {
			new_object = this->createLockedTreasure();
			break;
		}
		case GameObjectToCreate::UnlockedTreasureObject: {
			new_object = this->createUnlockedTreasure();
			break;
		}
		default:
			break;
	}
	return new_object;
}

IEvent* GameObjectEventFactory::createAltar()
{
	return new Altar(this->field->get_player());
}

IEvent* GameObjectEventFactory::createLockedTreasure()
{
	LockedTreasure* treasure = new LockedTreasure(this->field->get_player());
	//
	std::random_device random_device;
	std::default_random_engine generator(random_device());
	//
	std::uniform_int_distribution<int> random_gold(0, 100);
	treasure->set_gold_in_treasure(random_gold(generator));
	return treasure;
}

IEvent* GameObjectEventFactory::createUnlockedTreasure()
{
	UnlockedTreasure* treasure = new UnlockedTreasure(this->field->get_player());
	//
	std::random_device random_device;
	std::default_random_engine generator(random_device());
	//
	std::uniform_int_distribution<int> random_gold(0, 50);
	treasure->set_gold_in_treasure(random_gold(generator));
	return treasure;
}