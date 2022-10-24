#pragma once
#include "../GameObjectEvent.h"
#include <iostream>
#include <string>


class Altar : public GameObjectEvent
{
public:
	Altar(Player* player) : GameObjectEvent(player) {};

	void React() override;

	bool is_one_time() override;

	~Altar() = default;
private:
	int cost_one_hp = 2;
};

