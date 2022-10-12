#pragma once
#include "../GameProcessEvents.h"


class DefeatEvent : public GameProcessEvents
{
public:
	DefeatEvent(Player* player) : GameProcessEvents(player) {};

	void React() override;

	bool is_activate() override;
};

