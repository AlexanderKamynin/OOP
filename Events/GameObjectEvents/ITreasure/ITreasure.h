#pragma once
#include "../GameObjectEvent.h"


class ITreasure : public GameObjectEvent
{
public:
	ITreasure(Player* player) : GameObjectEvent(player) {};
	virtual void set_gold_in_treasure(int gold) = 0;

protected:
	int gold = 0;
};

