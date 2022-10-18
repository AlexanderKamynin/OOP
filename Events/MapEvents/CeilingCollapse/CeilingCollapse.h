#pragma once
#include "../MapEvent.h"
#include <iostream>

class CeilingCollapse : public MapEvent
{
public:
	CeilingCollapse(std::vector<Cell*> cells_to_change) : MapEvent(cells_to_change) {};

	void React() override;

	~CeilingCollapse() = default;
};

