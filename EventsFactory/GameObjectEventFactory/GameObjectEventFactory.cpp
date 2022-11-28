#include "GameObjectEventFactory.h"


IEvent* GameObjectEventFactory::createAltar()
{
	Altar* altar = new Altar(this->field->get_player());
	return altar;
}

IEvent* GameObjectEventFactory::createLockedTreasure(int gold) {
	LockedTreasure* treasure = new LockedTreasure(this->field->get_player());
	treasure->set_gold_in_treasure(gold);
	return treasure;
}

IEvent* GameObjectEventFactory::createUnlockedTreasure(int gold) {
	UnlockedTreasure* treasure = new UnlockedTreasure(this->field->get_player());
	treasure->set_gold_in_treasure(gold);
	return treasure;
}
