#pragma once
#include "../MapEvent.h"


class ITreasure : public MapEvent
{
public:
	ITreasure(Player* player) : MapEvent(player) {};
	virtual void set_gold_in_treasure(int gold) = 0;
protected:
	int gold = 0;
};

