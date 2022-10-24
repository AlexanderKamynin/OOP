#pragma once
#include "../MapEvent.h"


class Trap : public MapEvent
{
public:
	Trap(Player* player) : MapEvent(player) {};

	void React() override;

	bool is_one_time() override;

	~Trap() = default;
};