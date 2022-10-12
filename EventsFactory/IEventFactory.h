#pragma once
#include "../Events/IEvent.h"
#include "../Player/Player.h"


class IEventFactory {
public:
	IEventFactory(Player* player) : player(player) {};
protected:
	Player* player;
};