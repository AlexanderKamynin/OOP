#pragma once
#include "../IEvent.h"
#include "../../Player/Player.h"
#include "../../Background/Field.h"

class GameProcessEvents : public IEvent
{
public:
	GameProcessEvents(Player* player);

	virtual bool is_activate() = 0;

protected:
	Player* player;
	bool activate = false;
};

